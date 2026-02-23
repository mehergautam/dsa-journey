#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int checkHeight(Node* root) {
    if (root == NULL) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;

    int right = checkHeight(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    if (isBalanced(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is Not Balanced";

    return 0;
}
