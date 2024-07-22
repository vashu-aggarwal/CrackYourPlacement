class Solution {
public:
    ListNode* rev(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while (left <= right) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            left++;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* Leftprev = dummy;
        
        for (int i = 1; i < left; ++i) {
            Leftprev = Leftprev->next;
        }
        
       
        ListNode* leftNode = Leftprev->next;
       
        ListNode* rightNext = leftNode;
        for (int i = left; i <= right; ++i) {
            rightNext = rightNext->next;
        }
        
        
        ListNode* newHead = rev(leftNode, 1, right - left + 1);
        
        Leftprev->next = newHead;
        leftNode->next = rightNext;
        
        return dummy->next;
    }
};
