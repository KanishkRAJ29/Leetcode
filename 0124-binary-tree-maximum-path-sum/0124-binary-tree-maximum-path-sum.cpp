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
    int maxSum;
    int solve(TreeNode* root) {
        if(root==NULL)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int koi_ek_acha=root->val+max(l,r);
        int neeche_ans_hai=root->val+l+r;
        int only_root=root->val;
        maxSum=max({maxSum,koi_ek_acha,neeche_ans_hai,only_root});
        return max({koi_ek_acha,only_root});
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};