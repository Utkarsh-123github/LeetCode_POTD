// Kth smallest element in a BST

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Optimal Approach
class Solution{

    int count = 0, result = -1;

    void inOrder(Node* root, int k) {
        if (root == nullptr || count >= k) return;

        // Left subtree
        inOrder(root->left, k);

        // Process current node
        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        // Right subtree
        inOrder(root->right, k);
    }

    int kthSmallest(Node* root, int k) {
        count = 0;
        result = -1;
        inOrder(root, k);
        return result;
    }
};