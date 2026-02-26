/*
Leetcod 155 - Min Stack
Pattern: Stack 

Idea:
- Maintain current minimum (minEle).
- If push value >= minEle -> push normally.
- If push value < minEle -> encode previous min:
    encoded = 2*val - minEle
    update minEle = val
- When popping:
    if popped < minEle -> it was encoded
    restore previous min:
        minEle = 2*minEle - encoded
- When top:
    if top < minEle -> real value = minEle
    else -> normal top

Time Complexity: O(1)
Space Complexity: O(1)
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
    stack<long long> s; long long minEle;
public:
    void push(int val) {
        if (s.empty()) { s.push(val); minEle = val; }
        else if (val < minEle) { s.push(2LL*val - minEle); minEle = val; }
        else s.push(val);
    }
    void pop() {
        long long t = s.top(); s.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int top() { return s.top() < minEle ? (int)minEle : (int)s.top(); }
    int getMin() { return (int)minEle; }
};

