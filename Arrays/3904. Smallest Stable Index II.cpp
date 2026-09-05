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

*********************************************APPROACH 2nd(BETTER)**************************************************

class Solution {// Time: O(n)                                     Space: O(n)
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // prefixMax[i] = maximum element from index 0 to i
        //
        // Example:
        // nums       = [3, 1, 5, 2]
        // prefixMax  = [3, 3, 5, 5]
        //
        // This helps us quickly find the maximum value
        // in the left part [0 ... i].
        vector<int> prefixMax(n);

        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) 
        {
            // Maximum of:
            // 1. Previous maximum
            // 2. Current element
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }


        // suffixMin[i] = minimum element from index i to n-1
        //
        // Example:
        // nums       = [3, 1, 5, 2]
        // suffixMin  = [1, 1, 2, 2]
        //
        // This helps us quickly find the minimum value
        // in the right part [i ... n-1].
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int j = n - 2; j >= 0; j--) 
        {
            // Minimum of:
            // 1. Minimum found in the suffix starting at j+1
            // 2. Current element nums[j]
            suffixMin[j] = min(suffixMin[j + 1], nums[j]);
        }


        // Check every index from left to right.
        // We want the FIRST index satisfying the condition.
        for (int i = 0; i < n; i++) 
        {
            // prefixMax[i] = maximum element on the left side [0...i]
            // suffixMin[i] = minimum element on the right side [i...n-1]
            //
            // Their difference tells us the range between
            // the maximum and minimum values.
            //
            // If this difference <= k, then index i is stable.
            if (prefixMax[i] - suffixMin[i] <= k) 
            {
                return i;  // First stable index found
            }
        }

        // No index satisfies the condition.
        return -1;
    }
};

***********************************************APPROACH 3rd(OPTIMAL)**************************************************

class Solution {// Time  = O(n)                                Space = O(n)
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suffixMin[i] stores the minimum element
        // from index i to the end of the array.
        //
        // Example:
        // nums      = [3, 1, 5, 2]
        // suffixMin = [1, 1, 2, 2]
        //
        // So suffixMin[i] gives us the minimum value
        // in the right part [i ... n-1].
        vector<int> suffixMin(n);

        // The last element is the minimum of the suffix
        // containing only itself.
        suffixMin[n - 1] = nums[n - 1];

        // Build suffix minimum from right to left.
        for (int i = n - 2; i >= 0; i--) 
        {
            // Compare:
            // 1. Minimum value from i+1 to the end
            // 2. Current element nums[i]
            //
            // The smaller one becomes suffixMin[i].
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }


        // Instead of creating a prefixMax array,
        // we only maintain the maximum value seen so far.
        int prefixMax = 0;

        // Traverse from left to right because
        // we need to find the FIRST stable index.
        for (int i = 0; i < n; i++) 
        {
            // Update the maximum value from index 0 to i.
            //
            // prefixMax represents:
            // maximum(nums[0], nums[1], ..., nums[i])
            prefixMax = max(prefixMax, nums[i]);

            // Check whether index i is stable.
            //
            // prefixMax  = maximum value from [0 ... i]
            // suffixMin[i] = minimum value from [i ... n-1]
            //
            // If their difference is <= k,
            // then index i satisfies the condition.
            if (prefixMax - suffixMin[i] <= k) 
            {
                // Since we are checking indices from left to right,
                // this is the FIRST stable index.
                return i;
            }
        }

        // No stable index was found.
        return -1;
    }
};  
