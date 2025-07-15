# 🔧 What is Bootloader?
```
A *bootloader* is a small program that:

- Runs *before the operating system starts*
- Loads the *OS kernel* into memory
- Gives control to the *CPU* to start the OS
```

# 🧱 Bootloader Architecture

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
