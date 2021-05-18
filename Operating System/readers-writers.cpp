#include<semaphore.h>
#include<bits/stdc++.h>
#include<pthread.h>
sem_t red,wrt;
int blank = 0;
int full = 0;
int readercount = 0;
int writercount = 0;

void *reader(void* p)
{
    while(readercount<4)
    {
        sem_wait((void**)&blank);
    printf("reader is inside\n");
     printf("readeris leaving\n");
    sem_post((void**)&full);
    readercount++;
    }

    return NULL;
}

void *wrtr(void* p)
{
   while(writercount<4)
   {
        sem_wait((void**)&full);
    printf("writer has entered\n");
     printf("writer is leaving\n");
    sem_post((void**)&blank);
    writercount++;
   }

    return NULL;
}

int main()
{
    pthread_t writethred,readerthread;
    sem_init(&red,0,0);
     pthread_create(&writethred,NULL,reader,NULL);
    pthread_create(&readerthread,NULL,wrtr,NULL);
          pthread_join(writethred,NULL);
        pthread_join(readerthread,NULL);
}
