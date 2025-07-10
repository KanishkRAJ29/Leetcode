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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;
        int maxi=-1;
        q.push({root,0});
       
        while(!q.empty()){
            int n=q.size();
            long long l_idx=q.front().second;
            long long r_idx=q.back().second;
            
            
            for(int i=0;i<n;i++){
                auto element = q.front();
                q.pop();
                auto idx=element.second;
                 if (element.first->left)  q.push({element.first->left, (long long) 2 * idx});
                // if it has the right node, push it for the next level
                // with idx = 2 * cur_idx + 1
                if (element.first->right) q.push({element.first->right, (long long) 2 * idx + 1});
                    

            }
           maxi = max(maxi, int(r_idx - l_idx + 1));
        }
        return maxi;
    }
};