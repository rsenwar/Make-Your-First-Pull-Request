#include <stdio.h>
#include <stdlib.h>
int main()
{
   int l[100],n,i,j,temp,count=0,sum=0;
   scanf("%d",&n);
   if(n < 1 || n > 100)
   {
   	exit(0);
   }
   if(n == 1 || n==2)
   {
   	printf("%d",0); 
   	exit(0);
   }
   for(i=0;i<n;i++){
            scanf("%d",&l[i]);
        }
    for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (l[i] > l[j]) 
                {
 
                    temp =  l[i];
                    l[i] = l[j];
                    l[j] = temp;
 
                }
 
            }
 
        }    
   int side = n,z=1,w=n-1;
   
   for (i = 0; i < n; ++i) 
        {
            for (j = 0; j <= w-z; ++j)
             {
                sum = sum + l[j];
             }
            
            if(sum > l[j])
            {
            	printf("%d",side);
            	exit(0);
			}
			side--; 
			if(i == n-2)   
			    printf("%d",0);  
			z = z+1;
			sum =0;     
        }
            	
 return 0;
}
