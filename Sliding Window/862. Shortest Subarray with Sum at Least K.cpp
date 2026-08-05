
class Solution {// TC ---> O(N)                                          SC ---> O(N)
public:
    int shortestSubarray(vector<int>& nums, int k) {

        // Size of the input array
        int n = nums.size();

        // Deque will store indices of prefix sums.
        // It is maintained in increasing order of prefix sums.
        deque<int> dq;

        // Prefix sum array
        // cumulativeSum[i] = sum of elements from 0 to i
        vector<long long> cumulativeSum(n);

        int j = 0;

        // Stores the minimum length of valid subarray
        int ans = INT_MAX;

        while (j < n)
        {
            // Build prefix sum array
            if (j == 0)
            {
                cumulativeSum[j] = nums[j];
            }
            else
            {
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
            }

            // If the prefix sum itself is >= k,
            // then subarray from index 0 to j is valid.
            if (cumulativeSum[j] >= k)
            {
                ans = min(ans, j + 1);
            }

            // Check whether any previous prefix sum can form
            // a valid subarray ending at j.
            //
            // Subarray Sum = cumulativeSum[j] - cumulativeSum[previous]
            //
            // If this value >= k, then we found a valid subarray.
            //
            // Since deque stores indices in increasing prefix sums,
            // the front gives the earliest candidate.
            while (!dq.empty() && cumulativeSum[j] - cumulativeSum[dq.front()] >= k)
            {
                // Length = current index - previous prefix index
                ans = min(ans, j - dq.front());

                // Remove it because any future subarray using this
                // prefix will only become longer.
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums.
            //
            // If current prefix sum is smaller than or equal to
            // the prefix sum at the back of deque,
            // then the larger prefix sum is useless.
            //
            // Reason:
            // A smaller prefix sum gives a larger subarray sum
            // for every future index and is therefore always better.
            while (!dq.empty() && cumulativeSum[j] <= cumulativeSum[dq.back()])
            {
                dq.pop_back();
            }

            // Store current prefix sum index
            dq.push_back(j);

            j++;
        }

        // If no valid subarray exists, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};
