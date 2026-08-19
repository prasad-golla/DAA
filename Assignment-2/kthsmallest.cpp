#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    int a[n];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter k: ";
    cin >> k;

    sort(a, a + n);

    cout << "Kth smallest element = " << a[k - 1];

    return 0;
}