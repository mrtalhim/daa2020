#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int powerBruteForce(int a, int n)
{
    int x = 1;
    for (int i = 0; i < n; i++)
        x = x * a;
    return x;
}

int powerDivideAndConquer(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    if (n % 2 == 0)
        return powerDivideAndConquer(a, n / 2) * powerDivideAndConquer(a, n / 2);
    else
        return powerDivideAndConquer(a, n / 2 + 1) * powerDivideAndConquer(a, n / 2);
}

int powerDecreaseAndConquer(int a, int n)
{
    if (n == 0)
        return 1;
    return powerDecreaseAndConquer(a, n - 1) * a;
}

void repeatBruteForce(int a, int n)
{
    int x;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        x = powerBruteForce(a, i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << " ";
    return;
}

void repeatDivideAndConquer(int a, int n)
{
    int x;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        x = powerDivideAndConquer(a, i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << " ";
    return;
}

void repeatDecreaseAndConquer(int a, int n)
{
    int x;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        x = powerDecreaseAndConquer(a, i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << endl;
    return;
}

int main()
{
    int a = 2;
    int n = 512;
    for (int i = 0; i < 50; i++)
    {

        repeatBruteForce(a, n);
        repeatDivideAndConquer(a, n);
        repeatDecreaseAndConquer(a, n);
    }
}