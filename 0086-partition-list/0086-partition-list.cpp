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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
        return NULL;

        ListNode* greater=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* greaterprev=dummy;
        
        ListNode* itr=NULL;
        while(greater!=NULL &&greater->val<x){
            
            greaterprev=greater;
            greater=greater->next;
        }

        itr=greater;

        while(itr!=NULL && itr->next!=NULL){
            if(itr->next->val<x){
                greaterprev->next=itr->next;
                greaterprev=greaterprev->next;
                itr->next=itr->next->next;
            }
            else{
                itr=itr->next;
            }
        }

        greaterprev->next=greater;       
        return dummy->next;;
    }
};