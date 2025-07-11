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
    int solve(TreeNode* root,int height){
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return height;
        }
        return max(solve(root->left,height+1),solve(root->right,height+1));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return 1+solve(root,0);
    }
};