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


//see alternate solution as this is bit complicated ,multiset sorts autometically

class Solution {
public:
    void traversal(map<int,vector<pair<int,int>>>&mp,TreeNode* root,int i,int j){
        if(!root)return;
        if(root->left)traversal(mp,root->left,i+1,j-1);
        mp[j].push_back({root->val,i});
        if(root->right)traversal(mp,root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
        if(!root)return result;
     map<int,vector<pair<int,int>>>mp;
     traversal(mp,root,0,0);
    
    for (const auto& entry : mp) {
        const auto& vec = entry.second;
        vector<pair<int,int>>temp;
         temp.insert(temp.end(),vec.begin(),vec.end());
           sort(temp.begin(),temp.end(),[](const auto&a,const auto&b){
         if (a.second == b.second) {
            return a.first < b.first; // If second values are the same, sort by first value
        }
        return a.second < b.second;
        });
         vector<int>temp1;
         for (const auto& p : temp) {
            temp1.push_back(p.first); // Push the second value of each pair
        }
        result.push_back(temp1);
    }
  
    return result;
    }
};