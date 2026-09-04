
class Solution {//Time: O(n + k log k) → worst case O(n log n)          Space: O(n) worst case
public:
    int minSetSize(vector<int>& arr) {

        // Store the size of the original array
        int n = arr.size();

        // HashMap to store frequency of every number
        //
        // Example:
        // arr = [3,3,3,5,5,2]
        //
        // ump:
        // 3 -> 3
        // 5 -> 2
        // 2 -> 1
        unordered_map<int, int> ump;

        // Count frequency of each number
        for(auto &num : arr)
        {
            ump[num]++;
        }

        // Store only the frequencies.
        //
        // We don't care about the actual numbers anymore.
        // We only care about how many elements we can remove
        // by choosing each number.
        vector<int> freqCount;

        for(auto &[key, count] : ump)
        {
            freqCount.push_back(count);
        }

        // Sort frequencies from largest to smallest.
        //
        // We want to remove the numbers having the highest
        // frequency first because they remove more elements
        // with each selection.
        sort(freqCount.rbegin(), freqCount.rend());

        // Number of elements removed so far
        int removed = 0;

        // Number of distinct integers selected for removal
        int ans = 0;

        // Pick the highest frequencies one by one
        for(auto &num : freqCount)
        {
            // Remove all occurrences of this number
            removed += num;

            // We selected one more distinct integer
            ans++;

            // We need to remove at least half of the array
            if(removed >= arr.size() / 2)
            {
                return ans;
            }
        }

        // Return the number of distinct integers selected
        return ans;
    }
};

/* 

┌──────────────────────────────────────┐
│      REDUCE ARRAY SIZE TO HALF       │
├──────────────────────────────────────┤
│ 1. Count frequency                   │
│                                      │
│ 2. Store frequencies                 │
│                                      │
│ 3. Sort descending                   │
│                                      │
│ 4. Take largest frequencies first    │
│                                      │
│ 5. Stop when removed >= n/2          │
├──────────────────────────────────────┤
│ Pattern: Frequency + Greedy          │
│                                      │
│ Time  : O(n + k log k)               │
│ Space : O(n)                         │
└──────────────────────────────────────┘

*/
