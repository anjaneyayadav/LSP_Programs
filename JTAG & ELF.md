# 📌 What is JTAG?

**JTAG (Joint Test Action Group)** is a hardware debugging and testing standard.  
It was released in **1990** and developed by a group of electronics companies working together.

### ✅ Uses of JTAG:

- **Test and program** electronic chips (like processors, microcontrollers).
- **Debug embedded systems** directly at the hardware level.

---

## 🔧 Why JTAG is Used?

1. **Internal Chip Access**  
   → Direct access to chip internals (registers, logic blocks).

2. **Fault Detection**  
   → Detects broken connections, soldering faults, short circuits.

3. **No Need for Full System Boot**  
   → Works even when the system is not fully powered on or booted.

---

## ⭐ Key Features of JTAG

- **✅ Boundary Scan Testing**  
  → Tests PCB connections without system boot.

- **✅ In-System Programming**  
  → Programs microcontrollers/flash on-board.

- **✅ Hardware-Level Debugging**  
  → Set breakpoints, step through code, access registers.

- **✅ Direct Chip Communication**  
  → No USB/UART/Serial needed.

- **✅ Low Pin Count Interface**  
  → Uses 4 or 5 pins: TCK, TMS, TDI, TDO, (optional TRST).

- **✅ Multiple Device Support**  
  → Connect & access multiple devices in a JTAG chain.

- **✅ Wide Tool Support**  
  → Works with ARM, AVR, STM32, and various debuggers/programmers.

---

# 📁 What is ELF in Linux?

**ELF (Executable and Linkable Format)** is a standard file format used in Linux/Unix systems for:

1. **Executable files** (`.out`, binary)  
2. **Object files** (`.o`)  
3. **Shared libraries** (`.so`)  
4. **Core dump files** (for crash debugging)

---

## 🧱 ELF File Format Diagram

+-------------------------+
| ELF Header | ← Info about the file
+-------------------------+
| Program Header Table | ← Used at runtime (loader uses this)
+-------------------------+
| Section Header Table | ← Used at compile/link time
+-------------------------+
| Sections / Segments |
| - .text | ← Code (instructions)
| - .data | ← Initialized data (variables)
| - .bss | ← Uninitialized data (zero-filled)
| - .rodata | ← Read-only data (e.g., const)
| - .symtab/.strtab | ← Symbol & string tables
| - .rel/.rela | ← Relocation info
+-------------------------+

---

## 🧠 Easy Way to Remember ELF Parts

| Part             | Meaning                   |
|------------------|----------------------------|
| Header           | Identity                  |
| Program Header   | Runtime Info              |
| Section Header   | Linking Info              |
| `.text`          | Code (instructions)       |
| `.data`          | Init values               |
| `.bss`           | Uninit values             |
| `.rodata`        | Read-only constants       |
| `.symtab`        | Symbol names              |
| `.rel/.rela`     | Relocation entries        |

---

## 🚀 Real-Time Applications of ELF

1. **Running Linux Programs**  
   → Commands like `ls`, `cat` are ELF binaries.

2. **System Libraries (`.so` Files)**  
   → libc.so, libm.so, etc. are ELF shared libraries.

3. **Linux Kernel and Drivers**  
   → Kernel (`vmlinux`) and loadable modules (`.ko`) use ELF format.

4. **Debugging & Crash Analysis**  
   → Tools like `gdb`, `readelf`, and core dumps depend on ELF structure.

---

