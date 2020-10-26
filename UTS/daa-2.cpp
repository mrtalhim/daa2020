#include <iostream>

int knapsack(int n, int W, int w[], int v[])
{
    if (n == 0 || W == 0)
        return 0;
    else if (w[n] > W)
        return knapsack(n - 1, W, w, v);
    else
    {
        int a = v[n] + knapsack(n - 1, W - w[n], w, v);
        int b = knapsack(n - 1, W, w, v);
        return a > b ? a : b;
    }
}

int main()
{
    int n, W;
    printf("jumlah barang dan kapasitas max: ");
    scanf("%d %d", &n, &W);
    int w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        printf("barang %d: ", i + 1);
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d\n", knapsack(n, W, w, v));
    return 0;
}