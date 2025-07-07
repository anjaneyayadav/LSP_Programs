# JTAG and ELF in Linux

## What is JTAG?

*JTAG (Joint Test Action Group)* is a hardware debugging and testing standard. It was released in 1990 as *IEEE 1149.1* and developed by a group of electronics companies working together.

### JTAG is used to:
- Test and program electronic chips (like processors, microcontrollers).
- Debug embedded systems directly at the hardware level.

### Why JTAG is Used?

#### ‚úÖ 1. Internal Chip Access
- JTAG allows direct access to internal components of a chip like registers and logic blocks.

#### ‚úÖ 2. Fault Detection
- Helps identify broken connections, soldering issues, or short circuits on a PCB without external probing.

#### ‚úÖ 3. No Need for Full System Boot
- Debug or test even when the system is not fully powered on or not running its main software.

### Key Features of JTAG

#### ‚úÖ Boundary Scan Testing
- Tests connections on a PCB without powering up the full system.
- Detects shorts, open circuits, and soldering faults.

#### ‚úÖ In-System Programming
- Programs microcontrollers or flash memory directly on the board without removing the chip.

#### ‚úÖ Hardware-Level Debugging
- Set breakpoints, step through code, and read/write CPU registers at the hardware level.

#### ‚úÖ Direct Communication with Chips
- Communicates directly with a device without USB, UART, or serial ports.

#### ‚úÖ Low Pin Count Interface
- Uses only 4 or 5 pins: *TCK, TMS, TDI, TDO, and optional **TRST*.

#### ‚úÖ Supports Multiple Devices
- Connect multiple chips in a chain and access all of them through a single JTAG port.

#### ‚úÖ Wide Tool Support
- Compatible with many JTAG programmers and debuggers (e.g., ARM, AVR, STM32, etc.).

---

## What is ELF in Linux?

*ELF (Executable and Linkable Format)* is a file format used in Linux and Unix-based systems for:

1. Executable files (.out, binaries)
2. Object files (.o)
3. Shared libraries (.so)
4. Core dump files (used for debugging crashes)

### ELF File Format Diagram


+-------------------------+
| ELF Header             |  ‚Üê Info about the file
+-------------------------+
| Program Header Table   |  ‚Üê Used at runtime (loader uses this)
+-------------------------+
| Section Header Table   |  ‚Üê Used at compile/link time
+-------------------------+
| Sections / Segments    |
|   - .text              |  ‚Üê Code (instructions)
|   - .data              |  ‚Üê Initialized data (variables)
|   - .bss               |  ‚Üê Uninitialized data (zero-filled)
|   - .rodata            |  ‚Üê Read-only data (e.g., const)
|   - .symtab/.strtab    |  ‚Üê Symbol & string tables
|   - .rel/.rela         |  ‚Üê Relocation info
+-------------------------+


### üß† Easy Way to Remember

1. *Header* ‚Üí Identity  
2. *Program Header* ‚Üí Runtime Info  
3. *Section Header* ‚Üí Linking Info  
4. *.text* ‚Üí Code  
5. *.data* ‚Üí Values with init  
6. *.bss* ‚Üí Values without init  
7. *.rodata* ‚Üí Read-only constants  
8. *.symtab* ‚Üí Names  
9. *.rel/.rela* ‚Üí Fixups  

### Real-Time Applications

#### 1. Running Linux Programs
- Every program in Linux (like ls, cat, or custom apps) is stored in ELF format.
- ELF files contain the compiled code and metadata for execution.

#### 2. System Libraries (.so Files)
- Most shared libraries (like libc.so, libm.so) are ELF files.
- Essential for system and application functioning.

#### 3. Linux Kernel and Drivers
- The Linux kernel and loadable modules (.ko files) are ELF format.
- Used when booting the OS and loading drivers.

#### 4. Debugging and Crash Analysis
- Tools like gdb, readelf, and core dumps rely on ELF structure.
- Helps developers find bugs and fix crashes.
