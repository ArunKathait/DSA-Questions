******************************************************APPROACH 1st(USING BRUTE FORCE)*************************************

class Solution {// TC ---> O(N^2)                                       SC ---> O(N)
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Create a set from nums to remove duplicates
        // This helps us check each unique target value only once
        unordered_set<int> set(nums.begin(), nums.end());
        
        int operations = 0;

        // Iterate through each unique target value
        for (auto &target : set)
        {
            // Skip target = 0 because it doesn’t require any operation
            if (target == 0)
            {
                continue; 
            }

            bool flow = false; // Used to track if we are currently inside a "segment" of target values

            // Traverse the array to count how many continuous groups (segments)
            // of 'target' values appear in nums
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == target)
                {
                    // When we first encounter the target after a non-target value,
                    // we start a new segment, so count one operation
                    if (!flow)
                    {
                        operations++;
                        flow = true; // Mark that we are currently in a target segment
                    }
                } 
                else if (nums[i] < target)
                {
                    // When we see a smaller number, it breaks the target segment
                    flow = false; // Reset the flag so next target can start a new segment
                }
            }
        }

        // Return total number of operations (segments found across all target values)
        return operations;
    }
};

**************************************************APPROACH 2nd(USING BETTER APPROACH)********************************
  
class Solution {// TC ---> O(N)                                SC ---> O(N)
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;  // Stack to keep track of increasing sequence of numbers
        
        int operations = 0;  // To count total operations needed

        for (int i = 0; i < n; i++)
        {
            // If current number is smaller than the top of stack,
            // it means the sequence is decreasing,
            // so we remove all elements greater than nums[i]
            while (!st.empty() && st.top() > nums[i])
            {
                st.pop();
            }

            // Skip zeros because they don't require any operation
            if (nums[i] == 0)
            {
                continue;
            }

            // If stack is empty (no active value)
            // or current number is greater than the top (new higher value),
            // it means we are starting a new "operation"
            if (st.empty() || st.top() < nums[i])
            {
                st.push(nums[i]);  // Push current number as the new top
                operations++;      // Increment operation count
            }
        }

        // Return the total number of distinct operations
        return operations;
    }
};

