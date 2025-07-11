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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
        bool right=true;
        while(!q.empty()){
            int j=q.size();
            vector<int>temp(j);
            for(int i=0;i<j;i++){
                TreeNode* node=q.front();
                q.pop();
                if(right)temp[i]=node->val;
                else{temp[j-i-1]=node->val;}
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            right=!right;
            result.push_back(temp);
        }
        return result;
    }
};