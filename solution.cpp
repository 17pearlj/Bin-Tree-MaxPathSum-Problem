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
    vector<int> maxPathSumH(TreeNode* root) {
        if (!root) { 
            vector<int> v = {INT_MIN, INT_MIN};
            return v;
        }
        vector<int> left = maxPathSumH(root->left);
        vector<int> right = maxPathSumH(root->right);
        vector<int> me = {root->val + max(0,max(left[0], right[0])), max(left[1], right[1])};
        me[1] = max(me[1], root->val + max(0, left[0]) + max(0, right[0]));
        return me;
    }
    int maxPathSum(TreeNode* root) {
        vector<int> sol = maxPathSumH(root);
        return max(sol[0], sol[1]);
        

    }
};
