#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct {
        struct node* top;
        struct node* last;
}stack;

struct node* create(int val){
    struct node* new= (struct node* )malloc(sizeof(struct node));
    new->data  = val;
    new->next = NULL;
    return new;
}

struct node* isEmpty(stack* s){
    return s->top;
}


stack * push(stack *s,int val){
    struct node* new = create(val);
    if(!isEmpty(s)){
        s->top=new;
        s->last=new;
        new->next = s->top;
    }
    else{
        new->next = s->top;
        s->top = new;
        s->last->next = new;
    }

    return s;
}

struct node* pop(stack *s){
    if(s->top==NULL) return NULL;

    struct node* temp = s->top;
    s->top = s->top->next;
    s->last->next = s->top;

    return temp;
}


void disp(stack *s){
    struct node* temp = s->top;
    while(temp->next!=s->top){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("%d --> %d ...",temp->data,temp->next->data);
}

int main(){
        stack* s =(stack *)malloc(sizeof(stack));
        s->top =NULL; s->last = NULL;

        while(1){
            int c=1,x;
            //struct node* n = NULL;
            printf("Choice:: ");
            scanf("%d",&c);

            switch(c){
                case 1: scanf("%d",&x);
                        push(s,x);
                        disp(s);
                        break;

                case 2: //n=pop(s);
                        printf("%d got deleted!\n",pop(s)->data);
                        break;

                case 3: disp(s);
                        break;

                case 4: if(isEmpty(s))
                            printf("Is not Empty\n");
                        else printf("Is Empty\n");
                        break;

                default: printf("Invalid Choice\n\n");
                         break;
            }
        }
}
