#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, r;
    int n;

    cout << "Enter first term: ";
    cin >> a;

    cout << "Enter common ratio: ";
    cin >> r;

    cout << "Enter number of terms: ";
    cin >> n;

    double sum;

    if(r == 1)
    {
        sum = a * n;
    }
    else
    {
        sum = a * (pow(r, n) - 1) / (r - 1);
    }

    cout << "Sum = " << sum;

    return 0;
}