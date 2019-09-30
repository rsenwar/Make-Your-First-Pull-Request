// program to print the middle element of a singly linked list by traversing it exactly once

#include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
     
    struct node{
        int n;
        struct node *next;
    };
     
    struct node *Head=NULL;
    struct node *Tail=NULL;
    struct node * createNode(int n){
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p->n=n;
        p->next=NULL;
        return p;
    }
     
     
     
    void insert(int n){
        struct node *p=createNode(n);
        Tail->next=p;
        Tail=p;
    }
     
    int main(){
       int t,n;
       scanf("%d",&t);
       int arr[1000];
     
       while(t--){
           int a,l=0;
           char temp;
          scanf("%d%c",&a,&temp);
        
          while(temp!='\n'&&temp!='\0'){
             arr[l++]=a;
             scanf("%d%c",&a,&temp);
            
          }
          int i,k=0;
          for(i=0;i<l;i++){
          
                  if(i==0){
                       struct node *p=createNode(arr[i]);
                       Head=p;
                       Tail=p;
                  }
                insert(arr[i]);
              
          }
          struct node* t1=Head;
          struct node* t2=Head;
     
          while(t2!=NULL&&t2->next!=NULL){
              t1=t1->next;
              t2=t2->next;
              t2=t2->next;
          }
         if(k%2==0){
             t1=t1->next;
         }
          printf("%d\n",t1->n);
          Head=NULL;
          Tail=NULL;
     
       }
        return 0;
    }
