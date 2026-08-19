#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}


Node* findMin(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}


Node* deleteNode(Node* root, int value)
{
    if(root == NULL)
    {
        return root;
    }

    if(value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        
        if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int n, value, del;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "BST inorder: ";
    inorder(root);

    cout << "\nEnter element to insert: ";
    cin >> value;

    root = insert(root, value);

    cout << "After insertion: ";
    inorder(root);

    cout << "\nEnter element to delete: ";
    cin >> del;

    root = deleteNode(root, del);

    cout << "After deletion: ";
    inorder(root);

    return 0;
}