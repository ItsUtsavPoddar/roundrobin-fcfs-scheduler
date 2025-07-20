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

## 📘 Official Coursework Problem Statement

As part of our **Operating Systems Final Project**, we were required to design a **menu-driven C program** to simulate CPU scheduling using:

1. **First Come First Served (FCFS)**
2. **Round Robin (RR)** with a user-defined time quantum

##

### 📝 Program Requirements

The C program should:

- Accept user input for:
  - Number of processes
  - Process IDs (assumed unique)
  - Arrival times and CPU burst times
- Provide a **switch-case menu interface** with:
  - Option 1: Execute FCFS
  - Option 2: Execute RR
  - Option 3: Exit the program
- Allow entry of **time quantum** when RR is selected
- Simulate the scheduling policy and print:
  - Gantt Chart
  - Process Table including:
    - Waiting Time (WT)
    - Turnaround Time (TAT)
    - Response Time (RT)
  - Averages of each time metric

##

### 📊 Scheduling Constraints

- Each process has only **one CPU burst** (no I/O wait).
- RR Scheduling should follow:
  - **Preemption** based on time quantum
  - Newly arrived processes go to the **back of the ready queue**
  - Interrupted processes return to the **end of the queue**
- Output must be **formatted clearly** for visual analysis.

##
### 🧪 Sample Input (Official Coursework Test Case)


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
#### 🔁 Round Robin Output (MAIN HIGHLIGHT)
##### Gantt Chart for Round Robin Scheduling (Time Quantum = 4):

| P1  | P2  | P3  | P4  | P1  | P5  | P1  | P5  |
|-----|-----|-----|-----|-----|-----|-----|-----|

##### 🔁 Round Robin – Process Table

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

#### ⚙️ FCFS Output
##### Gantt Chart for FCFS Scheduling:

| P1  | P2  | P3  | P4  | P5  |
|-----|-----|-----|-----|-----|

##### 🔹 FCFS – Process Table

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

##

#### 📊 Analysis

Compared to FCFS, **Round Robin (RR)**:
- 🟢 Reduced **average waiting time** from `7.20 → 5.20`
- 🧠 Improved **average response time** from `7.20 → 3.20`
- ⚖️ Achieved **fairer distribution of CPU time**  
- 💬 Showed how preemptive scheduling improves short-task response

##

#### ✅ Conclusion

This validated test case was part of my official OS lab coursework.  
It proves that the logic, Gantt chart, and averages are correct — even under non-trivial burst/arrival patterns.

---

## ▶️ How to Run

### 🛠️ Requirements:
- GCC installed (`gcc --version`)

### ⚙️ Compile & Execute

```bash
gcc scheduler.c -o scheduler
./scheduler
