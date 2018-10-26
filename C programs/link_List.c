#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *ptr;
};

void InsertAtFront(struct Node **h,int val){
    struct Node* NewNode;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->value=val;
    if(*h == NULL){
        NewNode->ptr = *h;
        *h = NewNode;
    }else{
        NewNode->ptr = *h ;
        *h = NewNode;
        }
}

void InsertAtEnd(struct Node **h,int val){
    struct Node *NewNode,*temp;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->value = val;
    temp = *h;
    if(*h == NULL){
        *h = NewNode;
        NewNode->ptr = NULL;
    }else{
    while(temp->ptr != NULL)
        temp = temp->ptr;

        temp->ptr = NewNode;
        NewNode->ptr = NULL;
    }
}

void InsertAtOrder(struct Node **h,int val){
    struct Node *NewNode,*temp;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->value = val;
    temp = *h;
    if(*h == NULL){
        *h = NewNode;
        NewNode->ptr = NULL;
    }else if(temp->value >= val ){
        InsertAtFront(h,val);
    }
    else{
        while(temp->ptr->value <= val){
            temp = temp->ptr;
            if(temp->ptr == NULL)
                break;
        }
        if(temp->ptr == NULL){
            InsertAtEnd(h,val);
        }else{
        NewNode->ptr = temp->ptr;
        temp->ptr = NewNode;
        }
    }

}

void ReverseLinklist(struct Node **h){
    struct Node *temp_current, *NEXT, *PREVOUS;
    temp_current = *h;
    PREVOUS = NULL;
    while(temp_current != NULL){
        NEXT = temp_current->ptr;
        temp_current->ptr = PREVOUS;
        PREVOUS = temp_current;
        temp_current = NEXT;
    }
    *h = PREVOUS;
}

void DELETE(struct Node **h){
    struct Node *temp,*NodetoBeDeleted;
    temp = *h;
    if(temp == NULL)printf("\nsorry, Link list is empty.\n");
    else if(temp->ptr == NULL){
        NodetoBeDeleted = temp;
        free(NodetoBeDeleted);
    }else{
        printf("Enter your choice:\n1 for Delete at first\n2 for delete at last\n3 for delete specific value");
        int n;
        scanf("%d",&n);
        if(n == 1){
            NodetoBeDeleted = temp;
            temp = temp->ptr;
            (*h) = temp;
            free(NodetoBeDeleted);
        }else if(n == 2){
            while(temp->ptr->ptr != NULl)    temp = temp->ptr;
                free(temp->ptr);
                temp->ptr = NULL;
        }else if(n == 3){
            printf("\nenter specific value you want to delete:");
            int val;
            scanf("%d",&val);
            while(temp->ptr->value != val)
                temp = temp->ptr;
                NodetoBeDeleted = temp->ptr;
                temp->ptr = temp->ptr->ptr;
                free(NodetoBeDeleted);
        }
    }
}

void a_shorting(struct Node **h){
    struct Node *temp,*i,*j;
    int n=1
    temp = *h;
    while(temp != NULL){
        temp = temp->ptr;
        n++;
    }
    while(i != NULL){
        while(j != NULL){
            if((temp->value) >= (temp->ptr->value) ){

            }
        }
    }

}


void Display(struct Node**h){
    struct Node *temp;
    temp = *h;
    if(temp == NULL) printf("\n Ops!!! link list is null \n");
    else {while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->ptr;
    }
    }
}


int main(){
    struct Node *HEAD;
    int n,val;
    HEAD = NULL;
    printf("1 for insert value at front:\n");
    printf("2 for insert value at rear:\n");
    printf("3 for insert value according to order:\n");
    printf("4 for insert value after specific value:\n");
    printf("5 for reverse Linklist\n");
    printf("6 for display the list\n");
    printf("7 for Exit\n");
    scanf("%d",&n);

    while(n !=7){

        switch(n){
        case 1:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            InsertAtFront(&HEAD,val);
            break;
        case 2:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            InsertAtEnd(&HEAD,val);
            break;
        case 3:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            InsertAtOrder(&HEAD,val);
            break;
        case 4:
            printf("Enter the value you want to insert:\n");
           // scanf("%d",&val);
            printf("Enter after which value you want to insert:\n");
           // scanf("%d",&sval);
           // insert_specs(&Head,&Rear,val,sval);
            break;
        case 5:
            ReverseLinklist(&HEAD);
            break;
        case 6:
            Display(&HEAD);
            break;
        default:
            printf("Enter specific value:\n");
        }

        printf("\n Enter which type of the operation you want to apply:  ");
        scanf("%d",&n);
    }
    return 0;

}
