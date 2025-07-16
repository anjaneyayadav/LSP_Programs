## Example Module of Linux Architecture

<img width="447" height="703" alt="Linux Architecture" src="https://github.com/user-attachments/assets/76e95e93-e2c2-485c-9dd2-974004fb5231" />

# ✅ Android vs Linux Architecture – Key Component Comparison

| **#** | **Component**                     | **Android**                                                                 | **Linux**                                                                   |
|-------|----------------------------------|------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| 1️⃣   | **C Library**                    | Uses **Bionic C Library** – lightweight, fast, optimized for low memory and CPU | Uses **glibc (GNU C Library)** – full-featured but large and slower        |
| 2️⃣   | **Low Memory Management**       | Uses **Low Memory Killer (LMK)** – kills cached/background apps proactively | Uses **OOM Killer** – triggers only when memory is completely exhausted     |
| 3️⃣   | **Sleep-Prone Kernel**          | System goes into **sleep mode** when screen is locked – to save battery     | **Sleep/Suspend** available but rarely used in desktops/servers            |
| 4️⃣   | **WakeLocks**                   | **WakeLock API is available** – apps can keep CPU/screen awake              | **No WakeLock API** – system sleep needs to be managed manually             |
| 5️⃣   | **IPC Mechanism**               | Uses **Binder IPC** – fast, secure, client-server communication (RPC style) | Uses **System V IPC** – includes pipes, message queues, shared memory       |
| 6️⃣   | **Hardware Abstraction Layer (HAL)** | Strong **HAL layer** – provides standardized interface to hardware         | **No dedicated HAL** – applications access hardware directly (via `/dev`)   |

