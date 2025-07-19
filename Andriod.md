## Example Module of Linux Architecture

<img width="447" height="703" alt="Linux Architecture" src="https://github.com/user-attachments/assets/76e95e93-e2c2-485c-9dd2-974004fb5231" />

---

### 🔵 1. Some App (e.g., `bluetoothctl`)

- This is a **user-space application** that the user runs to control Bluetooth functionality.
- Example: `bluetoothctl` can scan, pair, and connect to Bluetooth devices.
- It **doesn't talk to the driver directly**; it communicates via a service.

---

### 🔁 2. IPC (e.g., `dbus`)

- The app uses **Inter-Process Communication (IPC)** to communicate with a **Bluetooth service**.
- In Linux, `dbus` is a common IPC mechanism.
- This allows processes to **exchange information securely and efficiently**.
- Think of this like a **messenger** between app and background service.

---

### 🛠️ 3. Service (e.g., `systemd-bluetooth`)

- A **background system service** that handles Bluetooth operations.
- Runs continuously to manage connections, visibility, discovery, etc.
- Receives commands from apps via IPC (dbus) and delegates them to libraries.

---

### 📚 4. Library (e.g., `bluetooth.c`)

- The service uses **Bluetooth-specific libraries** written in C (like `bluetooth.c`).
- These libraries contain reusable **Bluetooth functions and logic** (e.g., scanning, pairing, etc.).
- Acts as a **middleware** between the service and the core system.

---

### 📦 5. C Library (glibc or Bionic)

- These are the **standard C libraries** used by applications and services.
- Functions like `open()`, `read()`, `write()`, `ioctl()`, `poll()` are provided here.
- They **wrap around system calls**, making it easier for programmers to write code.

---

### 🧠 6. System Call Interface

- The C library uses **Linux system calls** to talk to the **kernel**.
- Example system calls: `open`, `read`, `write`, `ioctl`, `poll`.
- These **bridge user space to kernel space**.

---

### 🧩 7. Kernel Drivers (RFCOMM + UART)

#### ✅ RFCOMM Driver:

- Part of the **Bluetooth protocol stack in kernel**.
- Implements the RFCOMM protocol (Bluetooth serial port emulation).
- Enables sending/receiving data like a serial connection.

#### ✅ UART Driver:

- A **hardware-level driver** that communicates over the **serial UART interface** to the Bluetooth chip/module.
- Actual hardware transmission happens here.

---

### 📡 8. Bluetooth Module (Hardware)

- The **physical Bluetooth chip/module** connected via UART (or USB, SPI, etc.).
- Sends/receives Bluetooth signals (radio frequency).
- Handles actual wireless data communication.






# ✅ Android vs Linux Architecture – Key Component Comparison

| **#** | **Component**                     | **Android**                                                                 | **Linux**                                                                   |
|-------|----------------------------------|------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| 1️⃣   | **C Library**                    | Uses **Bionic C Library** – lightweight, fast, optimized for low memory and CPU | Uses **glibc (GNU C Library)** – full-featured but large and slower        |
| 2️⃣   | **Low Memory Management**       | Uses **Low Memory Killer (LMK)** – kills cached/background apps proactively | Uses **OOM Killer** – triggers only when memory is completely exhausted     |
| 3️⃣   | **Sleep-Prone Kernel**          | System goes into **sleep mode** when screen is locked – to save battery     | **Sleep/Suspend** available but rarely used in desktops/servers            |
| 4️⃣   | **WakeLocks**                   | **WakeLock API is available** – apps can keep CPU/screen awake              | **No WakeLock API** – system sleep needs to be managed manually             |
| 5️⃣   | **IPC Mechanism**               | Uses **Binder IPC** – fast, secure, client-server communication (RPC style) | Uses **System V IPC** – includes pipes, message queues, shared memory       |
| 6️⃣   | **Hardware Abstraction Layer (HAL)** | Strong **HAL layer** – provides standardized interface to hardware         | **No dedicated HAL** – applications access hardware directly (via `/dev`)   |

