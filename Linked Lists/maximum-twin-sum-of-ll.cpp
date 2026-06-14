// T: O(n)
// s: O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // start of reversed second half is now at prev

        ListNode* first = head;
        int res = INT_MIN;
        while (prev) {
            res = max(res, first->val + prev->val);
            first = first->next;
            prev=prev->next;
        }
        return res;
    }
};