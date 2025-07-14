/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }
        len--;
        int power=pow(2,len);
        curr=head;
        int num=0;
        while(curr!=NULL){
            num+=(curr->val)*power;
            power/=2;
            curr=curr->next;
        }
        return num;

    }
};