// LeetCode 226 Invert Binary Tree

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
    TreeNode* invertTree(TreeNode* root) {

        root = _invertTree(root);

        return root; 
    }

    TreeNode * _invertTree(TreeNode * node) {

        if (node == nullptr) {
            return node; 
        }

        TreeNode * rightNode = node->right;
        TreeNode * leftNode = node->left;

        if (rightNode) {
            node->left = _invertTree(rightNode);
        }
        else {
            node->left = nullptr; 
        }
        
        if (leftNode) {
            node->right = _invertTree(leftNode);
        }
        else {
            node->right = nullptr; 
        }

        return node; 
    }
};