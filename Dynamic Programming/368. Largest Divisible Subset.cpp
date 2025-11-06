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
        // Number of elements in the array
        int n = nums.size();  

        // Step 1️⃣: Sort the array to ensure that if nums[i] % nums[j] == 0,
        // then i > j (helps in forming subsets correctly)
        sort(nums.begin(), nums.end());

        // dp[i] stores the length of the largest divisible subset ending at index i
        vector<int> dp(n, 1);

        // previousIndex[i] stores the index of the previous element in the subset chain
        // This helps in reconstructing the actual subset later
        vector<int> previousIndex(n, -1);

        // Variables to keep track of the overall longest subset
        int maxLength = 1;         // Length of longest divisible subset
        int lastTakenIndex = 0;    // Index where that subset ends

        // Step 2️⃣: Build the dp table
        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                // Check if current element nums[i] can be appended to subset ending at nums[j]
                if (nums[i] % nums[j] == 0) 
                {
                    // If adding nums[i] gives a longer subset, update dp[i] and link the chain
                    if (dp[i] < dp[j] + 1) 
                    {
                        dp[i] = dp[j] + 1;      // Update the length
                        previousIndex[i] = j;   // Store previous element index
                    }

                    // ✅ Check if we found a new longest subset
                    if (dp[i] > maxLength) 
                    {
                        maxLength = dp[i];        // Update max length
                        lastTakenIndex = i;       // Mark where the chain ends
                    }
                }
            }
        }

        // Step 3️⃣: Reconstruct the largest divisible subset using previousIndex[]
        vector<int> ans;
        while (lastTakenIndex != -1) 
        {
            ans.push_back(nums[lastTakenIndex]);       // Add current element to answer
            lastTakenIndex = previousIndex[lastTakenIndex]; // Move to previous element
        }
        
        // Return the final largest divisible subset
        return ans;  
    }
};
