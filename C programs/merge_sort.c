#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge_sort(long long int *a,long long int left,long long int right,long long int middle);
void merge(long long int *a,long long int left,long long int right);
int main()

{       clock_t begin,finish;
  	double time_taken;
	long long int k,i,j,*a,left,right,n;
	//printf("enter the no. of elements\n");
	srand(time(0));
	//scanf("%lld",&n);
	for(n=100;n<=100000;n=n+100)
	{
	a=(long long int*) malloc(n*sizeof(long long int));
	for(i=0;i<n;i++)
	{
	{  k=rand()%n;
          *(a+i)=k;
          // printf("%lld \n",k);
	}
	//printf("x");
	//scanf("%lld",(a+i));
	}
	//printf("1");
	begin=clock();
	left=0;
	right=n-1;
//middle=left+((right-left)/2);
	merge(a,left,right);
	finish=clock();
	/*	for(j=0;j<n;j++)
	{
		printf("%lld\t",*(a+j));
	}*/
	time_taken=((double)(finish-begin)/CLOCKS_PER_SEC);
        printf("the time taken by the code to execute for %d is %f\n",n,time_taken);
	}
return 0;
}
void merge_sort(long long int *a,long long int left,long long int right,long long int middle)

{
	long long int i,j,k,m1,m2;
	m1=(middle-left)+1;
	m2=(right-middle);
        long long int l[m1];
        long long int r[m2];
        for(i=0;i<m1;i++)
	{ 
	  l[i]= *(a+i+left);
	}
 	for(j=0;j<m2;j++)
	{
	  r[j]= *(a+middle+1+j);
	}
	i=0;
	j=0;
	k=left;
        while(i<m1 && j<m2)
	{
	    if(l[i]<=r[j])
	     { 
             *(a+k)=l[i];
	       i++;
	     }
           else
             {
	      *(a+k)=r[j];
	      j++;
             }
           k++;
        }
	while(i<m1)
 	   {
            *(a+k)=l[i];
            i++;
	    k++;
	   }
        
	while(j<m2)
  	   {
            *(a+k)=r[j];
	     j++;
	     k++;
	   }
       
 }
void merge(long long int *a,long long int left,long long int right)
{     if(left>=right) return;
	if(1)
	{
         long long int middle;
	 middle=((right+left)/2);
	 merge(a,left,middle);
	 merge(a,middle+1,right);
	 merge_sort(a,left,right,middle);
	}        
 
 }




