#include<bits/stdc++.h>
using namespace std;

struct process{
    int arrival,burst,priority, pid;
    int passed=0;
};
process processes[6];
bool vis[7] = {false};
bool foo(process x, process y)
{
    if(x.arrival==y.arrival)
    {
        if(x.priority==y.priority)
        {
            return x.burst<y.burst;
        }
        else
            return x.priority>y.priority;
    }
    else
        return x.arrival<y.arrival;
}
void solutionwithPriority(int n)
{
    int waitingTime[n]={0};
    int turnAroundTime[n]={0};
    int service[n]={0};
    int totalWaitingTime = 0, totalTurnAroundTime =0;
    int totalBurst =0;
    for(int i=0;i<n;i++)
    {
         waitingTime[i]= totalBurst-processes[i].arrival;
         totalBurst+=processes[i].burst;
         turnAroundTime[i]=waitingTime[i]+processes[i].burst;

    }
    cout<< "Order: "<<endl;
    cout<< "Processes  BurstTime Priority"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<< "p"<< processes[i].pid<< "        "<< processes[i].burst<<"             "<< processes[i].priority<<endl;
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }
    cout<<endl;
    cout<< "Avg waiting: "<< (float) totalWaitingTime/(float)n<<endl;
    cout<< "Avg turnAround: "<< (float)totalTurnAroundTime/(float)n<<endl;
}


int main()
{
    int priority[] = {8,3,4,4,5,5};
    int brust[] = {15,20,20,20,5,15};
    int arrival[] = {0,0,20,25,45,55};
    int n = sizeof(priority)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        processes[i].arrival=arrival[i];
        processes[i].burst = brust[i];
        processes[i].priority=priority[i];
        processes[i].pid=i+1;
    }
    sort(processes,processes+n,foo);
    solutionwithPriority(n);
}
