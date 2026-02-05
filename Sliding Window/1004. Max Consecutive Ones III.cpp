
class Solution {// TC ---> O(N)                                 SC ---> O(1)
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();          // length of the array

        int ans = 0;                 // stores the maximum window size
        int i = 0;                   // left pointer of sliding window
        int j = 0;                   // right pointer of sliding window
        
        int countZero = 0;           // number of zeros in current window

        // expand the window using right pointer j
        while (j < n)
        {
            // if we encounter a zero, increase zero count
            if (nums[j] == 0)
            {
                countZero++;
            }

            // if zero count exceeds allowed flips (k),
            // shrink the window from the left
            while (countZero > k) 
            {
                // if the left element is zero,
                // reduce zero count as it leaves the window
                if (nums[i] == 0)
                {
                    countZero--;
                }
                i++;    // move left pointer forward
            }

            // update the maximum length of valid window
            // (window contains at most k zeros)
            ans = max(ans, j - i + 1);

            j++;    // move right pointer forward
        }

        return ans;  // return maximum consecutive 1s possible
    }
};
