class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0){
            return head;
        }
        
        ListNode*tail=head;
        ListNode* prev=NULL;
        
        int length=1;
        while(tail->next!=NULL){
            tail=tail->next;
            length++;
        }
        k = k % length;
        tail->next=head;
      
            for(int j=0;j<length-k;j++){
                tail=tail->next;
                head=head->next;
                }
        
        tail->next=NULL;
        return head;
    }
};