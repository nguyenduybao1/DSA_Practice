/*
Leetcode 206 - Reverse linked list
Pattern: Linked List + Iterative Pointer Manipulation

Idea:
- Traverse the list and reverse pointers one by one.
- Keep three pointers: prev, cur, next.
- At each step:
  - save next
  - reverse current pointer
  - move forward
- Return prev as new head.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur; 
            cur = nxt;
        }
        return prev;
    }
};