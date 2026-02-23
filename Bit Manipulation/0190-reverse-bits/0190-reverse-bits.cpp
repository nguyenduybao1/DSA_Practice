/*
Leetcode 190 - Reverse Bits
Pattern: Bit Manipulation

Idea:
- Loop exactly 32 times (since we deal with a 32-bit integer).
- Each iteration, extract the last bit of n using (n & 1).
- Shift result left by 1 bit, then OR with the extracted bit to build the reversed number.
- Shift n right by 1 bit to move to the next bit.
- After 32 iterations, result holds the bit-reversed version of n.

Time Complexity: O(1)
Space Complexity: O(1)
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};