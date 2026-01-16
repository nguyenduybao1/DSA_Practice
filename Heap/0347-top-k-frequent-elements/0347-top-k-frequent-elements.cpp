/*
Leetcode 347 - Top K Frequent Elements
Pattern: Hashing + Heap 

Idea:
- Count the frequency of each number using a hash map.
- Use a min-heap that stores pairs of (frequency, number).
- Iterate through the frequency map and push each pair into the heap.
- If the heap size exceeds k, remove the element with the smallest frequency.
- After processing all elements, the heap contains the k most frequent numbers.
- Extract the numbers from the heap to form the result.

Time Complexity: O(n log k)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(int x : nums){
            mp[x]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int, int>>,
            greater<pair<int,int>>
        > pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};