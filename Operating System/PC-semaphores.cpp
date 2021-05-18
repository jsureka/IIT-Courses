#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
#define N 0
#define bsize 8
int coun= -1;
int buffer[8]={0};
int blank=8;
int full=0;
int t1=0;
int t2=0;
bool locked = false;
int s=0;
bool testnSet( bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;

}

void wait(int *var)
{
    while(var<=0);
    var--;
}

void signal(int *var)
{
    while(testnSet(&locked));
    var++;
}
void *producer ( void* ){
    while(t2<10)
    {
        wait(&blank);
        coun++;
        int temp = 5;
        buffer[coun] = temp;
        printf("Job %d has been produced\n", temp);
        t2++;
        locked=false;
        signal(&full);
    }

}

void *consumer( void* ){


    while(t1<10)
    {
        wait(&full);
        coun--;
        printf("Job %d has been consumed\n", buffer[0]);
        t1++;
        locked=false;
        signal(&blank);
    }

}
int main(){

    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, producer,NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1,NULL);
    pthread_join(t2, NULL);

}

