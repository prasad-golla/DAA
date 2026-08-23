#include <iostream>
using namespace std;

#define MAX 20

int stackArr[3][MAX];
int top[3] = {-1, -1, -1};

void push(int rod, int disk)
{
    top[rod]++;
    stackArr[rod][top[rod]] = disk;
}

int pop(int rod)
{
    int disk = stackArr[rod][top[rod]];
    top[rod]--;
    return disk;
}

void moveDisk(int from, int to, char names[])
{
    int disk;

    if (top[from] == -1)
    {
        disk = pop(to);
        push(from, disk);

        cout << "Move disk " << disk << ": "
             << names[to] << " -> " << names[from] << endl;
    }
    else if (top[to] == -1)
    {
        disk = pop(from);
        push(to, disk);

        cout << "Move disk " << disk << ": "
             << names[from] << " -> " << names[to] << endl;
    }
    else if (stackArr[from][top[from]] < stackArr[to][top[to]])
    {
        disk = pop(from);
        push(to, disk);

        cout << "Move disk " << disk << ": "
             << names[from] << " -> " << names[to] << endl;
    }
    else
    {
        disk = pop(to);
        push(from, disk);

        cout << "Move disk " << disk << ": "
             << names[to] << " -> " << names[from] << endl;
    }
}

int main()
{
    int n, i;
    char names[] = {'A', 'B', 'C'};

    cout << "Enter number of disks: ";
    cin >> n;

    // Push disks onto rod A
    for (i = n; i >= 1; i--)
    {
        push(0, i);
    }

    int totalMoves = (1 << n) - 1;

    for (i = 1; i <= totalMoves; i++)
    {
        if (n % 2 == 1)
        {
            if (i % 3 == 1)
            {
                moveDisk(0, 2, names);
            }
            else if (i % 3 == 2)
            {
                moveDisk(0, 1, names);
            }
            else
            {
                moveDisk(1, 2, names);
            }
        }
        else
        {
            if (i % 3 == 1)
            {
                moveDisk(0, 1, names);
            }
            else if (i % 3 == 2)
            {
                moveDisk(0, 2, names);
            }
            else
            {
                moveDisk(1, 2, names);
            }
        }
    }

    return 0;
}