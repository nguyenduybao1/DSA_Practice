/*
Leetcode 202 - Happy Number
Pattern: TwoPointers(Fast & Slow) / Floyd's Cycle Detection

Idea:
- Treat the sequence of generated numbers as a linked list.
- Use Floyd’s Cycle Detection (two pointers) to detect a cycle.
- Move slow pointer one step at a time and fast pointer two steps at a time.
- If the sequence reaches 1, the number is a happy number.
- If slow and fast meet at a number other than 1, a cycle exists and the number is not happy

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int genNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = genNext(n);

        while(fast != 1 && slow != fast){
            slow = genNext(slow);
            fast = genNext(genNext(fast));
        }
        return fast == 1;
    }
};