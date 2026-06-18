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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* first = head;

        while (first) {
            ListNode* sec = first->next;
            if (!sec) break;

            ListNode* next = sec->next;
            first->next = next;
            sec->next = first;
            prev->next = sec;

            prev = first;
            first = next;
        }

        return dummy.next;
    }
};