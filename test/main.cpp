#include <stdio.h>
#include <stdlib.h>

// this print the "queries[i] index" of the forward rotated array "arr".
int main()
{
    int n, k, q, i;
    int *arr;
    arr = (int *)malloc((n + 1) * sizeof(int));
    int queries;
    int final_index;
    scanf("%d %d %d", &n, &k, &q);
    /****INPUT*****/
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < q; i++)
    {
        scanf("%d", &queries);
        final_index = (k + queries) % n;
        printf("%d\n", arr[final_index]);
    }

    return 0;
}
