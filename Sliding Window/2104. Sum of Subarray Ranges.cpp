********************************************APPROACH 1st(USING BRUTE FORCE)**********************************************

class Solution { // TC ---> O(N^2)                                          SC ---> O(1)
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();    // Size of the array

        long long ans = 0;      // Stores final sum of (max - min) for all subarrays

        // Fix the starting index of the subarray
        for(int i = 0; i < n; i++)
        {
            // Initialize min and max for subarray starting at i
            int mini = nums[i];
            int maxi = nums[i];

            // Extend subarray from i to j
            for(int j = i + 1; j < n; j++)
            {
                // Update minimum element of current subarray
                mini = min(mini, nums[j]);

                // Update maximum element of current subarray
                maxi = max(maxi, nums[j]);

                // Add range (max - min) of current subarray
                ans += (maxi - mini);
            }
        }

        // Return total sum of ranges of all subarrays
        return ans;
    }
};
**********************************************************************************************************************
NOTES:

For every index i:
Total subarrays where nums[i] is chosen
= (distance to left boundary) × (distance to right boundary)

That’s why:

left = i - boundary_left
right = boundary_right - i


************************************************APPROACH 2nd(OPTIMAL)*************************************************

class Solution { // TC ---> O(N)                                      SC ---> O(N)
public:

    // ---------- Next Smaller to Left ----------
    // For each index i, find index of nearest element
    // to the LEFT which is strictly smaller than nums[i]
    vector<int> getNSL(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> NSL(n);     // stores indices
        stack<int> st;          // monotonic increasing stack (by value)

        for(int i = 0; i < n; i++)
        {
            // Pop elements >= current because they can't be NSL
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            // If stack empty → no smaller on left
            NSL[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }
        return NSL;
    }

    // ---------- Next Smaller to Right ----------
    // For each index i, find index of nearest element
    // to the RIGHT which is smaller or equal than nums[i]
    vector<int> getNSR(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> NSR(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            // Pop elements > current
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }

            // If stack empty → no smaller on right
            NSR[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return NSR;
    }

    // ---------- Next Greater to Left ----------
    // For each index i, find index of nearest element
    // to the LEFT which is strictly greater than nums[i]
    vector<int> getNGL(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> NGL(n);
        stack<int> st;   // monotonic decreasing stack

        for(int i = 0; i < n; i++)
        {
            // Pop elements <= current
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            // If stack empty → no greater on left
            NGL[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return NGL;
    }

    // ---------- Next Greater to Right ----------
    // For each index i, find index of nearest element
    // to the RIGHT which is greater or equal than nums[i]
    vector<int> getNGR(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> NGR(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            // Pop elements < current
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }

            // If stack empty → no greater on right
            NGR[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return NGR;
    }

    // ---------- Sum of Subarray Minimums ----------
    long long sumSubarrayMins(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> NSL = getNSL(nums);
        vector<int> NSR = getNSR(nums);

        long long totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            // Number of elements we can extend on the left
            long left = i - NSL[i];

            // Number of elements we can extend on the right
            long right = NSR[i] - i;

            // Total subarrays where nums[i] is minimum
            long long totalWays = left * right;

            // Contribution of nums[i]
            totalSum += nums[i] * totalWays;
        }
        return totalSum;
    }

    // ---------- Sum of Subarray Maximums ----------
    long long sumSubarrayMaxs(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> NGL = getNGL(nums);
        vector<int> NGR = getNGR(nums);

        long long totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            long left = i - NGL[i];
            long right = NGR[i] - i;

            // Total subarrays where nums[i] is maximum
            long long totalWays = left * right;

            totalSum += nums[i] * totalWays;
        }
        return totalSum;
    }

    // ---------- Final Answer ----------
    // Range = max - min for each subarray
    long long subArrayRanges(vector<int>& nums) 
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
