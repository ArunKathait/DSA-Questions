
class Solution {// TC ---> O(N)                                   SC ---> O(K)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        // Deque will store indices of elements
        // It will always maintain:
        // 1) Indices within the current window
        // 2) Elements in decreasing order of their values
        deque<int> dq;

        // This will store the maximum of each window
        vector<int> ans;

        // Traverse the array
        for(int i = 0; i < n; i++)
        {
            // STEP 1: Remove indices that are OUTSIDE the current window
            // Current window range: [i - k + 1, i]
            // If dq.front() <= i - k, it means that index is no longer in window
            while(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // STEP 2: Remove smaller elements from the BACK
            // If current element is greater than elements in deque,
            // those elements can NEVER be maximum in future windows
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // STEP 3: Add current index to deque
            dq.push_back(i);

            // STEP 4: Start adding answers once first window is complete
            // First valid window ends at index k - 1
            if(i >= k - 1)
            {
                // Front of deque always contains index of maximum element
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
