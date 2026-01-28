
class Solution {// TC ---> O(n × 2ⁿ)                                     SC ---> O(n × 2ⁿ)
public:
    // Recursive function to generate all non-decreasing subsequences
    void solve(int index, int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans)
    {
        // If current subsequence has length >= 2,
        // it is a valid answer, so store it
        if (temp.size() >= 2)
        {
            ans.push_back(temp);
        }

        // Used to avoid picking the same number again
        // at the same recursion level (prevents duplicates)
        unordered_set<int> set;

        // Try all possible elements starting from 'index'
        for (int i = index; i < n; i++)
        {
            // Condition 1:
            // - temp is empty (first element can be anything)
            // - OR current number is >= last element in temp
            //   (to maintain non-decreasing order)
            //
            // Condition 2:
            // - nums[i] has not been used at this recursion level
            if ((temp.empty() || temp.back() <= nums[i]) && set.find(nums[i]) == set.end())
            {
                // Choose current number
                temp.push_back(nums[i]);

                // Recurse for next index
                solve(i + 1, n, nums, temp, ans);

                // Backtrack: remove last element
                temp.pop_back();

                // Mark this number as used at this level
                set.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;  // Stores all valid subsequences
        vector<int> temp;         // Temporary subsequence

        // Start recursion from index 0
        solve(0, n, nums, temp, ans);

        return ans;
    }
};
