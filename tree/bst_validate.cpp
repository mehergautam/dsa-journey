#include <iostream>
#include <climits>
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

bool isValidBST(Node* root, long minVal, long maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    if (isValidBST(root, LONG_MIN, LONG_MAX))
        cout << "Valid BST";
    else
        cout << "Not a BST";

    return 0;
}
