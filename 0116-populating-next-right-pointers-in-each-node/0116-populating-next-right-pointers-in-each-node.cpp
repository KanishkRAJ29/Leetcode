class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;    // 1) handle empty tree

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            Node* prev = nullptr;     // reset at start of each level

            for (int i = 0; i < n; i++) {
                Node* curr = q.front(); q.pop();

                if (prev) {
                    prev->next = curr;
                }
                prev = curr;

                // 2) enqueue every child's children here, inside the loop
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // at end of level, prev->next is already null by default
        }

        return root;
    }
};
