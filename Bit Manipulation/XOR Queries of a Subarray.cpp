
class Solution {// TC--->O(N + Q)                      SC--->O(N + Q)
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Get the size of the input array `arr`
        int n = arr.size();
        
        // Create a cumulative XOR array to store the prefix XOR values
        vector<int>cumulativeXor(arr.size());
        
        // Initialize the first element as the first value of the input array
        cumulativeXor[0] = arr[0];
        
        // Compute the cumulative XOR for the array
        for(int i=1;i<n;i++)
        {
            // cumulativeXor[i] stores the XOR of all elements from arr[0] to arr[i]
            cumulativeXor[i] = cumulativeXor[i-1] ^ arr[i];
        }
        
        // To store the results of all queries
        vector<int>ans;
        
        // Loop through each query in `queries`
        for(auto &x:queries)
        {
            // Get the left index of the query
            int left = x[0];
            
            // Get the right index of the query
            int right = x[1];
            
            // Variable to store the result for this query
            int xorVal;
            
            // If the left index is 0, the XOR from arr[0] to arr[right] is simply cumulativeXor[right]
            if(left == 0)
            {
                // This is the same as just cumulativeXor[right]
                xorVal = 0 ^ cumulativeXor[right];
            } 
            else 
            {
                // Otherwise, the XOR from arr[left] to arr[right] can be computed as:
                // cumulativeXor[right] ^ cumulativeXor[left-1]
                // This works because cumulativeXor[left-1] cancels out the XOR of all elements before `left`
                xorVal = cumulativeXor[left-1] ^ cumulativeXor[right];
            }
            
            // Add the result for this query to the result array
            ans.push_back(xorVal);
        }
        
        // Return the final array with answers for all queries
        return ans;
    }
};
