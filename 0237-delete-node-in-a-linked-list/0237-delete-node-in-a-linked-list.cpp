/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* n=node->next;
        ListNode* p=node;
        while(n!=NULL){
            p=node;
            node->val=n->val;
            node=node->next;
            n=n->next;
        }
        p->next=NULL;
        return;
    }
};