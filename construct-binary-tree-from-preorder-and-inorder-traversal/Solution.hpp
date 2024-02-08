// LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
            return nullptr; 
        }

        TreeNode * root = _buildTree(preorder, inorder); 

        return root; 
    }

private:
    TreeNode * _buildTree(const vector<int> & preorder, const vector<int> & inorder) {
        
        /**
         * The 0th element in preorder is always the root
         * 
         * The index of (0th elemtn in preorder) in the inorder split the inorder
         * into two parts: sub-tree on the left and sub-tree on the right
         * 
         * With the subtree from inorder, we can divide preorder into 2 parts:
         * preorder of left subtree and preorder of right subtree
         */


        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }

        int val = preorder[0];
        TreeNode * node = new TreeNode(val);
        int idxRoot = find(inorder.begin(), inorder.end(), val) - inorder.begin();

        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + idxRoot + 1);
        vector<int> preorderRight(preorder.begin() + idxRoot + 1, preorder.end());

        vector<int> inorderLeft(inorder.begin(), inorder.begin() + idxRoot);
        vector<int> inorderRight(inorder.begin() + idxRoot + 1, inorder.end());

        node->left = _buildTree(preorderLeft, inorderLeft);
        node->right = _buildTree(preorderRight, inorderRight); 

        return node; 
    }
};