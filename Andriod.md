## Example Module of Linux Architecture

<img width="447" height="703" alt="Linux Architecture" src="https://github.com/user-attachments/assets/76e95e93-e2c2-485c-9dd2-974004fb5231" />

# ✅ Android vs Linux: Architecture 

| **#** | **Feature / Module**             | **Android**                                                                 | **Linux**                                                                  |
|-------|----------------------------------|------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| 1     | **Bionic C Library**             | Uses **Bionic C** (lightweight, faster, optimized for low memory/CPU)       | Uses **glibc** (fully featured but larger and slower to load)              |
| 2     | **Scheduler - CFS**              | Uses **Completely Fair Scheduler (CFS)** with vruntime and nice values      | Also uses **CFS**, replaces older Round Robin/Priority scheduling          |
|       |                                  | Red-Black Tree based – Leftmost node = smallest `vruntime`                 | Same mechanism                                                             |
|       |                                  | `vruntime = CPU_time × weight` based on nice value                         | Same concept with `nice` values (-20 to +19)                               |
| 3     | **Low Memory Management**        | Uses **Low Memory Killer (LMK)** to kill background/cached apps early      | Uses **OOM Killer** (Out Of Memory) only when system is completely out     |
|       |                                  | Based on **priority score** (foreground > background > cached)            | Less refined, reactive rather than proactive                               |
| 4     | **Sleep-Prone Kernel**           | System goes to **sleep/suspend** when user locks screen                    | Suspend available, but less utilized in desktops/servers                   |
| 5     | **WakeLocks**                    | Allows apps to **keep CPU/screen awake** during critical tasks             | Not commonly used; no WakeLock API                                         |
|       |                                  | Used for music, GPS, background services                                   | Not available by default                                                   |
| 6     | **IPC Mechanism**                | Uses **Binder IPC** – fast, secure RPC-style client-server communication   | Uses traditional **System V IPC**: pipes, message queues, shared memory    |
| 7     | **Hardware Abstraction Layer**   | Strong **HAL** layer for accessing hardware through defined interfaces     | Direct hardware access, less abstraction                                  |
| 8     | **Logging Mechanism**            | Uses `dmesg` (kernel logs), `logcat` (app/system logs, circular buffer)    | Uses `dmesg` for kernel logs, `journalctl` for services                    |
