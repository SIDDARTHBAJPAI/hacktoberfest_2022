#include <stdio.h>
#include <stdlib.h>

struct set{
    int profit, weight;
};

typedef struct set set;

int minIndex(set *arr, int *visited, int n)
{
    int min = 0, i;
    double minVal = (double)arr[0].weight/(double)arr[0].profit;
    for(i = 1 ; i < n ; i++)
    {
        double temp = (double)arr[i].weight/(double)arr[i].profit;
        if(temp < minVal && !visited[i])
        {
            minVal = temp;
            min = i;
        }
    }
    return min;
}

void knapsack(set *arr, int n, int capacity)
{
    int *visited = (int*)calloc(n, sizeof(int));
    int u = capacity, total = 0;
    while(u > 0)
    {
        int i = minIndex(arr, visited, n);
        if(arr[i].weight > u)
            break;
        visited[i] = 1;
        total += arr[i].profit;
        u -= arr[i].weight;
    }
    printf("\nTotal profit is %d", total);
}

int main()
{
    int n;
    printf("\nEnter total number of elements: ");
    scanf("%d", &n);
    set *arr = (set*)malloc(n*sizeof(set));
    for(int i = 0 ; i < n ; i++)
    {
        printf("\nEnter the profit: ");
        scanf("%d", &arr[i].profit);
        printf("\nEnter the weight: ");
        scanf("%d", &arr[i].weight);
    }
    int w;
    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &w);
    knapsack(arr, n, w);
    return 0;
}