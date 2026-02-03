/*
Leetcode 2 - Add Two Numbers
Pattern: Two Pointers / Linked List Simulation / Math (Carry)

Idea:
- Traverse both linked lists simultaneously.
- Add current digits and carry.
- Create a new node with (sum % 10).
- Update carry = sum / 10.
- Continue until both lists and carry are empty.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
  
        while(l1 || l2 || carry){
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy.next;
    }
};