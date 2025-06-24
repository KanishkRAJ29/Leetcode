/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *//*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1=headA;
        ListNode* p2=headB;
        while(p1->next!=NULL){
            p1=p1->next;
        }
        while(p2->next!=NULL){
            p2=p2->next;
        }
        if(p1!=p2)return NULL;
        p1=headA;
        p2=headB;
        while(p1!=p2){
            if(p1->next==NULL){
                p1=headA;
            }else{
            p1=p1->next;

            }
            if(p2->next==NULL){
                p2=headB;
            }else{
            p2=p2->next;

            }
        }
        return p1;
    }
};*//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int lenA = 0;
        int lenB = 0;

        while(tempA){
            lenA++;
            tempA = tempA->next;
        }

        while(tempB){
            lenB++;
            tempB = tempB->next;
        }

        int c = 0;
        tempA = headA;
        tempB = headB;
        if(lenA > lenB){
            //shift tempA
            c = lenA - lenB;
            while(c>0){
                tempA = tempA->next;
                c = c-1;
            }
        }
        else if(lenA < lenB){
            //shift tempB
            c = lenB - lenA;
            while(c>0){
                tempB = tempB->next;
                c = c-1;
            }
        }

        while( (tempA != nullptr)  &&  (tempB != nullptr) ){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;

        }

        return nullptr;

    }
};