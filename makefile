#---Set project name
TARGET = mcal

#---Files to compile
SRCS = main.c startup.c

#---Linker script
LINKER = linker.ld

#directorios con archivos a compilar (.c y .s)
SRC_PATHS  = .
#direcotrios con archivos .h
INC_PATHS  = .

#---Set toolchain
TOOLCHAIN = clang

#---Compilation options
CPU = -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -target armv6m-*-none-eabi
CFLAGS  = $(CPU)
CFLAGS += -Os                        # Compile with Size Optimizations (O0, O1, O2, O3, Os)
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
LFLAGS  = $(CPU) 
LFLAGS +=  -T$(LINKER)
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
OBJS = $(SRCS:%.c=Build/obj/%.o)
DEPS = $(OBJS:%.o=%.d)
FILES  = $(shell find ./ -type f -name "*.[ch]")
VPATH = $(SRC_PATHS)
INCLS = $(addprefix -I ,$(INC_PATHS))

all : format lint build $(TARGET)

$(TARGET) : $(addprefix Build/, $(TARGET).elf)
	llvm-objdump -S -h $< > Build/$(TARGET).lst
	llvm-size --format=berkeley $<

Build/$(TARGET).elf : $(OBJS)
	$(TOOLCHAIN) $(LFLAGS) -o $@ $^

Build/obj/%.o : %.c
	$(TOOLCHAIN) $(CFLAGS) $(INCLS) -c $< -o $@

.PHONY : build clean lint docs format
#---remove binary files
clean :
	rm -r Build
#---Create output directory
build :
	mkdir -p Build/obj

format :
	clang-format -style=file -i --Werror $(FILES)

lint :
	mkdir -p Build/checks
	cppcheck --addon=misra.json --suppressions-list=.msupress $(LNFLAGS) .

docs :
	mkdir -p Build/doxygen 
	mkdir -p Build/sphinx 
	mkdir -p Build/sphinx/_template 
	mkdir -p Build/sphinx/_static 
	mkdir -p Build/sphinx/_build
	doxygen .doxyfile
	sphinx-build -b html Docs Build/sphinx/_build -c ./ -W
	firefox Build/sphinx/_build/index.html
