
class Solution {// TC ---> O(N)                         SC ---> O(N)
public:
    int missingInteger(vector<int>& nums) {

        // Store all numbers of nums in an unordered_set.
        // This allows us to check whether a number exists in nums
        // in O(1) average time.
        unordered_set<int> st(nums.begin(), nums.end());

        // Start with the first element.
        // We will calculate the sum of the longest sequential prefix.
        //
        // Example:
        // nums = [1, 2, 3, 5, 6]
        // Sequential prefix = [1, 2, 3]
        // sum = 1 + 2 + 3 = 6
        int sum = nums[0];

        // Start checking from the second element.
        for (int i = 1; i < nums.size(); i++) {

            // Check whether the current number is exactly
            // 1 greater than the previous number.
            //
            // Example:
            // nums[i-1] = 2
            // nums[i]   = 3
            // 3 - 2 = 1  --> sequential
            if (nums[i] - nums[i - 1] == 1) {

                // The sequence is still continuous,
                // so add the current number to the sum.
                sum += nums[i];

            } else {

                // The sequential prefix has ended.
                // No need to check further elements.
                break;
            }
        }

        // Now 'sum' is the sum of the sequential prefix.
        //
        // The problem asks for the smallest integer >= sum
        // that does NOT exist in nums.
        //
        // Example:
        // nums = [1, 2, 3, 6, 7]
        // sum = 1 + 2 + 3 = 6
        //
        // 6 exists -> try 7
        // 7 exists -> try 8
        // 8 doesn't exist -> answer = 8
        while (st.find(sum) != st.end()) {

            // If sum already exists in nums,
            // increase it by 1 and check again.
            sum++;
        }

        // 'sum' is now the smallest integer that
        // is greater than or equal to the sequential
        // prefix sum and does not exist in nums.
        return sum;
    }
};
