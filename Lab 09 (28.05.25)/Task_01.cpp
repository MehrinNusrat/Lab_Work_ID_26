#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left , *right;

    Node(char c , int f) : ch(c) , freq(f) , left(nullptr) , right(nullptr) {}
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code)
{
    if(!root)
    {
        return;
    }

    if(!root->left && !root->right)
    {
        cout << root->ch << ": " << code << '\n';
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanCoding(unordered_map<char, int>& freqMap)
{
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* combined = new Node('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;

        pq.push(combined);
    }

    Node* root = pq.top();
    printCodes(root, "");
}

int main()
{
    unordered_map<char, int> freqMap = {
            {'a', 5}, {'b', 9}, {'c', 12},
            {'d', 13}, {'e', 16}, {'f', 45}
        };

    huffmanCoding(freqMap);
    return 0;
}
