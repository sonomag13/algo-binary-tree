// LeetCode 129. Sum Root to Leaf Numbers

#include <vector>
#include <numeric>

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
    int sumNumbers(TreeNode* root) {

        _traverseTree(root, 0);

        int sum = accumulate(nums.begin(), nums.end(), 0);

        return sum; 
    }

private:

    vector<int> nums; 

    void _traverseTree(TreeNode * node, int val) {

        val = val * 10 + node->val; 

        if (node->left == nullptr && node->right == nullptr) {
            nums.push_back(val); 
            return; 
        }

        if (node->left != nullptr) {
            _traverseTree(node->left, val);
        }

        if (node->right != nullptr) {
            _traverseTree(node->right, val);
        }
    }

};