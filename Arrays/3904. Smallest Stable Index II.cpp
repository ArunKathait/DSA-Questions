**********************************************APPROACH 1st(BRUTE FORCE)********************************************
class Solution {// Time: O(n²)                                Space: O(1)
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // We check every index i as a possible "stable index".
        for(int i = 0; i < n; i++)
        {
            // Find the maximum element in the left part:
            // nums[0 ... i]
            int maxi = 0;

            for(int j = 0; j <= i; j++)
            {
                // Update maxi if we find a larger element.
                if(nums[j] > maxi)
                {
                    maxi = nums[j];
                }
            }

            // Find the minimum element in the right part:
            // nums[i ... n-1]
            int mini = INT_MAX;

            for(int j = i; j < n; j++)
            {
                // Update mini if we find a smaller element.
                if(nums[j] < mini)
                {
                    mini = nums[j];
                }
            }

            // A stable index means:
            // maximum of left part - minimum of right part <= k
            if(maxi - mini <= k)
            {
                // Since we are checking i from left to right,
                // this is automatically the FIRST stable index.
                return i;
            }
        }

        // No index satisfies the condition.
        return -1;
    }
};

*********************************************APPROACH 2nd(OPTIMAL)**************************************************

  
