#include <stdio.h>
#include <unistd.h>
#define MAX 20
int forks;
int n;
int hungry[MAX];
int hungrycount;
int eating[20]={0};
void wait(int *s)
{
    while(*s<=0);
    *s=*s-1;
}
void signal(int *s)
{
    *s=*s+1;
}
int can_eat(int id) {
    int left = (id-1+ n)% n;
    int right = (id +1)%n;
    return !eating[left] && !eating[right];
}
void show_waiting(int start)
{
    for (int i =start; i <hungrycount; i++) {
        printf("P %d is waiting\n",hungry[i]);
    }
}
void oneeat() {
    forks =1;
    for (int i =0; i <hungrycount; i++) {
        show_waiting(i);
        int id =hungry[i];
        if (can_eat(id)) {
            wait(&forks);
            eating[id] =1;
            printf("P %d is granted to eat\n", id);
            sleep(1);
            printf("P %d has finished eating\n", id);
            eating[id]=0;
            signal(&forks);
        } else {
            printf("P %d cannot eat now due to neighbor eating\n",id);
        }
        sleep(1);
    }
}

void twoeat()
{
    forks =2;
    int i= 0;
    while (i <hungrycount) {
        show_waiting(i);
        int first = hungry[i];
        int second = (i + 1 <hungrycount)? hungry[i + 1]: -1;
        if (can_eat(first))
            {
            wait(&forks);
            eating[first] = 1;
            printf("P %d is granted to eat\n", first);
        } else {
            printf("P %d cannot eat now due to neighbor eating\n", first);
        }
        if (second !=-1 && can_eat(second)) {
            wait(&forks);
            eating[second]=1;
            printf("P %d is granted to eat\n", second);
        } else if (second!=-1) {
            printf("P %d cannot eat now due to neighbor eating\n", second);
        }
        sleep(1);
        if (eating[first]){
            printf("P %d has finished eating\n", first);
            eating[first] = 0;
            signal(&forks);
        }
        if (second!= -1 && eating[second]) {
            printf("P %d has finished eating\n", second);
            eating[second] = 0;
            signal(&forks);
        }
        i+=2;
        sleep(1);
    }
}

int main()
{
    int choice;
    printf("Enter the total number of philosophers: ");
    scanf("%d",&n);
    printf("How many are hungry: ");
    scanf("%d",&hungrycount);
    for (int i=0;i <hungrycount; i++)
    {
        printf("Enter philosopher %d position (0 to %d):", i+1, n-1);
        scanf("%d", &hungry[i]);
    }
    do {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                oneeat();
                break;
            case 2:
                twoeat();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
