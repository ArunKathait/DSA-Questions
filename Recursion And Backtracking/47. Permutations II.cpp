************************************************APPROACH 1st*****************************************************

class Solution {// TC ---> O(n × n!)                            SC ---> O(n)
public:

    // Recursive function to generate all unique permutations.
    //
    // nums  -> Original input array (used only to know the required size).
    // temp  -> Stores the current permutation being built.
    // ans   -> Stores all unique permutations.
    // ump   -> Frequency map (value -> remaining count).
    void solve(vector<int> &nums,
               vector<int> &temp,
               vector<vector<int>> &ans,
               unordered_map<int,int> &ump)
    {
        // Base case:
        // If the current permutation contains all elements,
        // store it in the answer.
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Try every distinct number present in the frequency map.
        for(auto &[val, count] : ump)
        {
            // If this number has already been used completely,
            // skip it.
            if(count == 0)
            {
                continue;
            }

            // ---------------- Choose ----------------

            // Add the current value to the permutation.
            temp.push_back(val);

            // Decrease its remaining frequency.
            ump[val]--;

            // ---------------- Explore ----------------

            // Generate the remaining permutation.
            solve(nums, temp, ans, ump);

            // ---------------- Backtrack ----------------

            // Remove the last inserted value.
            temp.pop_back();

            // Restore its frequency so it can be used
            // in other recursive branches.
            ump[val]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Frequency map:
        // Stores how many times each number appears.
        unordered_map<int,int> ump;

        for(auto &num : nums)
        {
            ump[num]++;
        }

        // Stores all unique permutations.
        vector<vector<int>> ans;

        // Stores the current permutation.
        vector<int> temp;

        // Start backtracking.
        solve(nums, temp, ans, ump);

        return ans;
    }
};

***********************************************APPROACH 2nd***********************************************************

class Solution {// Tc ---> O(n × n!)                              SC ---> O(N)
public:

    // Recursive function to generate all unique permutations.
    //
    // index -> Current position that we are fixing.
    // nums  -> Current state of the permutation.
    // ans   -> Stores all unique permutations.
    void solve(int index, int n,
               vector<int> &nums,
               vector<int> &temp,
               vector<vector<int>> &ans)
    {
        // Base case:
        // If all positions have been fixed,
        // store the current permutation.
        if(index == n)
        {
            ans.push_back(nums);
            return;
        }

        // Keeps track of the values that have already
        // been placed at the current index.
        //
        // This prevents generating duplicate permutations.
        unordered_set<int> uniqueSet;

        // Try every element from index to n-1
        // at the current position.
        for(int i = index; i < n; i++)
        {
            // If this value has already been used
            // at the current recursion level,
            // skip it.
            if(uniqueSet.find(nums[i]) != uniqueSet.end())
            {
                continue;
            }

            // Mark this value as used at this level.
            uniqueSet.insert(nums[i]);

            // ---------------- Choose ----------------

            // Place nums[i] at position 'index'.
            swap(nums[i], nums[index]);

            // ---------------- Explore ----------------

            // Fix the next position.
            solve(index + 1, n, nums, temp, ans);

            // ---------------- Backtrack ----------------

            // Restore the original array so the next
            // iteration starts with the original state.
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n = nums.size();

        // Not used in this approach.
        vector<int> temp;

        // Stores all unique permutations.
        vector<vector<int>> ans;

        // Start fixing elements from index 0.
        solve(0, n, nums, temp, ans);

        return ans;
    }
};
