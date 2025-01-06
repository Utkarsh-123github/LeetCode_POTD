// Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

// Examples:

// Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
// Output: True
// Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void inorder(Node* root,vector<int>&ans){
        if(root == nullptr)return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int>ans;
        inorder(root,ans);
        int i=0, j= ans.size()-1;
        while(i<j){
            if(ans[i] + ans[j] == target)return true;
            else if(ans[i] + ans[j] > target)j--;
            else i++;
        }
        return false;
        
    }
};