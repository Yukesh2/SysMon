# 🖥️ SysMon — Linux Memory Monitor

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square)
![Linux](https://img.shields.io/badge/Platform-Linux-brightgreen?style=flat-square)


A FUi tool that continuously polls the Linux kernel's virtual filesystem to report **total and free memory in real time** 

---

## ✨ Features

- **Live polling** — refreshes memory stats every 3 seconds in a continuous loop
- **Kernel-direct reads** — reads straight from `/proc/meminfo`, no third-party parsers
- **Human-readable output** — converts raw kB values to GB automatically


---

## 📋 Requirements

| Requirement | Details |
|-------------|---------|
| **OS** | Linux (requires `/proc` filesystem) |
| **Compiler** | `g++` with C++17 support |


---

## 🚀 Build & Run




**1. Compile**
```bash
g++ filename -o monitor
```

**2. Run**
```bash
./sysmon
```

**Expected output:**
```
Total Mem: 15.82 GB
Used Mem:  3.41 GB
```
The display refreshes in-place every 3 seconds.

---

## 🗂️ Code Structure

```
sysmon/
├── main.cpp       # Entry point + Process class
└── README.md
```

```cpp
class Process {
    // Reads /proc/meminfo via std::ifstream
    void Memusage();  // Prints total + free mem, sleeps 3s
};

int main() {
    Process monitor;
    while (true) monitor.Memusage();  // Continuous poll loop
}
```

### How it works

1. Opens `/proc/meminfo` using `std::ifstream`
2. Reads `MemTotal` and `MemFree` values (in kB)
3. Converts to GB (`value / 1,000,000`)
4. Prints to stdout with ANSI cursor control (`\033[2A`) to update in-place
5. Sleeps for 3 seconds, then repeats

---

## 🔭 Roadmap

- [ ] **CPU monitoring** — extend to read `/proc/stat` for per-core CPU usage
- [ ] **Used memory calculation** — compute `MemTotal - MemAvailable` for accurate "used" figure

---

## ⚠️ Known Limitations

- Currently reports `MemFree` (completely unused memory), not "Used" memory. True used memory is `MemTotal - MemAvailable`.
- Only tested on Linux. Not compatible with macOS or Windows.

---

