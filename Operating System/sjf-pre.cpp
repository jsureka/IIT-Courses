
#include<bits/stdc++.h>
using namespace std;



using namespace std;



int main()
{
    struct process{
        int pid;
        int bt;
        int btc;
        int avt;
        int flag=0;
        int ctime=0;
        int ttime=0;
        int wtime=0;

    }pro[6];
    pro[0].pid = 1;
     pro[1].pid = 2;
      pro[2].pid = 3;
       pro[3].pid = 4;
        pro[4].pid = 5;
         pro[5].pid = 6;
    pro[0].btc = 15;
     pro[1].btc =20;
      pro[2].btc =20;
       pro[3].btc =20;
        pro[4].btc =5;
         pro[5].btc =15;
           pro[0].bt = 15;
     pro[1].bt =20;
      pro[2].bt =20;
       pro[3].bt =20;
        pro[4].bt =5;
         pro[5].bt =15;
    pro[0].avt =0;
    pro[1].avt=0;
      pro[2].avt = 20;
       pro[3].avt = 25;
        pro[4].avt = 45;
         pro[5].avt = 55;
//     int process[6]={1,2,3,4,5,6};
//    int burst[6]={15,20,20,20,5,15};
//    int arrival[6]={0,0,20,25,45,55};
//    int wt[6],tt[6];

    int sum_w=0, sum_t=0;
    double avg_w=0, avg_t=0;
    int time=0;
    int sch[7];
    int schc=0;
    for(int i=0;i<=95;i++)
    {
         int temp[6]={1000,1000,1000,1000,1000,1000};
        int coun=0;
        for(int j=0;j<6;j++)
        {

            if(pro[j].avt<=time&&pro[j].flag==0)
            {
                temp[coun]=pro[j].bt;
                coun++;
            }
        }

        sort(temp,temp+6);

        for(int k=0;k<6;k++)
        {
            if(pro[k].bt==temp[0]&&pro[k].flag==0)
            {

                pro[k].bt-=1;

                if(pro[k].bt==0)
                {
                    pro[k].flag=1;
                    pro[k].ctime=time;
                    sch[schc]=pro[k].pid;
                    schc++;

                }
                time+=1;
                break;
            }
        }
    }
    for(int i=0;i<6;i++)
    {
        pro[i].ttime=pro[i].ctime-pro[i].avt;
        sum_t+=pro[i].ttime;
    }
    for(int i=0;i<6;i++)
    {
        pro[i].wtime=pro[i].ttime-pro[i].btc;
        sum_w+=pro[i].wtime;
    }
    avg_t=(double)sum_t/6;
    avg_w=(double)sum_w/6;
    for(int i=0;i<6;i++)
    {
        cout<<"Scheduele "<<i+1<<" : "<<sch[i]<<endl;
    }

    cout<<"Average Turnaround Time : "<<avg_t<<endl;
    cout<<"Average Waiting Time : "<<avg_w<<endl;

    return 0;
}

