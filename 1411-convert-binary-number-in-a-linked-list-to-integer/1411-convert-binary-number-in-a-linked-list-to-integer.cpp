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
    ListNode* rev(ListNode* head){
        if(head==NULL)
           return NULL;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;
    }
    int getDecimalValue(ListNode* head) {
      head=rev(head);
      int ans=0,i=0;
      while(head!=NULL){
          ans+=head->val*pow(2,i);
          i++;
          head=head->next;
      }

      return ans;
    }
};