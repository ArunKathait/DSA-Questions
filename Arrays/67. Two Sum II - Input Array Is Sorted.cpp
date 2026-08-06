
class Solution {// TC ---> O(n)                               SC ---> O(1)
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Pointer to the beginning of the sorted array
        int left = 0;

        // Pointer to the end of the sorted array
        int right = numbers.size() - 1;

        // Vector to store the 1-based indices of the answer
        vector<int> ans;

        // Continue until the two pointers meet
        while (left < right)
        {
            // Calculate the sum of the current pair
            int sum = numbers[left] + numbers[right];

            // If the required target is found
            if (sum == target)
            {
                // Problem requires 1-based indexing
                ans.push_back(left + 1);
                ans.push_back(right + 1);

                // Return the answer immediately
                return ans;
            }

            // Current sum is smaller than the target
            else if (sum < target)
            {
                // Since the array is sorted in ascending order,
                // moving the left pointer to the right increases the sum.
                left++;
            }

            // Current sum is greater than the target
            else
            {
                // Since the array is sorted,
                // moving the right pointer to the left decreases the sum.
                right--;
            }
        }

        // If no pair is found (though the problem guarantees one exists)
        return ans;
    }
};
