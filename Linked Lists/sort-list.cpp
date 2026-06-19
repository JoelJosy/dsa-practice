// T: O(nlogn)
// S: O(logn)

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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }

        temp->next = (h1) ? h1 : h2;
        return dummy.next;
    }

    ListNode* divide(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cut first half end
        prev->next = nullptr;

        // slow is head of second half
        ListNode* first = divide(head);
        ListNode* sec = divide(slow);

        return merge(first, sec);
    }

    ListNode* sortList(ListNode* head) {
        return divide(head;)
    }
};