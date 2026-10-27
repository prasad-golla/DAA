#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};

void printCodes(Node* root, string code) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << code << '\n';
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    cout << "Enter character and frequency:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        minHeap.push(new Node(ch, freq));
    }

   
    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    Node* root = minHeap.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}