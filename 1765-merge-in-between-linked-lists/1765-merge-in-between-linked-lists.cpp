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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        
        while(a>1){
            temp=temp->next;
            a--;
        }
        ListNode* temp1=list1;
        while(b>0){
            temp1=temp1->next;
            b--;
         }
        temp->next=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }

        list2->next=temp1->next;
        temp1->next=NULL;

        return list1;
    }
};