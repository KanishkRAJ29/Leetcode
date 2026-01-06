class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }

        int maxLevel = 1;
        int maxSum = root->val; // Initialize with the root value
        int level = 1;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                levelSum += curr->val;

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }

            ++level;
        }

        return maxLevel;
    }
};