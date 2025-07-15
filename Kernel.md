# WHAT IS BOOTLOADER?

- A **bootloader** is a small program that:

- Runs **before the operating system starts**

- Loads the **OS kernel** into memory

- Gives control to the **CPU** to start the OS

---
# BOOTLOADER ARCHITECTURE

```text

[Power ON]
     ↓
[First Stage Bootloader]
     ↓
[Second Stage Bootloader]
     ↓
[Kernel Loading]
     ↓
[Init Process / User-space]
     ↓
[Login screen / GUI / Terminal]

# 🧠 Full Linux Boot Process Explained

---

## ✅ 1. Power ON

🔹 When you press the power button:

- Electricity flows to motherboard, CPU, RAM, etc.

- CPU starts running from a fixed address (on x86: FFFF:0000)

- It looks for firmware — which is *BIOS* or *UEFI*

📌 This is not software yet, it's *pre-installed on the motherboard*.

---

## ✅ 2. BIOS / UEFI

🔹 BIOS (Legacy) or UEFI (Modern firmware):

- Performs *POST* (Power-On Self Test)

- Checks RAM, CPU, keyboard, etc.

- Finds the bootable device (HDD/SSD/USB)

- Loads first 512 bytes (MBR) from disk (in BIOS)

- Or loads .efi file from EFI partition (in UEFI)

📌 This firmware is responsible for *finding and starting the bootloader*.

---

## ✅ 3. Bootloader (GRUB, U-Boot)

🔹 Bootloader is a small program on disk (in MBR or EFI partition).

- Shows *boot menu* (Linux, Windows, etc.)
- Loads Linux *kernel image* (vmlinuz) into memory
- Loads *initrd/initramfs* (temporary root filesystem)
- Passes boot arguments (e.g., root=/dev/sda1)
- Finally, gives control to the *kernel*

📌 Bootloader = "*middleman*" between firmware and kernel

---

## ✅ 4. Linux Kernel Loads

🔹 Now *kernel is running* — it's in full control of the CPU.

- Initializes memory and enables *virtual memory* (paging)
- Detects hardware (USB, disk, network, etc.)
- Loads *device drivers*
- Mounts the *root filesystem*
- Unpacks *initrd* (if provided)

📌 Once ready, the kernel runs the *first user program*: init

---

## ✅ 5. Init Process Starts

🔹 Kernel executes /sbin/init or /lib/systemd/systemd (PID 1)

- Starts all *system services* (daemons)
- Loads configuration files (/etc/inittab, or systemd units)
- Starts *login service*:
  - If GUI system → gdm, lightdm, sddm
  - If terminal → shows *TTY login screen*

📌 init is the *root controller* of userspace — it decides what runs.

---

## ✅ 6. Login Screen / GUI / Terminal

🔹 Based on init settings, system shows:

- A *graphical login screen* (GNOME, KDE, etc.)
- Or a *terminal login prompt* (on servers)

✅ From here, the user logs in and runs programs.

---

## 🧾 Summary Table

| Stage         | Main Task                                      |
|---------------|------------------------------------------------|
| Power ON      | Start motherboard and CPU                      |
| BIOS/UEFI     | Load bootloader from disk                      |
| Bootloader    | Load kernel + initrd and pass boot options     |
| Linux Kernel  | Setup memory, drivers, mount root filesystem   |
| Init Process  | Start services and login manager               |
| Login Screen  | User logs in, OS is ready to use               |
