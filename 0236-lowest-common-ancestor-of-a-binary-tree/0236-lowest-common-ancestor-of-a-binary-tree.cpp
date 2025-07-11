/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findt(TreeNode* root, TreeNode* t){
        if(root==NULL)return false;
        if(root==t)return true;
        return findt(root->left,t)||findt(root->right,t);

    }
    void solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans){
        if(root==NULL)return;
        if((findt(root->left,p)&&findt(root->right,q))||(findt(root->right,p)&&findt(root->left,q))){
            ans=root;
            return;
        }
        solve(root->left,p,q,ans);
        solve(root->right,p,q,ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(findt(p,q))return p;   
     if(findt(q,p))return q; 
     TreeNode* ans; 
      solve(root,p,q,ans); 
      return ans;
    }
};