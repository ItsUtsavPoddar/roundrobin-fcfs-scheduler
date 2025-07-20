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
## 🧪 Sample Input (Official Coursework Test Case)

**Processes:**

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 10         |
| P2      | 1            | 1          |
| P3      | 2            | 2          |
| P4      | 3            | 1          |
| P5      | 6            | 5          |

**Time Quantum for RR: 4 ms**
##
### 🔁 Round Robin Output (MAIN HIGHLIGHT)
#### Gantt Chart for Round Robin Scheduling (Time Quantum = 4):

| P1  | P2  | P3  | P4  | P1  | P5  | P1  | P5  |
|-----|-----|-----|-----|-----|-----|-----|-----|

#### 🔁 Round Robin – Process Table

| Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Response Time |
|---------|--------------|------------|---------------|------------------|----------------|
| P1      | 0            | 10         | 8             | 18               | 0              |
| P2      | 1            | 1          | 3             | 4                | 3              |
| P3      | 2            | 2          | 3             | 5                | 3              |
| P4      | 3            | 1          | 4             | 5                | 4              |
| P5      | 6            | 5          | 8             | 13               | 6              |

- Average Waiting Time: 5.20
- Average Turnaround Time: 9.00
- Average Response Time: 3.20

##

### ⚙️ FCFS Output
#### Gantt Chart for FCFS Scheduling:

| P1  | P2  | P3  | P4  | P5  |
|-----|-----|-----|-----|-----|

#### 🔹 FCFS – Process Table

| Process | Arrival Time | Burst Time | Finish Time | Turnaround Time | Waiting Time | Response Time |
|---------|--------------|------------|-------------|------------------|---------------|----------------|
| P1      | 0            | 10         | 10          | 10               | 0             | 0              |
| P2      | 1            | 1          | 11          | 10               | 9             | 9              |
| P3      | 2            | 2          | 13          | 11               | 9             | 9              |
| P4      | 3            | 1          | 14          | 11               | 10            | 10             |
| P5      | 6            | 5          | 19          | 13               | 8             | 8              |

- Average Waiting Time: 7.20
- Average Turnaround Time: 11.00
- Average Response Time: 7.20

## ▶️ How to Run

### 🛠️ Requirements:
- GCC installed (`gcc --version`)

### ⚙️ Compile & Execute

```bash
gcc scheduler.c -o scheduler
./scheduler
