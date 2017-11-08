#include<stdio.h>
#include<stdlib.h>

struct node{
    int data, p;
    struct node* next;
};

typedef struct{
    struct node* front;
}queue;

struct node* create(int val, int pr){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val; new->p  = pr; new->next = NULL;
    return new;
}

queue* insert(queue* q,int item, int priority)
        {
            struct node *tmp, *q_;
            tmp = create(item,priority);

            if (q->front == NULL || priority < q->front->p)
            {
                tmp->next = q->front;
                q->front = tmp;
            }
            else
            {
                q_ = q->front;
                while (q_->next != NULL && q_->next->p <= priority)
                    q_=q_->next;
                tmp->next = q_->next;
                q_->next = tmp;
            }
            return q;
        }

 void del(queue* q)
        {
            struct node *tmp;
            if(q->front == NULL)
                printf("Queue Underflow\n");
            else
            {
                tmp = q->front;
                printf("Deleted item is: %d\n",tmp->data);
                q->front = q->front->next;
                free(tmp);
            }
        }

void display(queue *q)
        {
            struct node *ptr;
            ptr = q->front;
            if (q->front == NULL)
                printf("Queue is empty\n");
            else
            {	printf("Queue is :\n");
                printf("Priority       Item\n");
                while(ptr != NULL)
                {
                    printf("%d                   %d\n",ptr->p,ptr->data);
                    ptr = ptr->next;
                }
            }
        }

int main(){
        int choice, item, priority;
   queue *q =(queue*)malloc(sizeof(queue));
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Quit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Input the item value to be added in the queue : ");
            scanf("%d",&item);
            printf("Enter its priority : ");
            scanf("%d",&priority);
            q=insert(q,item, priority);
            break;
        case 2:
            del(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            break;
        default :
            printf("Wrong choice\n");
        }
    }
    while(choice != 4);
    return 0;
}
