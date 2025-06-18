
class Solution {// TC--->O(NLOGN)                                    SC--->O(N)
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Get the total number of elements in the array
        int n = nums.size(); 

        // This will store the final groups of 3 numbers
        vector<vector<int>> ans; 

        // Sort the array to make it easier to group elements with small differences
        sort(nums.begin(), nums.end());

        // Loop through the array in steps of 3 to form groups of 3 elements
        for (int i = 0; i < n; i += 3)
        {
            // Check if the current group of 3 elements can be formed such that
            // the maximum difference between any two elements is <= k
            // Since the array is sorted, nums[i+2] is the largest and nums[i] is the smallest in the group
            if (nums[i+2] - nums[i] <= k)
            {
                // If the condition is satisfied, add the group to the result
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else
            {
                // If the condition fails for any group, return an empty vector (not possible to divide)
                return {};
            }
        }

        // Return the successfully formed groups
        return ans;
    }
};
