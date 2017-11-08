#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {

    int qu[MAX];
    int front;
    int rear;
    int count;
}q;

int isEmpty(q* q1){
    if(q1->front > q1->rear){
        return 1;
    }
    else if(q1->front ==-1 && q1->rear == -1){
        return 1;
    }
    return 0;
}

int isFull(q *q1){
    if(q1->rear==MAX){
        return 1;
    }
    return 0;
}

void enq(q *q1,int val){

    if(!isFull(q1)){
        if(isEmpty(q1)){
        q1->front++;
    }
        q1->qu[++q1->rear] = val;
        q1->count++;
    }
    else{
        printf("FULL\n");
    }
}

int deq(q *q1){
    int x;
    if(isEmpty(q1)){
        printf("EMPTY\n");
        return -1;
    }
    else{
        x = q1->qu[q1->front];
        q1->front++;
        q1->count--;
    }

    if(isEmpty(q1)){
        q1->front =-1;
        q1->rear =-1;
    }
    return x;
}
void disp(q *q1){
    int i;
    for(i=q1->front;i<q1->rear;i++){
        printf("%d  ",q1->qu[i]);
    }
    printf("%d\n",q1->qu[q1->rear]);
}

int main(){
    q *q1=(q*)malloc(sizeof(q));
    q1->front =-1;
    q1->rear =-1;
    q1->count =0;
    printf("Enter \n1 to Insert\n2 to Delete\n3 to Display\n");
    while(1){
        printf("Your choice:: ");
        int ch; int val;
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&val);
                    enq(q1,val);
                    disp(q1);
                    break;

         case 2:val = deq(q1);
                printf("%d got delete!\n",val);
                break;

            case 3:disp(q1);
                   break;

            default: printf("Enter a valid choice:: \n");
                     break;
        }
    }
}
