/*
Leetcode 24 - Swap Nodes in Pairs
Pattern: Linked List

Idea:
- Use a dummy node to handle edge cases at the head.
- For each pair (first, second), rewire the pointers to swap them.
- Move prev to first (which is now behind second) and repeat.
- Stop when less than 2 nodes remain.

Time Complexity: O(n)
Space Complexity: O(1)
*/

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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while(prev->next != nullptr && prev->next->next != nullptr){
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }
        return dummy->next;
    }
};