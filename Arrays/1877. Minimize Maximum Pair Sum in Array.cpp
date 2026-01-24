
class Solution {// TC ---> O(NLogN)                                SC ---> O(1)
public:
    int minPairSum(vector<int>& nums) {

        // Get the total number of elements in the array
        int n = nums.size();

        // Sort the array in ascending order
        // This helps us pair smallest with largest
        sort(nums.begin(), nums.end());

        // i points to the smallest element (start of array)
        int i = 0;

        // j points to the largest element (end of array)
        int j = n - 1;

        // This will store the maximum pair sum among all pairs
        int ans = 0;

        // Keep forming pairs until both pointers meet
        while (i < j)
        {
            // Calculate sum of current pair
            // (smallest + largest)
            int sum = nums[i] + nums[j];

            // Update answer with the maximum pair sum found so far
            ans = max(ans, sum);

            // Move i forward to the next smallest element
            i++;

            // Move j backward to the next largest element
            j--;
        }

        // Return the minimized maximum pair sum
        return ans;
    }
};
