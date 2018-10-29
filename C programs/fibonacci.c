    #include<stdio.h> 
    int fibonacci(int);
     
    int main()
    {
      int n, i = 0, c;
      printf("Enter number of terms:");
      scanf("%d", &n);
      printf("Fibonacci series terms are:\n");
      for (c = 1; c <= n; c++)
      {
        printf("%d\t", fibonacci(i));
        i++;
      }
      printf("\n");
      return 0;
    }
     
    int fibonacci(int n)
    {
      if (n == 0 || n == 1)
        return n;
      else
        return (fibonacci(n-1) + fibonacci(n-2));
    }
