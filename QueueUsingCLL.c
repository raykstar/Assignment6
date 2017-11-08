#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct {
        struct node* front, *rear;
}queue;

struct node* create(int val){
    struct node* new= (struct node* )malloc(sizeof(struct node));
    new->data  = val;
    new->next = NULL;
    return new;
}

queue * enq(queue *q,int val){
    struct node* new = create(val);
    if(q->rear == NULL){
        q->rear = q->front = new;
    }
    else{
        q->rear->next = new;
        q->rear = new;
        new->next = q->front;
    }
    return q;
}

struct node* deq(queue *q){
    if(q->front==NULL) return NULL;

    struct node* temp = q->front;
    q->front = q->front->next;
    q->rear->next = q->front;
    if(q->front == NULL) q->rear =NULL;

    return temp;
}

void disp(queue* q){
    struct node* temp = q->front;
    while(temp!=q->rear){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("%d\n\n",temp->data);

}



int main(){
        queue *q =(queue *)malloc(sizeof(queue));
        q->front =NULL;
        q->rear =NULL;

        while(1){
            int c=1,x;
            struct node* n = NULL;
            printf("Choice:: ");
            scanf("%d",&c);

            switch(c){
                case 1: scanf("%d",&x);
                        enq(q,x);
                        disp(q);
                        break;

                case 2: n=deq(q);
                        printf("%d got deleted!\n",n->data);
                        break;

                case 3: disp(q);
                        break;



                default: printf("Invalid Choice\n\n");
                         break;
            }
        }
}
