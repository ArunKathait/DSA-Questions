class Solution {// TC ---> O(N)                            SC ---> O(1)
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        int count = 0;  // Counts how many times target appears
        int index = 0;  // Counts how many elements are smaller than target

        // Traverse the array to count target occurrences
        // and elements smaller than target
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
            {
                count++;  // Found one occurrence of target
            }
            else if(nums[i] < target)
            {
                index++;  // One element will appear before target
                         // after sorting
            }
        }

        vector<int> ans;  // Stores the target's indices after sorting

        // Add consecutive indices for every occurrence of target
        while(count--)
        {
            ans.push_back(index);  // Store the current target index
            index++;               // Move to the next target index
        }

        return ans;  // Return all target indices
    }
};

/*

┌─────────────────────────────────────┐
│ Target Indices — Cheat Box          │
├─────────────────────────────────────┤
│ Intuition:                          │
│ Count smaller elements to find the  │
│ target's first index after sorting. │
│                                     │
│ Steps:                              │
│ 1. Count target occurrences.        │
│ 2. Count elements < target.         │
│ 3. Add consecutive target indices.  │
│                                     │
│ Time Complexity:  O(n)              │
│ Auxiliary Space:  O(1)              │
│ Output Space:     O(k)              │
│                                     │
│ k = occurrences of target           │
└─────────────────────────────────────┘

*/
