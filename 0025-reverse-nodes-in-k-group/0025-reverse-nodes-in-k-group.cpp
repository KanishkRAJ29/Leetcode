class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){return head;}
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* check=head;
        int count=0;
        for(int i=0;i<k;i++){
            if(!check)return head;
            check=check->next;
        }
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};