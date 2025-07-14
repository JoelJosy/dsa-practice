// 23. Merge K Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

// Min Heap Approach
// Time Complexity: O(N log k), where N is the total number of nodes in all lists
// Space Complexity: O(k), where k is the number of linked lists

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
    // Functor for min heap
    struct Compare {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, Compare> heap;
        ListNode temp(0);
        ListNode* curr = &temp;

        for (ListNode* listHead: lists) {
            if (listHead != nullptr) {
                heap.push(listHead);
            }
        }
        while (!heap.empty()) {
            ListNode* top = heap.top();
            curr->next = top;
            curr = curr->next;
            heap.pop();
            if (top->next != nullptr) {
                heap.push(top->next);
            }
        }

        return temp.next;
    }
};


// Divide and Conquer Approach
// Time Complexity: O(N log k), where N is the total number of nodes in all lists
// Space Complexity: O(log k), for the recursion stack , can be O(1) if iterative 

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
    ListNode* mergeTwo(ListNode* h1, ListNode* h2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val < h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }
        temp->next = h1 ? h1 : h2;
        return dummy.next;
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l==r) return lists[l];
        int mid = l + (r-l)/2;
        ListNode* list1 = divide(lists, l, mid);
        ListNode* list2 = divide(lists, mid+1, r);
        return mergeTwo(list1, list2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.empty()) return nullptr;
       return divide(lists, 0, lists.size() - 1);
    }
};