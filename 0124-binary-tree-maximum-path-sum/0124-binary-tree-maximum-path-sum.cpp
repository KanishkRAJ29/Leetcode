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
int solve(TreeNode* root,int &maxi){
    if(root==NULL)return 0;

    int leftMax=solve(root->left,maxi);
    int rightMax=solve(root->right,maxi);
    maxi=max(maxi,root->val);
    int m=max(leftMax,rightMax);
    maxi=max(maxi,leftMax+rightMax+root->val);
    maxi=max(m+root->val,maxi);
    return max(root->val,m+root->val);
}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int x=solve(root,maxi);
        return maxi;
    }
};