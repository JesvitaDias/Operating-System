#include<stdio.h>
#include<stdlib.h>
#define BUFFERSIZE 10
int buffer[BUFFERSIZE];
int in = 0, out = 0;
int empty = BUFFERSIZE;
int full = 0;
int mutex = 1;
void wait(int *x)
{
    while(*x<=0);
    (*x)--;
}
void signal(int *x)
{
    (*x)++;

}
void producer()
{
    wait(&mutex);
    wait(&empty);
    int item;
    item=rand()%100;
    buffer[in]=item;
    printf("Producer produced %d\n",buffer[in]);
    in=(in+1)%BUFFERSIZE;
    signal(&full);
    signal(&mutex);
}
void consumer()
{
    wait(&full);
    wait(&mutex);
    int item = buffer[out];
    printf("Consumer consumed %d\n",buffer[out]);
    out = (out + 1) % BUFFERSIZE;

    signal(&mutex);
    signal(&empty);
}
void main()
{
   int choice;
   printf("Enter a choice: 1.Produce  2.Consume    3.Produce and Consume   4.Exit\n");
   while(1)
   {
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:if(empty>0)
                 {producer();
                    break;}

           case 2:if(full>0)
                  {consumer();
                   break;}
           case 3:{
                  producer();
                  consumer();
                   break;}
           default: exit(0);
       }
   }
}
