
class Solution {// TC ---> O(n²)                                 SC ---> O(n)
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();     // Total number of elements in the array

        int ans = 0;             // Stores the maximum length of a balanced subarray

        // Outer loop: fixes the starting index of the subarray
        for(int i = 0; i < n; i++)
        {
            // Sets to store DISTINCT even and odd numbers in current subarray
            unordered_set<int> even;
            unordered_set<int> odd;
            
            // Inner loop: expands the subarray from index i to j
            for(int j = i; j < n; j++)
            {
                // Check if current element is even
                if(nums[j] % 2 == 0)
                {
                    // Insert even number into even set
                    even.insert(nums[j]);
                } 
                else
                {
                    // Insert odd number into odd set
                    odd.insert(nums[j]);
                }
                
                // If count of distinct even numbers
                // equals count of distinct odd numbers
                if(even.size() == odd.size())
                {
                    // Update the maximum length
                    ans = max(ans, j - i + 1);
                }
            }
        }

        // Return the length of the longest balanced subarray
        return ans;
    }
};
