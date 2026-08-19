#include <iostream>
using namespace std;

int main()
{
    int n;
    double a, r;

    cout << "Enter first term: ";
    cin >> a;

    cout << "Enter common ratio: ";
    cin >> r;

    cout << "Enter number of terms: ";
    cin >> n;

    double sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    cout << "Sum = " << sum;

    return 0;
}