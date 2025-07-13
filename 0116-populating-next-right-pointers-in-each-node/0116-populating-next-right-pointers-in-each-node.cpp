/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void fill(Node* root)
    {
        if(!root) return;

        if(!root->left) return;// if this line doesnt exists and root->left is null then at next line we are acccessing root->left->next which will make no sense

        root->left->next = root->right;//due to perfect bt always right exists if left
        if(root->next)
        root->right->next = root->next->left;//if next exists then only : think!!

        fill(root->left);
        fill(root->right);
    }
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        fill(root);
        return root;
        
    }
};