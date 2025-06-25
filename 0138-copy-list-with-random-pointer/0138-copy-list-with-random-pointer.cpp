class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert cloned nodes in between original nodes
        Node* curr = head;
        while (curr) {
            Node* newnode = new Node(curr->val);
            newnode->next = curr->next;
            curr->next = newnode;
            curr = newnode->next;
        }

        // 2. Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Separate the original and cloned list
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copy->next)
                copy->next = copy->next->next;
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};
