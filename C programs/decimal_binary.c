#include<stdio.h>

void main(){
    int temp,j,n,i=0,ans[15]={};

    printf("Enter the number you want to convert to binary:\n");
    scanf("%d",&n);

    while(n!=0){
        temp = n%2;
        ans[i++]=temp;
        n=n/2;
    }

    for(j=i-1;j>=0;j--){
        printf("%d",ans[j]);
    }

}
