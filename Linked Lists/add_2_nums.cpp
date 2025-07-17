// Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 == nullptr) ? 0 : l1->val;
            int v2 = (l2 == nullptr) ? 0 : l2->val;

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = (l1 == nullptr) ? l1 : l1->next;
            l2 = (l2 == nullptr) ? l2 : l2->next;
        }

        return dummy->next;
    }
};