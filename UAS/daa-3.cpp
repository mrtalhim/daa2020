#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int totalObject = 4, knapsackCapacity = 16, bestWeight = 0, bestValue = 0;
    int bestChoice[totalObject];
    int currentChoice[] = {0, 0, 0, 0};
    int weight[] = {2, 5, 10, 5};
    int profit[] = {2000, 3000, 5000, 100};

    for (int i = 0; i < 16; i++)
    {
        int tempWeight = 0, tempValue = 0;
        int d = i;
        int tmp = 0;

        while (d > 0)
        {
            currentChoice[tmp] = d % 2;
            d = d / 2;
            tmp++;
        }

        for (int k = 0; k < totalObject; k++)
        {
            if (currentChoice[k] != 0)
            {
                tempWeight = tempWeight + weight[k];
                tempValue = tempValue + profit[k];
            }
        }

        if ((tempValue > bestValue) && (tempWeight <= knapsackCapacity))
        {

            bestValue = tempValue;
            bestWeight = tempWeight;
            for (int x = 0; x < totalObject; x++)
                bestChoice[x] = currentChoice[x];
        }
    }

    for (int i = 0; i < totalObject; i++)
    {
        cout << bestChoice[i] << " ";
    }
}