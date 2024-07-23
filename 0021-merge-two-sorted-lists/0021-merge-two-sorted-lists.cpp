/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     ListNode *next;
 *     ListNode() : data(0), next(nullptr) {}
 *     ListNode(int x) : data(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : data(x), next(next) {}
 * };
 */
class Solution {
public:

 ListNode* solve( ListNode* first,  ListNode* second){

    ListNode* curr1=first;
    ListNode* curr2=second;
     ListNode* next1=curr1->next;
     ListNode* next2=curr2->next;
      if(curr1->next==NULL)
         {
               curr1->next=curr2;
                return first;
         }
 
    while(next1!=NULL && curr2!=NULL)
    {
       if(curr2->val >=curr1->val && curr2->val <=next1->val)
       {
           curr1->next=curr2;
           next2=curr2->next;
           curr2->next=next1;


           curr1=curr2;
           curr2=next2;
       }
       else{
           curr1=next1;
           next1=next1->next;
           if(next1==NULL)
           {
               curr1->next=curr2;
               return first;
           }
       }
       
    }
    return first;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
      return list2;
    if(list2==NULL)
    {
        return list1;
    }
   if(list1->val <= list2->val)
{
    return solve(list1, list2);
} else {
    return solve(list2, list1); // Fixed typo here
}
    }
};