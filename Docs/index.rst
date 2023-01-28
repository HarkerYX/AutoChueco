.. test documentation master file,
    it should at least contain the root `toctree` directive.

Software Detail Design
======================


Welcome to AUTOSAR MCAL Documentation, the project is designed to to run on board Nucleo-G0B1 or any 
board that make use of the **stm32g0b1re** microcontroller. This is a very simple implementation with no 
other purpose than learn and train about AUTOSAR concepts

Building
--------

To build the project just type `make clean && make` and then to flash the board `make flash`, if generate
documentation is required just type make docs

Tooling
-------

For any person interested in participate in the current development effor it is necesary to install
the following tools. **NOTE:** we currently support Arch Linux only.

.. code-block::

    $ sudo pacman -S llvm arm-none-eabi-gdb lld clang make

.

.. toctree::
    :maxdepth: 1
    :caption: Contents:

    Bfx_bit8
    Bfx_bit32
    Port
