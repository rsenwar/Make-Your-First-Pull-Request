#include <stdio.h>

int main()
{
    int n, i, pf;
    printf("Number: ");
    scanf("%d", &n);
    pf = 0;
    
    for ( i = 0; i < n; i++ )
    {
        if ( (i*i == n) )
        {
            pf++;
        }
        else 
        {
            continue;
        }
    }
    if ( pf == 1 )
    {
        printf("Perfect Square.");
    }
    else
    {
        printf("Not a Perfect Square.");
    }
}