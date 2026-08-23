#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << value << " pushed into stack" << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;

    cout << temp->data << " popped from stack" << endl;

    top = top->next;

    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element is: " << top->data << endl;
    }
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* temp = top;

    cout << "Stack elements: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}