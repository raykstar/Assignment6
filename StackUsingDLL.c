#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct {
        struct node* top;
}stack;

struct node* create(int val){
    struct node* new= (struct node* )malloc(sizeof(struct node));
    new->data  = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

stack * push(stack *s,int val){
    struct node* new = create(val);

    new->next = s->top;
    s->top = new;
    s->top->prev = s->top;
    return s;
}

struct node* pop(stack *s){
    if(s->top==NULL) return NULL;

    struct node* temp = s->top;
    s->top = s->top->next;
    s->top->prev =NULL;

    return temp;
}

void disp(stack *s){
    struct node* temp = s->top;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }

}

int main(){
        stack* s =(stack *)malloc(sizeof(stack));
        s->top =NULL;

        while(1){
            int c=1,x;
            struct node* n = NULL;
            printf("Choice:: ");
            scanf("%d",&c);

            switch(c){
                case 1: scanf("%d",&x);
                        push(s,x);
                        disp(s);
                        break;

                case 2: n=pop(s);
                        printf("%d got deleted!\n",n->data);
                        break;

                case 3: disp(s);
                        break;

                default: printf("Invalid Choice\n\n");
                         break;
            }
        }
}
