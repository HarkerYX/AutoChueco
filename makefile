#---Set project name
TARGET = mcal

#---Files to compile
SRCS = main.c startup.c
#---Actual fremawork sources
SRCF = Bfx_bit8.c
#---Unit testing files
SRCT = unity.c

#---Linker script
LINKER = linker.ld

#directorios con archivos a compilar (.c y .s)
SRC_PATHS  = .
SRC_PATHS += Libraries
SRC_PATHS += Utest
SRC_PATHS += Utest/unity
#direcotrios con archivos .h
INC_PATHS  = .
INC_PATHS += Libraries
INC_PATHS += Utest
INC_PATHS += Utest/unity

#---Set toolchain
TOOLCHAIN = clang

#---Compilation options
CPU = -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -target armv6m-*-none-eabi
CFLAGS  = -Os                        # Compile with Size Optimizations (O0, O1, O2, O3, Os)
CFLAGS += -g3                        # Debugging information level (g1, g2, g3)
CFLAGS += -ffunction-sections        # Create a separate function section
CFLAGS += -fdata-sections            # Create a separate data section
CFLAGS += -fno-builtin               # Don't recognize built-in functions that do not begin with ‘__builtin_’ as prefix
CFLAGS += -std=c99                   # Comply with C11
CFLAGS += -Wall                      # Be anal Enable All Warnings
CFLAGS += -pedantic                  # Be extra anal More ANSI Checks
CFLAGS += -Werror                    # Threat all warnings as errors
CFLAGS += -Wstrict-prototypes        # Warn if a function is declared or defined without specifying the argument types
CFLAGS += -fsigned-char              # char is treated as signed
CFLAGS += -fdiagnostics-color=always # color the output
CFLAGS += -fomit-frame-pointer       # Don't keep the frame pointer in a register for functions that don't need one
CFLAGS += -fverbose-asm              # Put extra commentary information in the generated assembly code
CFLAGS += -MMD -MP

#---Linker options
LFLAGS  =  -T$(LINKER)
LFLAGS += -nostdlib
LFLAGS += -Wl,--gc-sections
LFLAGS += -Wl,-Map=Build/$(TARGET).map	# Generate map file

#Linter ccpcheck flags
LNFLAGS  = --inline-suppr       # comments to suppress lint warnings
LNFLAGS += --quiet              # spit only useful information
LNFLAGS += --std=c99            # check against C11
LNFLAGS += --template=gcc       # display warning gcc style
LNFLAGS += --force              # evaluate all the #if sentences
LNFLAGS += --platform=unix32    # lint againt a unix32 platform, but we are using arm32
LNFLAGS += --cppcheck-build-dir=Build/checks

#---Build target
SRC = $(SRCS) $(SRCF)
OBJSA = $(SRC:%.c=Build/obj/%.o)
DEPS = $(OBJS:%.o=%.d)
RSLST = $(SRCT:Test_%.c=Build/unity/results/Test_%.txt)
FILES  = $(shell find ./ -type f ! -path '*/Utest/unity*' -name "*.[ch]")
VPATH = $(SRC_PATHS)
INCLS = $(addprefix -I ,$(INC_PATHS))

all : format lint build $(TARGET)

$(TARGET) : $(addprefix Build/, $(TARGET).elf)
	llvm-objdump -S -h $< > Build/$(TARGET).lst
	llvm-size --format=berkeley $<

Build/$(TARGET).elf : $(OBJSA)
	$(TOOLCHAIN) $(CPU) $(LFLAGS) -o $@ $^

Build/obj/%.o : %.c
	$(TOOLCHAIN) $(CPU) $(CFLAGS) $(INCLS) -c $< -o $@

.PHONY : build clean lint docs format utest
#---remove binary files
clean :
	rm -r Build
#---Create output directory
build :
	@mkdir -p Build/obj
	@mkdir -p Build/unity
	@mkdir -p Build/unity/results
	@mkdir -p Build/unity/obj

format :
	clang-format -style=file -i --Werror $(FILES)

lint :
	mkdir -p Build/checks
	cppcheck --addon=misra.json --suppressions-list=.msupress $(LNFLAGS) .

#unit testing setup, this is a temporary solution since we planned to use the full ceedling framework
utest : build format $(RSLST)
	@echo -e "\nPASS:"
	@-grep -s --no-filename :PASS Build/unity/results/*.txt
	@echo -e "\nFAILURES:"
	@-grep -r --no-filename :FAIL Build/unity/results/*.txt
	@echo -e "\nIGNORE:"
	@-grep -s --no-filename :IGNORE Build/unity/results/*.txt

Build/unity/results/Test_%.txt : Build/unity/Test_%.out
	-./$< > $@ 2>&1

Build/unity/Test_%.out: Build/unity/obj/%.o Build/unity/obj/Test_%.o Build/unity/obj/unity.o
	@clang -o $@ $^

Build/unity/obj/%.o: %.c
	@clang $(CFLAGS) $(INCLS) -DTEST -c $< -o $@

.PRECIOUS: Build/unity/Test_%.out
.PRECIOUS: Build/unity/obj/%.o
.PRECIOUS: Build/unity/results/%.txt
#-------------------------------------------------------

docs :
	mkdir -p Build/doxygen 
	mkdir -p Build/sphinx 
	mkdir -p Build/sphinx/_template 
	mkdir -p Build/sphinx/_static 
	mkdir -p Build/sphinx/_build
	doxygen .doxyfile
	sphinx-build -b html Docs Build/sphinx/_build -c ./ -W
	firefox Build/sphinx/_build/index.html
