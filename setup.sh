#!/bin/bash
set -xue

# Scritpt to install:
# - bash: The command-line shell. Usually it's pre-installed.
# - tar: Usually it's pre-installed. Prefer GNU version, not BSD.
# - clang: C compiler. Make sure it supports 32-bit RISC-V CPU (see below).
# - lld: LLVM linker, which bundles complied object files into an executable.
# - llvm-objcopy: Object file editor. It comes with the LLVM package (typically llvm package).
# - llvm-objdump: A disassembler. Same as llvm-objcopy.
# - llvm-readelf: An ELF file reader. Same as llvm-objcopy.
# - qemu-system-riscv32: 32-bit RISC-V CPU emulator. It's part of the QEMU package (typically qemu package).

sudo apt update && sudo apt install -y clang llvm lld qemu-system-riscv32 curl
curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin
clang -print-targets | grep riscv32