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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL & n==1))
        {
            return NULL;
        }
        
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        int n1=length-n-1;
        temp=head;
        if(n1==-1)
        {
            head=head->next;
            delete temp;
            return head;
        }
        while(n1>0)
        {
           temp=temp->next;
           n1--;
        }

        temp->next=temp->next->next;

        return head;
    }
};