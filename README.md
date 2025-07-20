# ⏱️ CPU Scheduling Simulator – Round Robin (MAIN HIGHLIGHT) & FCFS (C language)

This project implements two fundamental **CPU scheduling algorithms** in C:
- 🔁 **Round Robin (RR)**  *(MAIN HIGHLIGHT)*
- 🟢 **First Come First Served (FCFS)**

Built as part of my **Operating Systems coursework**, this simulation goes beyond basic scheduling — incorporating **accurate response time tracking**, dynamic queue handling, and visual Gantt chart output.

---

## 🧠 Why This Project Matters

While studying Operating Systems, I discovered that most textbook examples and online implementations **skip over tricky scheduling scenarios** — especially when it comes to:
- ✅ **Round Robin’s Response Time** (with dynamic arrivals) *(Main Focus)*
- Proper circular Ready Queue handling
- Accurate time tracking across preemptions

So I designed my own simulation from scratch — with:
- 🔄 Custom flag-based system to track **first execution time**
- 📊 Clean **Gantt Chart generation**
- 📋 Full table for Waiting Time, Turnaround Time, and Response Time

> 🔍 This wasn’t just coursework — it was my deep dive into how **real scheduling algorithms behave under constraints.**

---

## 🔧 Features

- Select **FCFS** or **Round Robin** at runtime
- Input process burst times, arrival times, and time quantum
- Computes:
  - ✅ Waiting Time
  - ✅ Turnaround Time
  - ✅ Response Time
- Displays:
  - 📊 Gantt Chart
  - 🧾 Process table
  - 📈 Average metrics

---

## ▶️ How to Run

### 🛠️ Requirements:
- GCC installed (`gcc --version`)

### ⚙️ Compile & Execute

```bash
gcc scheduler.c -o scheduler
./scheduler
