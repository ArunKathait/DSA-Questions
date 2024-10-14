
class Solution {// TC--->O(NlogN + klogN)                SC--->O(N)
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Use a max-heap (priority_queue) to always get the largest element.
        // The priority_queue is initialized with all elements from the nums vector.
        priority_queue<int>pq(nums.begin(),nums.end());
        
        // Variable to keep track of the total score, using long long for large sums.
        long long score = 0;
        
        // Loop while there are elements in the priority_queue and we still have k operations left.
        while(!pq.empty() && k > 0)
        {
            // Get the largest element from the heap (the top element of the max-heap).
            auto top = pq.top();
            
            // Remove the top element from the heap.
            pq.pop();
            
            // Add the largest element to the total score.
            score += top;
            
            // Divide the current top element by 3 (with ceiling) and push it back into the heap.
            // This ensures that we're inserting a reduced value of the top element.
            int newElement = ceil(top/3.0);
            
            // Add the new element back to the priority_queue.
            pq.push(newElement);
            
            // Decrement the number of remaining operations (k).
            k--;
        }
        
        // Return the final accumulated score after k operations.
        return score;
    }
};
