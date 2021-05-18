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
bool flag[2];
int i=0;
int j=1;
int t1=0;
int t2=0;

void *producer ( void* ){
    while(t2<10)
    {
        flag[j] = TRUE;
        turn = i;
        while (coun == bsize);
        while (flag[i] == TRUE && turn == i);

                    coun++;
                    int temp = 5;
                    printf("Job %d has been produced\n", temp);
                    buffer[coun] = temp;

        flag[j] = false;
        t2++;
    }

}

void *consumer( void* ){

    while(t1<10)
    {
        flag[i] = TRUE;
        turn = j;
        while( coun == -1);
        while (flag[j] == TRUE && turn == j) ;

                printf("Job %d has been consumed\n", buffer[0]);
                buffer[coun] = 0;
                coun--;

        flag[i] = false;
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
