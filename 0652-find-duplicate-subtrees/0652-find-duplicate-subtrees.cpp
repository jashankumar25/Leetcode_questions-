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
    string duplicates(TreeNode* root, unordered_map<string, int>& mapp,
                      vector<TreeNode*>& result) {
        
        if (!root)
            return "#";
        
       
        string leftstr = duplicates(root->left, mapp, result);
        string rightstr = duplicates(root->right, mapp, result);
        
        string curr_str = to_string(root->val) + "," + leftstr + "," + rightstr;

        if (mapp[curr_str] == 1) {
            result.push_back(root);
        }
        
        mapp[curr_str]++;
        
        return curr_str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mapp; 
        vector<TreeNode*> result;        

        duplicates(root, mapp, result);
        
        return result;
    }
};

/*==========================================
Base Case: Agar node NULL hai, toh '#' return karo
         Step 1: Left aur Right subtree ko recursively serialize karo
         Step 2: Current subtree ka unique string representation banao (Root, Left, Right)
         Step 3: Check karo ki kya yeh subtree pehle exact 1 baar aa chuka hai
                Agar frequency 1 hai, iska matlab duplicate mil gaya hai toh result mein add kar lo
         Step 4: Map mein current subtree ki frequency ko increment kar do
                 Current subtree ka string return karo parent nodes ke liye
 ==========================================*/
// Time Complexity: O(N) or O(N * H) due to string serialization
// Space Complexity: O(N) for hash map and recursion stack