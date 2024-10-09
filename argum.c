#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int sum = 0;

    int *a = (int*)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for(int i = 1; i <= n; i++) {
        a[i-1] = i * i;
         printf("%d %d\n", i, a[i-1]);
        sum += a[i-1];
    }

    end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of %d squares is %d\n", n, sum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Free the dynamically allocated memory
    free(a);


    return 0;
}