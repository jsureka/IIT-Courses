#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;
#define FALSE 0
#define TRUE 1
#define N 0
#define bsize 8
int coun= -1;
int buffer[8]={0};
int turn;
int t1=0;
int t2=0;
bool lock = false;

bool testnSet( bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;

}
void *producer ( void* ){
    while(t2<10)
    {
        while (coun == bsize);
        while(lock==true);
        while (testnSet(&lock));

                    coun++;
                    int temp = 5;

                    buffer[coun] = temp;

        lock = false;
        printf("Job %d has been produced\n", temp);
        t2++;
    }

}

void *consumer( void* ){

    while(t1<10)
    {
        while( coun == -1);
        while(lock==true);
       while (testnSet(&lock));

                coun--;
                lock = false;
         printf("Job %d has been consumed\n", buffer[0]);
        t1++;
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
