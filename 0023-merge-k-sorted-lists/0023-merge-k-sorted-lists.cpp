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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare=[](ListNode*a,ListNode*b){
        return a->val>b->val;
    };
        priority_queue<ListNode*, vector<ListNode*>,decltype(compare) > pq(compare);

        for(int i=0; i<lists.size(); i++){
            ListNode* listHead= lists[i];
            if(listHead!=NULL){
              pq.push(listHead);  
            }
           }
         
         ListNode* head= NULL;
         ListNode* tail= NULL;
        while(!pq.empty()){
            ListNode* topNode= pq.top();
            pq.pop();

        if(head==NULL){
            head= topNode;
            tail= topNode;

            if(topNode->next!=NULL){
                pq.push(topNode->next);
            }
            }
            else{
                tail->next= topNode;
                tail= topNode;
                if(topNode->next!=NULL){
                pq.push(topNode->next);
            }
            }
         }
        return head;
    }
};/*
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<=l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2; 
        }
        return NULL;
    }
    ListNode* partition(int start,int end,vector<ListNode*>& lists){
        if(start==end)return lists[start];
        int mid=start+(end-start)/2;
        ListNode* l1=partition(start,mid,lists);
        ListNode* l2=partition(mid+1,end,lists);
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
      return  partition(0,lists.size()-1,lists);
    }
};*/