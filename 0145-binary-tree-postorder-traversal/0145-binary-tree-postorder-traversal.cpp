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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(root);
        while (!s1.empty()) {
            int size = s1.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = s1.top();
                s1.pop();
                s2.push(node);
                if (node->left != nullptr)
                    s1.push(node->left);

                if (node->right != nullptr)
                    s1.push(node->right);
            }
        }

        while (!s2.empty()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;
    }
};

/*void postorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }*/