**********************************************APPROACH 1st(USING RECURSION)**********************************************

class Solution {// TC ---> O(2^N * N)                                SC ---> O(N)
public:

    // Recursive helper function to generate all subsets
    // index → current position in nums
    // n → total number of elements
    // nums → input array
    // temp → current subset being built
    // ans → stores the largest divisible subset found so far
    // prev → last selected element in the subset (used to check divisibility)
    void solve(int index, int n, vector<int>& nums, vector<int>& temp, vector<int>& ans, int prev)
    {
        // ✅ Base case:
        // If we've considered all elements (index >= n),
        // check if the current subset (temp) is larger than the best answer so far.
        if(index >= n)
        {
            if(temp.size() > ans.size())
            {
                ans = temp; // Update the answer if current subset is larger
            }
            return;
        }

        // ✅ Choice 1: Include nums[index] if it divides correctly with prev
        // We can include the current number only if:
        // - prev == -1 (means no previous element chosen yet)
        // - OR nums[index] is divisible by prev
        if(prev == -1 || nums[index] % prev == 0)
        {
            // Choose current element
            temp.push_back(nums[index]);

            // Move forward to next index
            solve(index + 1, n, nums, temp, ans, nums[index]);

            // Backtrack — remove the last chosen element
            temp.pop_back();
        }

        // ✅ Choice 2: Skip current number and move ahead
        solve(index + 1, n, nums, temp, ans, prev);
    }
    
    // Main function
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size();

        // Step 1: Sort the array
        // Sorting ensures that for any pair i < j, nums[j] >= nums[i],
        // making it easier to check divisibility (nums[j] % nums[i] == 0).
        sort(nums.begin(), nums.end());

        vector<int> ans;   // To store the final largest subset
        vector<int> temp;  // Temporary subset while exploring
        int prev = -1;     // Initially no previous number chosen

        // Step 2: Start recursion from index 0
        solve(0, n, nums, temp, ans, prev);

        // Step 3: Return the largest divisible subset found
        return ans;
    }
};

***********************************************APPROACH 2nd(USING TABULATION)*******************************************

class Solution {// TC ---> O(N^2)                                   SC ---> O(N)
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Get total number of elements in the input array
        int n = nums.size();  

        // Sort the array in ascending order
        // Sorting helps because if nums[i] % nums[j] == 0, then nums[i] >= nums[j].
        sort(nums.begin(), nums.end());

        // dp[i] will store the length of the largest divisible subset ending at index i
        vector<int> dp(n, 1);

        // previousIndex[i] stores the index of the previous element
        // that is part of the subset ending at nums[i]
        // (used later to reconstruct the subset)
        vector<int> previousIndex(n, -1);

        // Variables to keep track of the maximum subset length found so far
        int maxLength = 1;

        // And the index of the last element of that subset
        int lastTakenIndex = 0;

        // Start looping through the array to fill dp[]
        for (int i = 1; i < n; i++) 
        {
            // For each nums[i], check all previous elements nums[j]
            for (int j = 0; j < i; j++) 
            {
                // If nums[i] is divisible by nums[j],
                // then nums[i] can be added after nums[j] in a divisible subset
                if (nums[i] % nums[j] == 0) 
                {
                    // If including nums[i] after nums[j] forms a longer subset
                    if (dp[i] < dp[j] + 1) 
                    {
                        dp[i] = dp[j] + 1;         // Update the length of subset ending at i
                        previousIndex[i] = j;      // Store the link to previous index j
                    }
                }
            }

            // Update the maximum length and last index of the best subset found so far
            if (dp[i] > maxLength) 
            {
                // Update maxLength to the current best length
                maxLength = dp[i];             

                // Store the index i — this index will be used later
                // to backtrack the actual subset elements (starting from this element)
                lastTakenIndex = i;
            }
        }

        // Reconstruct the subset from the information stored in previousIndex[]
        vector<int> ans;

        // Start from the last element of the largest subset
        while (lastTakenIndex != -1) 
        {
            ans.push_back(nums[lastTakenIndex]);  // Add current element to result
            lastTakenIndex = previousIndex[lastTakenIndex];  // Move to the previous element
        }

        // The subset is constructed in reverse order (from last to first)
        // but order doesn’t matter, so we can return it directly.
        return ans;
    }
};
