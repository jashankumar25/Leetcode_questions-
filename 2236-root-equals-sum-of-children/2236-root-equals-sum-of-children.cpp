/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        int left_data = 0, right_data = 0;
        if (root == nullptr || root->left == nullptr && root->right == nullptr)
            return true;

        else {
            if (root->left != nullptr)
                left_data = root->left->val;

            if (root->right != nullptr)
                right_data = root->right->val;

            if (root->val == left_data + right_data && checkTree(root->left) &&
                checkTree(root->right))
                return true;

            return false;
        }
    }
};