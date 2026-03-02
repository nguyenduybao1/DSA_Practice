/*
LeetCode 19 - Remove Nth Node From End of List
Pattern: Two Pointers (Fast & Slow) - LinkedList

Idea:
- Use a dummy node before head to handle edge cases.
- Use two pointers: fast and slow.
- Move fast pointer ahead by (n + 1) steps to create a fixed gap.
- Move both fast and slow together until fast reaches the end.
- At that moment, slow is right before the node to remove.
- Adjust pointers to remove the target node.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};