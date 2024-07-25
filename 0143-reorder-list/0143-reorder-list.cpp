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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* forward = NULL;

        while (current != NULL) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }

        return prev;
    }

    ListNode* find_middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge_Linked_List(ListNode* head, ListNode* head1) {
        ListNode* p1 = head;
        ListNode* temp1 = p1->next;
        ListNode* p2 = head1;
        ListNode* temp2 = p2->next;

        while (p1 != NULL && p2 != NULL) {
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;

            if (temp1 != NULL)
                temp1 = temp1->next;
            if (temp2 != NULL)
                temp2 = temp2->next;
        }

        return head;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* middle = find_middle(head);
        ListNode* head1 = middle->next;
        middle->next = NULL;
        head1 = reverse(head1);

        head = merge_Linked_List(head, head1);
    }
};
