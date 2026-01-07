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
    int m = 1e9 + 7;
    long ans = 0;
    int getTotalSum(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        return root->val + getTotalSum(root->left) + getTotalSum(root->right);

    }

    int helper(TreeNode* root,int sum){

        if(root == NULL){
            return 0;
        }

        long s1 = root->val + helper(root->left,sum) + helper(root->right,sum);
        long s2 = sum - s1;
        ans = max(ans,s1*s2);
        return s1;

    }
    int maxProduct(TreeNode* root) {
        int sum = getTotalSum(root);
        helper(root,sum);
        return ans % m;
    }
};