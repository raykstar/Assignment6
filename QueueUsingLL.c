queue * enq(queue *q,int val){
    struct node* new = create(val);
    if(q->rear == NULL){
        q->rear = q->front = new;
    }
    else{
        q->rear->next = new;
        q->rear = new;
    }
    return q;
}

struct node* deq(queue *q){
    if(q->front==NULL) return NULL;

    struct node* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL) q->rear =NULL;

    return temp;
}

void disp(queue* q){
    struct node* temp = q->front;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }

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
