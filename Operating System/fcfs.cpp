#include<bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
     int process[6]={1,2,3,4,5,6};
    int burst[6]={15,20,20,20,5,15};
    int arrival[6]={0,0,20,25,45,55};
    int wt[6],tt[6];
    int sum_w=0, sum_t=0;
    int avg_w=0, avg_t=0;
    int ctime[6],time=0;
    wt[0]=0;
    ctime[0]=burst[0];
    for(int i=1;i<6;i++)
    {
        ctime[i]=burst[i]+ctime[i-1];

    }
    for(int i=0;i<6;i++)
    {
        tt[i]=ctime[i]-arrival[i];
        sum_t+=tt[i];
    }
     for(int i=1;i<6;i++)
    {
        wt[i]=tt[i]-burst[i];
        sum_w+=wt[i];
    }
    avg_t=sum_t/6;
    avg_w=sum_w/6;
    cout<< "Order of the processes : "<<endl;
    for(int i=0;i< 6;i++)
    {

        cout<< process[i]<<endl;
    }
    cout<<"Average Waiting Time : "<<avg_w<<endl;
    cout<<"Average TurnAround Time : " << avg_t<<endl;

}

