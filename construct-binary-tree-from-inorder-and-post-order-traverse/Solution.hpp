// LeetCode 106. Construct Binary Tree from Inorder and Postorder Traversal

#include <vector>

using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        TreeNode * root = _buildTree(inorder, postorder);

        return root; 
    }

private:

    TreeNode* _buildTree(const vector<int> & inorder, const vector<int>& postorder) { 

        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr; 
        }

        int val = postorder.back();
        TreeNode * node = new TreeNode(val);
        int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();

        vector<int> inorderLeft(inorder.begin(), inorder.begin() + idx);
        vector<int> inorderRight(inorder.begin() + idx + 1, inorder.end());

        vector<int> postorderLeft(postorder.begin(), postorder.begin() + idx);
        vector<int> postorderRight(postorder.begin() + idx, postorder.end() - 1);

        node->left = _buildTree(inorderLeft, postorderLeft);
        node->right = _buildTree(inorderRight, postorderRight); 

        return node; 
    }
};