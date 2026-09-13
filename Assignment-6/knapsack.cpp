#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity == 0) break;

        if (item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            capacity = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum value = " << totalValue << '\n';
}