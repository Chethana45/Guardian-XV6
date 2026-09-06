# 🛡️ GuardianXV6

### Kernel-Level Behavioral Intrusion Detection System for xv6-RISC-V

> **Monitor processes. Analyze behavior. Detect threats.**

GuardianXV6 is a lightweight **kernel-level Intrusion Detection System (IDS)** integrated into the **xv6-RISC-V operating system**. It monitors process behavior and identifies abnormal activity using multiple system-level parameters.

---

## 🚀 Features

* 🔄 **Process Monitoring** — Tracks process creation and `fork()` activity
* ⚙️ **System Call Monitoring** — Tracks abnormal system-call activity
* 🖥️ **CPU Monitoring** — Detects sustained high CPU usage
* 📁 **File Activity Monitoring** — Monitors `open()`, `write()`, and `unlink()`
* 📊 **Risk Assessment** — Calculates a behavioral risk score
* 🚨 **Explainable Alerts** — Shows why a process is considered suspicious
* 🔐 **Optional Response** — Supports process termination for detected threats
* 🖥️ **`ids` Command** — Displays real-time IDS status

---

## 🏗️ Architecture

```text
User Process
     │
     ▼
 System Calls
     │
     ▼
┌───────────────────┐
│    xv6 Kernel     │
│                   │
│ Process Monitor   │
│ Syscall Monitor   │
│ CPU Monitor       │
│ File Monitor      │
└─────────┬─────────┘
          │
          ▼
   Behavior Analyzer
          │
          ▼
    Risk Assessment
          │
     ┌────┼────┐
     ▼    ▼    ▼
   SAFE WARNING ALERT
```

---

## 🎯 Detection

GuardianXV6 analyzes multiple behavioral indicators:

| Behavior      | Detection                      |
| ------------- | ------------------------------ |
| Fork Abuse    | Excessive process creation     |
| CPU Abuse     | Sustained high CPU activity    |
| File Abuse    | Excessive file operations      |
| Syscall Abuse | Abnormal system-call frequency |

### Risk Levels

```text
0 – 30    → NORMAL
31 – 60   → WARNING
61 – 100  → SUSPICIOUS
```

---

## 🧪 Testing

Controlled attack simulations are used to demonstrate the IDS:

```text
forkbomb.c       → Process creation abuse
cpuhog.c         → CPU abuse
fileattack.c     → File activity abuse
syscallstorm.c   → System-call abuse
```

These are **bounded test programs for educational demonstration**, not real malware.

---

## 🛠️ Tech Stack

`xv6-RISC-V` • `C` • `RISC-V` • `QEMU` • `GCC` • `Make` • `Git`

---

## ⚡ Getting Started

### Clone

```bash
git clone https://github.com/<your-username>/GaurdianXV6.git
cd GaurdianXV6
```

### Build

```bash
make clean
make
```

### Run xv6

```bash
make qemu
```

### View IDS

Inside xv6:

```bash
ids
```

Example:

```text
PID   PROCESS    SYSCALLS   FORKS   CPU   RISK   STATUS
1     init       15         1       10    0      NORMAL
2     sh         42         3       20    5      NORMAL
8     attacker   721        86      95    75     ALERT
```

---

## 📂 Project Structure

```text
GuardianXV6/
├── kernel/
│   ├── proc.c
│   ├── proc.h
│   ├── syscall.c
│   ├── sysfile.c
│   ├── sysproc.c
│   ├── ids.c
│   └── ids.h
│
├── user/
│   ├── ids.c
│   ├── forkbomb.c
│   ├── cpuhog.c
│   ├── fileattack.c
│   └── syscallstorm.c
│
├── Makefile
└── README.md
```

---

## 🎓 Project Focus

**Operating Systems • Kernel Programming • xv6 • Process Management • System Calls • Cybersecurity • Intrusion Detection**

GuardianXV6 combines these concepts into an integrated behavioral IDS framework for xv6-RISC-V.

---

## 🔮 Future Scope

* Adaptive behavioral profiling
* Advanced risk scoring
* ML-based anomaly detection
* Security monitoring dashboard
* Additional attack detection
* Linux kernel implementation

---

## 👥 Team

**GuardianXV6 — Operating Systems & Cybersecurity Project**

> *Built for learning, experimentation, and research in operating-system security.*

---

### ⭐ GuardianXV6

**Monitor → Analyze → Detect → Respond**
