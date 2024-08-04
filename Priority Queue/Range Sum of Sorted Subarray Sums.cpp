
class Solution {// TC--->O(N^2 * NLogN)                     SC--->O(N)
public:
    // Define a type alias for a pair of integers
    typedef pair<int,int>P;
    
    // Modulo value as per problem constraints
    int M = 1e9 + 7;
    
    // Function to calculate the range sum of sorted subarray sums
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        // Min-heap (priority queue) to store pairs of (sum, index)
        priority_queue<P,vector<P>,greater<P>>pq;
        
        // Initialize the priority queue with the initial subarray sums
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        
        // Variable to store the final answer
        int ans = 0;
        
        // Process the elements in the priority queue up to the 'right' position
        for(int i=1;i<=right;i++)
        {
            // Get the smallest sum from the priority queue
            auto front = pq.top();
            pq.pop();
            
            // The sum value
            int val = front.first;
            
            // The ending index of the subarray
            int index = front.second;
            
            // If the current index is within the range [left, right], add the sum to the answer
            if(i >= left)
            {
                ans = (ans + val)%M;
            }
            
            // Calculate the new index for the next subarray sum
            int new_index = index + 1;
            
            // Create a new pair for the next subarray sum if the new index is within bounds
            P new_pair;
            if(new_index < n)
            {
                // Add the next element to the current sum
                new_pair.first = val + nums[new_index];
                
                // Update the ending index of the subarray
                new_pair.second = new_index;
                
                // Push the new pair to the priority queue
                pq.push(new_pair);
            }
        }
        
        // Return the final answer
        return ans;
    }
};
