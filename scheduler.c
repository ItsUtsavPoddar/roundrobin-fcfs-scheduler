#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void calcAvg(int n, int *waitTime, int *turnaroundTime, int *responseTime)
{
    float avgWaitTime = 0, avgTurnaroundTime = 0, avgResponseTime = 0;

    for (int i = 0; i < n; i++)
    {
        avgWaitTime += waitTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgResponseTime += responseTime[i];
    }

    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    avgResponseTime /= n;

    printf("\nAverage Waiting Time: %.2f", avgWaitTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Response Time: %.2f", avgResponseTime);
}

// Function to implement FCFS scheduling

void fcfs(int n, int arrivalTime[], int burstTime[])
{
    int waitTime[n], turnaroundTime[n], responseTime[n], finishTime[n];

    waitTime[0] = 0;
    turnaroundTime[0] = burstTime[0];
    responseTime[0] = 0;
    finishTime[0] = burstTime[0];

    for (int i = 1; i < n; i++)
    {
        finishTime[i] = finishTime[i - 1] + burstTime[i];
        turnaroundTime[i] = finishTime[i] - arrivalTime[i];
        waitTime[i] = turnaroundTime[i] - burstTime[i];
        responseTime[i] = waitTime[i];
    }

    printf("\nGantt Chart for FCFS Scheduling:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t", i + 1);
    }

    // Display process wait and turnaround times
    printf("\n\nProcess\tArrival Time\tBurst Time\tFinish Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], finishTime[i], turnaroundTime[i], waitTime[i], responseTime[i]);
    }

    // Calculate and display average times
    calcAvg(n, waitTime, turnaroundTime, responseTime);
}

void recordResponseTime(int *p, int a)
{
}

// Function to implement Round Robin scheduling WITH PROPER COMMENTS

void rr(int n, int *arrivalTime, int *burstTime, int timeQuantum)
{
    // structure to check and store response time of process
    struct res
    {
        bool beenHere;
        int time;
        bool beenAdded;
    };
    struct res flags[n];

    // initializing each struct with default values of time = 0 and beenHere = false
    for (int i = 0; i < n; i++)
    {
        flags[i].beenHere = false;
        flags[i].beenAdded = false;
        flags[i].time = 0;
    }

    // declaring the different arrays for each attribute
    int waitTime[n], turnaroundTime[n], responseTime[n], finishTime[n], ReadyQueue[n], remainingTime[n];

    // initializing each array with the default values
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = burstTime[i];
        waitTime[i] = 0;
        turnaroundTime[i] = 0;
        responseTime[i] = -1;
    }

    // HARD CODING VALUES for the first process as it will always have response time = 0 and will be first in readyQueue
    responseTime[0] = 0;
    ReadyQueue[0] = 0;
    flags[0].beenAdded = true;

    // front and rear for the circular queue implementation on readyQueue
    int front = 0, rear = 0;

    // TIME variable will store total time
    int time = 0;

    // notHasBeenAdded stores the complement of number of the processes not added in the readyQueue yet based on their ArrivalTime
    int notHasBeenAdded = 1;

    // TO Display Gantt Chart
    printf("\nGantt Chart for Round Robin Scheduling (Time Quantum = %d):\n", timeQuantum);

    while (front != -1) // For the circular queue
    {
        int process = ReadyQueue[front]; // process stores the current process to be executed

        if (remainingTime[process] > 0 && remainingTime[process] > timeQuantum)
        {

            // This block of code checks if the process has already been executed or not to get the first response time
            if (!flags[process].beenHere)
            {
                flags[process].time = time;
                flags[process].beenHere = true;
            }

            // time is incremented by the time quantum (remember we have already checked that process's burst Time > time quantum so we can safely add timeQuantum directly)
            time += timeQuantum;

            // printing the gantt chart
            printf("P%d\t", process + 1);

            // adds processes that has not been yet added in the ready queue
            for (int i = 0; i < n; i++)
            {
                if ((!flags[i].beenAdded) && arrivalTime[i] <= time)
                {
                    flags[i].beenAdded = true;
                    rear = (rear + 1) % n;
                    ReadyQueue[rear] = i;
                }
            }

            // updates the remaining time of process and adds in the rear of circular ReadyQueue; also we update front
            remainingTime[process] -= timeQuantum;
            rear = (rear + 1) % n;
            ReadyQueue[rear] = process;

            front = (front + 1) % n;
        }
        // FOR THE PROCESS WHOSE REMAINING TIME IS LESS THAN TIME QUANTUM
        else
        {
            // This block of code checks if the process has already been executed or not to get the first response time
            if (!flags[process].beenHere)
            {
                flags[process].time = time;
                flags[process].beenHere = true;
            }

            // Now here we add remainingTime of the process directly bcs we have checked that it is less than time quantum
            time += remainingTime[process];

            // printing the gantt chart
            printf("P%d\t", process + 1);

            // adds processes that has not been yet added in the ready queue
            for (int i = 0; i < n; i++)
            {
                if ((!flags[i].beenAdded) && arrivalTime[i] <= time)
                {
                    flags[i].beenAdded = true;
                    rear = (rear + 1) % n;
                    ReadyQueue[rear] = i;
                }
            }

            // We finally calculate the turnAroundTime and waitTime given the process has completed its execution
            turnaroundTime[process] = time - arrivalTime[process];
            waitTime[process] = turnaroundTime[process] - burstTime[process];

            // obviously
            remainingTime[process] = 0;

            // CHECKING if there are any more processes in the Queue or Not
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % n;
            }
        }
    }

    // storing responseTime In Array for ease may use struct directly in future or you can modify the code yourself (recordResponseTime function declared)
    for (int i = 0; i < n; i++)
    {
        responseTime[i] = flags[i].time;
    }

    for (int i = 0; i < n; i++)
    {
        responseTime[i] -= arrivalTime[i];
    }

    // To Display process' arrival, burst, wait, turnaround and response times
    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitTime[i], turnaroundTime[i], responseTime[i]);
    }

    // Calculate and display average times
    calcAvg(n, waitTime, turnaroundTime, responseTime);
}

void main()
{
    int n, chayan;
    // chayan is hindi word for selection, so don't get confused

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], timeQuantum;
    printf("\nEnter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    do
    {
        printf("\nChoose the scheduling policy:\n");
        printf("1. First Come First Served (FCFS)\n");
        printf("2. Round Robin (RR)\n");
        printf("3. Exit from program\n");
        printf("Enter your choice: ");
        scanf("%d", &chayan);
        if (chayan == 3)
        {
            break;
        }
        switch (chayan)
        {
        case 1:
            fcfs(n, arrivalTime, burstTime);
            break;
        case 2:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &timeQuantum);
            rr(n, arrivalTime, burstTime, timeQuantum);
            break;
        default:
            printf("ERRROOOORRR! Invalid choice. Enter a valid option.\n");
        }
    } while (true);

    // int arrivalTime[5] = {0, 5, 1, 6, 8};
    // int burstTime[5] = {8, 2, 7, 3, 5};
    // rr(5, arrivalTime, burstTime, 3);
}
