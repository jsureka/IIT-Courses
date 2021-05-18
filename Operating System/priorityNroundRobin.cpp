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

void solutionwithRoundRobin(int priority[], int burst[], int arrival[], int n)
{
    int quantam = 10;
    int totalWaitingTime = 0, totalTurnAroundTime =0;
    int waitingTime[n] ={0}, turnAroundTime[n]={0}, temp[10];
    int total =0, cc2=0;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        temp[i]=burst[i];
    }
    queue<process> q;
    vector<int> res;
    int  wait=0;
    int wt=0,tt=0;
    process minArivProcess;
    minArivProcess.arrival=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(processes[i].arrival<minArivProcess.arrival)
        {
            minArivProcess = processes[i];
        }
    }
    q.push(minArivProcess);
    int counter2=0;
    //cout<< "size"<< q.size()<<endl;
    while(!q.empty())
    {
        process tem = q.front();
        q.pop();
        res.push_back(tem.pid);
        //q.pop();
        if(tem.burst<=quantam&&tem.burst>0)
        {
            //cout<< "1"<<endl;
            total +=  tem.burst;
            tem.burst=0;
            flag=true;
        }
        else if(tem.burst>0)
        {
            //cout<< "2"<<endl;
            total += quantam;
            tem.burst -= quantam;
        }
        if(tem.burst==0 && flag==true)
        {
            cc2++;
            waitingTime[counter2++] = total-tem.arrival-temp[tem.pid-1];
            if(waitingTime[counter2-1]<0) waitingTime[counter2-1]=0;
            wt+=waitingTime[counter2-1];
            turnAroundTime[counter2-1] = total - tem.arrival;
            tt+=turnAroundTime[counter2-1];
            totalTurnAroundTime = totalTurnAroundTime + total - tem.arrival;
        }
        for(int i=0;i<n;i++)
        {
            if(processes[i].pid==tem.pid)
            {
                processes[i].burst=tem.burst;
            }
        }
        int ii=tem.pid;
        if(ii==n) ii=0;
        //if(tem.pid==n) ii=0;
        //else ii=tem.pid;
        int counter = 0;
        //cout<< ii<< endl;
        while(counter++<n)
        {
            if(processes[ii].arrival<=total&&processes[ii].pid!=tem.pid && processes[ii].burst>0)
            {
                q.push(processes[ii]);
                ii++;
                break;
            }
            ii++;
            if(ii==n) ii=0;
        }
        if(cc2==n)
        {
            break;
        }
    }
    cout<< "Order: ";
    for(int i=0;i<res.size();i++)
    {
        cout<< res[i]<< " ";
    }
    cout<< endl;
    //cout<<wt<<endl;
    cout<< "Avg Waiting Time : "<< (float) wt/ (float)n<<endl;
    cout<< "Avg TurnAround Time : "<< (float) tt/ (float)n<<endl;
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
    solutionwithRoundRobin(priority,brust,arrival,n);
}
