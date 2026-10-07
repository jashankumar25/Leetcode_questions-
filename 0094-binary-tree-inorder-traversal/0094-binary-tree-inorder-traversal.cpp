/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> s;
        TreeNode * curr=root;
        while(!s.empty() || curr!=nullptr)//Traversal
        {
           while(curr!=nullptr)//Current node se leftmost node tak pahunchata hai.
           {
            s.push(curr);
            curr=curr->left;
           }
           curr=s.top();
           s.pop();
           ans.push_back(curr->val);
           curr=curr->right;
        }
        return ans;
    }
};
/*   void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }*/