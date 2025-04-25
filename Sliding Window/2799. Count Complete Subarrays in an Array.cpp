
class Solution {// TC--->O(N)                           SC--->O(N)
public:
    int countCompleteSubarrays(vector<int>& nums) {
         // Get the length of the input array.
        int n = nums.size();
        
        // Step 1: Use a set to find how many unique elements are in the array.
        unordered_set<int>set(nums.begin(),nums.end());

        // Total number of unique elements in the entire array.
        int uniqueCount = set.size();
         
        // To keep track of the frequency of elements in the current window.
        unordered_map<int,int>ump;

        // Left pointer of the sliding window.
        int i = 0;

        // Right pointer of the sliding window.
        int j = 0;

        // Variable to store the final count of complete subarrays.
        int ans = 0;

        // Step 2: Start sliding the window
        while(j < n)
        {
            // Include nums[j] in the current window and update its count.
             ump[nums[j]]++;

             // Step 3: Check if the current window has all unique elements
             while(uniqueCount == ump.size())
             {
                // If yes, then all subarrays starting from index i and ending at any index >= j are complete.
                // So, we add (n - j) to the answer.
                ans += n - j;

                // Try to shrink the window from the left to find other possible complete subarrays.
                // Decrease the frequency of nums[i].
                ump[nums[i]]--;
                if(ump[nums[i]] == 0)
                {
                    // If frequency becomes 0, remove the element.
                    ump.erase(nums[i]);
                } 
                // Move the left pointer to the right.
                i++;
             }
             // Move the right pointer to the right.
             j++;
        }

        // Return the total number of complete subarrays.
        return ans;
    }
};
