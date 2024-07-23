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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
           return head;
        
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        dummy->next=head;

        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            
            if(curr->next->val!=curr->val){
                prev=curr;
                curr=curr->next;
            }else{
                 while(curr->next!=NULL && curr->next->val==curr->val)
                  curr=curr->next;
                
                prev->next=curr->next;
                curr=curr->next;
            }
        }


        return dummy->next;

    }
};