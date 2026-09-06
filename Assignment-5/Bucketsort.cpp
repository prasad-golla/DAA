#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void bucketSort(vector<T>& a)
{
    int n = a.size();

    if (n <= 1)
        return;


    T minValue = *min_element(a.begin(), a.end());
    T maxValue = *max_element(a.begin(), a.end());


    if (minValue == maxValue)
        return;


    vector<vector<T>> buckets(n);

    
    for (T x : a)
    {
        int index = (int)(((x - minValue) / (maxValue - minValue)) * n);

        
        if (index == n)
            index = n - 1;

        buckets[index].push_back(x);
    }

    
    for (int i = 0; i < n; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (T x : buckets[i])
        {
            a[k++] = x;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(a);

    cout << "Sorted array: ";
    for (double x : a)
        cout << x << " ";

    return 0;
}