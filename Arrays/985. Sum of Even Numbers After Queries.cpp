
class Solution {// TC ---> O(N + Q)                             SC ---> O(1)
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        // This will store the sum of all EVEN numbers in nums
        int evenSum = 0;

        // Step 1: Calculate initial sum of even numbers
        for (auto &num : nums)
        {
            // Check if number is even
            if ((num & 1) == 0)
            {
                evenSum += num;   // add even number to evenSum
            }
        }

        // This will store the answer after each query
        vector<int> ans;

        // Step 2: Process each query one by one
        for (auto &x : queries)
        {
            int val = x[0];      // value to add
            int index = x[1];    // index where value will be added

            // If the old value at index is even,
            // remove it from evenSum (because it will change now)
            if ((nums[index] & 1) == 0)
            {
                evenSum -= nums[index];
            }

            // Apply the query: add val to nums[index]
            nums[index] += val;

            // If the new value at index is even,
            // add it to evenSum
            if ((nums[index] & 1) == 0)
            {
                evenSum += nums[index];
            }

            // After updating evenSum correctly,
            // store it as the answer for this query
            ans.push_back(evenSum);
        }

        // Step 3: Return the result
        return ans;
    }
};
