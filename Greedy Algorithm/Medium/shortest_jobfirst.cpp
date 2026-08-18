/*Shortest Job First (SJF) Scheduling

SJF is a CPU scheduling algorithm where the process with the smallest CPU burst time is executed first.

Think of it as:

Among all available processes, choose the one that will finish fastest.

Example

Suppose all processes arrive at time 0:

Process	Burst Time
P1	6
P2	2
P3	8
P4	3

SJF sorts them by burst time:

P2 → P4 → P1 → P3

Gantt chart:*/

/*0      2      5           11              19
| P2   | P4   |    P1     |      P3       |*/

/*Waiting Time

Waiting time = time a process waits before getting CPU*/

/*P2 = 0
P4 = 2
P1 = 2 + 3 = 5
P3 = 2 + 3 + 6 = 11*/

/*Average waiting time:


(0+2+5+11)/4=4.5

A major advantage of SJF is that it gives the minimum average waiting time among non-preemptive scheduling choices when burst times are known.
*/

long long solve(vector<int> arr) {
    sort(arr.begin(), arr.end());

    long long wtTime = 0;
    long long ans = 0;

    for (int i = 0; i < arr.size(); i++) {
        ans += wtTime;
        wtTime += arr[i];
    }

    return ans / arr.size();
}

// tc is O(N) + O(NlogN) and sc is O(1)