#include<stdio.h>
 
void  main()
{
  int i,n,a[100],temp;
 
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
 
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
 
    printf("Original array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
 
    /* shifting array elements */
    temp=a[0];
    for(i=0;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;
 
    printf("\nNew array after rotating by one postion in the left direction\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
