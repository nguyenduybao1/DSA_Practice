/*
Leetcode 21 - Merge two sorted lists
Pattern: Linked List + TwoPointers

Idea:
- Use two pointers to compare both lists.
- Always attach the smaller node to the result list.
- Move the corresponding pointer forward.
- When one list finishes, attach the remaining nodes.


Time Complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        if(list1 != nullptr) cur->next = list1;
        else cur->next = list2;

        return dummy.next;
    }
};