/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *Head1, ListNode *Head2) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ListNode* d1 = Head1;
    ListNode* d2 = Head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? Head2:d1->next;
        d2 = d2 == NULL? Head1:d2->next;
    }
    
    return d1;
    }
};