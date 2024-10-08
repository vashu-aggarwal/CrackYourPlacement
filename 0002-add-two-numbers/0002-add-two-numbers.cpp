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

    ListNode* rev(ListNode* head)
    {
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* forward;
        while(current!=NULL)
        {
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
    void insertAtTail(ListNode* &head, ListNode* &tail,int data)
    {
        ListNode* temp=new ListNode(data);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;

        } 
        tail->next=temp;
        tail=temp;
    }
     ListNode* add(ListNode* l1, ListNode* l2){
       
       int carry=0;
       ListNode *head=NULL;
       ListNode *tail=NULL;

       while(l1!=NULL || l2!=NULL || carry!=0)
       {
           int val1=0;
           if(l1!=NULL)
           {
               val1=l1->val;
           }
          int val2=0;
          if(l2!=NULL)
          {
              val2=l2->val;
          }
       int sum = val1+val2+carry;
        
        int digit=sum%10;
        insertAtTail(head,tail,digit);
        carry=sum/10;
        if(l1!=NULL)
        {

        l1=l1->next;
        }
        if(l2!=NULL)
          {

        l2=l2->next;
          }
     }

     
     return head;

}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=rev(l1);
        // l2=rev(l2);
       
       ListNode* ans= add(l1,l2);
       return ans;
    }
};