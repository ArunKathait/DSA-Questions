
class Solution {// TC ---> O(N)                                                    SC ---> O(1)
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        
        // Size of array
        int n = arr.size();
        
        // To store maximum XOR found so far
        int maxXor = INT_MIN;
        
        // Two pointers for sliding window
        int i = 0;   // left pointer
        int j = 0;   // right pointer
        
        // Stores XOR of current window
        int currentXor = 0;
        
        // Traverse the array using right pointer
        while(j < n)
        {
            // Include current element in window
            currentXor ^= arr[j];
            
            // If window size becomes exactly k
            if(j - i + 1 == k)
            {
                // Update maximum XOR
                maxXor = max(maxXor, currentXor);
                
                // Remove left element from window
                // (because XOR of same element twice cancels it)
                currentXor ^= arr[i];
                
                // Move left pointer forward
                i++;
            }
            
            // Expand window
            j++;
        }
        
        // Return maximum XOR among all subarrays of size k
        return maxXor;
    }
};
