#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    unsigned int maxIndex = 100000;
    unsigned int data[maxIndex];

    cout << "generating data..." << endl;
    for (int i = 0; i < maxIndex; i++)
    {
        data[i] = rand() % maxIndex;
    }
    cout << "done!" << endl;

    cout << "sorting..." << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < maxIndex; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < maxIndex; j++)
            if (data[minIndex] > data[j])
                minIndex = j;

        unsigned int tmp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = tmp;
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << ":" << duration.count() << endl;
}