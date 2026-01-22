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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> seen;
        for (int num: nums) {
            if (!seen.count(num)) seen.insert(num);
        }

        ListNode dummy(0, head);
        ListNode* temp = &dummy;
        while (temp->next) {
            int val = temp->next->val;
            if (seen.count(val)) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};