**********************************************************APPROCAH 1st**********************************************************************

class Solution {// TC--->O(N)                        SC--->O(N)
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Find the maximum number in the array
        int maxNumber = *max_element(nums.begin(), nums.end());
        
        // Stores indices where maxNumber occurs
        vector<int> indices;  

        // To store the final count of valid subarrays
        long long ans = 0;    

        // Step 2: Traverse the array
        for (int i = 0; i < n; i++) 
        {
            // If the current element is the maximum, store its index
            if (nums[i] == maxNumber) 
            {
                indices.push_back(i);
            }

            // Current number of maxNumber occurrences
            int size = indices.size();  

            // Step 3: If we have at least k occurrences of maxNumber so far
            if (size >= k) 
            {
                // The k-th most recent maxNumber (from the right) is at index: indices[size - k]
                int lastIndex = indices[size - k];

                // All subarrays ending at i and starting from 0 to lastIndex are valid
                // So, we add (lastIndex + 1) to the answer
                ans += (lastIndex + 1);
            }
        }

        // Return total valid subarrays
        return ans;
    }
};

*******************************************************************APPROACH 2nd(SLIDING WINDOW)***************************************************


class Solution {// TC--->O(N)                                SC--->O(1)
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Find the maximum number in the array
        int maxNumber = *max_element(nums.begin(),nums.end());

        // To store the final count of valid subarrays
        long long ans = 0;

        // Left pointer of sliding window
        int i = 0;

         // Right pointer of sliding window
        int j = 0;
        
         // Count of maxNumber in the current window [i..j]
        int count = 0;

        // Step 2: Expand the window using right pointer 'j'
        while(j < n)
        {
            // If current element is maxNumber, increase the count
            if(nums[j] == maxNumber)
            {
                count++;
            }

            // Step 3: When count of maxNumber >= k in window [i..j],
            // we found valid subarrays starting from i to j
            while(count >= k)
            {
                // For every such i, all subarrays [i..j], [i..j+1], ..., [i..n-1] are valid
                // Add all those valid subarrays to answer
                ans += (n - j);

                // Shrink the window from the left (move i forward)
                // and update count if needed
                if(nums[i] == maxNumber)
                {
                    count--;
                }
                i++;
            }

            // Move right pointer to expand the window
            j++;
        }

        // Return the total number of valid subarrays
        return ans;
    }
};
