// Cleaner soln:
// T: O(n)
// O: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        ListNode* prestart = prev;
        ListNode* start = curr;

        ListNode* prev_node = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev_node;
            prev_node = curr;
            curr = next;
        }

        prestart->next = prev_node;
        start->next = curr;

        return dummy.next;
    }
};

// My soln:
// T: O(n)
// O: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy = ListNode(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // save for later
        ListNode* prestart = prev;
        ListNode* start = curr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        start->next = curr;
        prestart->next = prev;
        
        return dummy.next;
    }
};