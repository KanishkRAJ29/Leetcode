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

class info {
    public:
    int ma;
    int mi;
    int sum;
    bool isBST;
};

class Solution {
public:
    info solve(TreeNode* root, int &ans){
        if (root==NULL){return{INT_MIN,INT_MAX,0,true};}
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        info currNode;
        currNode.sum=left.sum+right.sum+root->val;
        currNode.ma=max(root->val,right.ma);
        currNode.mi=min(root->val,left.mi);
        currNode.isBST=(left.isBST && right.isBST && (root->val>left.ma && root->val<right.mi));
        if (currNode.isBST){ans=max(ans,currNode.sum);}
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        info temp=solve(root,maxsum);
        return maxsum;
    }
};