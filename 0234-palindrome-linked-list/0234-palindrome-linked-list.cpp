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
    private:
    ListNode *getmid(ListNode* head)
    {
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
public:
     ListNode *reverseList(ListNode *head) 
{
    if(head==NULL)
    {
        return head;
    }
      ListNode *prev=NULL;
      ListNode *current=head;
      ListNode *forward;
       while(current!=NULL)
       {
         forward=current->next;
         current->next=prev;
         prev=current;
         current=forward;
       }
       head=prev;
       return head;

}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
      ListNode* mid=getmid(head);
      ListNode* temp=mid->next;
      mid->next=reverseList(temp);
     ListNode* temp1=head;
     ListNode* temp2=mid->next;
     while(temp2!=NULL)
     {
         if(temp1->val!=temp2->val)
            return false;
        
        temp2=temp2->next;
        temp1=temp1->next;
     }
    
   temp=mid->next;
      mid->next=reverseList(temp);
     return true;
        
    }
};