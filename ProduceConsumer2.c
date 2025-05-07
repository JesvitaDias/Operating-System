#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 10
int buffer[BUFFERSIZE];
int in = 0, out = 0;
int empty = BUFFERSIZE;
int full = 0;
int mutex = 1;
void wait(int *x) {
    while (*x <= 0);
    (*x)--;
}

void signal(int *x) {
    (*x)++;
}

void producer() {
    wait(&empty);
    wait(&mutex);
    int item = rand() % 100;
    buffer[in] = item;
    printf("Producer produced: %d\n", item);
    in = (in + 1) % BUFFERSIZE;
    signal(&mutex);
    signal(&full);
}

void consumer() {
    wait(&full);
    wait(&mutex);
    int item = buffer[out];
    printf("Consumer consumed: %d\n", item);
    out = (out + 1) % BUFFERSIZE;
    signal(&mutex);
    signal(&empty);
}
void main() {
    int choice;
    printf("Enter a choice: 1.Produce  2.Consume  3.Produce and Consume  4.Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (empty > 0)
                    producer();
                else
                    printf("Buffer is full.Cannot produce");
                break;
            case 2:
                if (full > 0)
                    consumer();
                else
                    printf("Buffer is empty.Cannot consume");
                break;
            case 3:
                producer();
                consumer();
                break;
            case 4:
                exit(0);
            default:
                {
                printf("Invalid choice,exiting");
                exit(0);
                }
        }
    }


}
