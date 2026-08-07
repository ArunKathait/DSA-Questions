
class Solution {// TC ---> O(n × n!)                        SC ---> O(n)
public:

    // Recursive function to generate all permutations.
    // 'index' represents the current position that we want to fill.
    void solve(int index, int n, vector<int> &nums, vector<vector<int>> &ans)
    {
        // Base case:
        // If index reaches the end of the array,
        // one complete permutation has been formed.
        if(index >= n)
        {
            ans.push_back(nums);
            return;
        }

        // Try placing every element from index to n-1
        // at the current position (index).
        for(int i = index; i < n; i++)
        {
            // Swap the current element with the element
            // at the current position.
            swap(nums[i], nums[index]);

            // Recursively fix the next position.
            solve(index + 1, n, nums, ans);

            // Backtrack:
            // Restore the original array before trying
            // the next possible element.
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        // Stores all possible permutations.
        vector<vector<int>> ans;

        // Start generating permutations from index 0.
        solve(0, n, nums, ans);

        // Return all generated permutations.
        return ans;
    }
};
