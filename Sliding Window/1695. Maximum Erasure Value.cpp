
class Solution {// TC ---> O(N)                           SC ---> O(1)
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        // Set stores all elements currently present
        // inside our sliding window [i ... j].
        //
        // The important condition is:
        // Every element inside the window must be UNIQUE.
        unordered_set<int> st;

        // i = left boundary of the window
        int i = 0;

        // j = right boundary of the window
        int j = 0;

        // Stores the sum of all elements
        // currently inside the window.
        int sum = 0;

        // Stores the maximum unique-subarray sum found so far.
        int ans = 0;


        // Expand the window using j.
        while (j < n)
        {
            // If nums[j] is already present in the window,
            // we have found a duplicate.
            //
            // Example:
            // Window = [4, 2, 4]
            // nums[j] = 4
            //
            // We cannot keep this duplicate 4,
            // so we move the left pointer i forward
            // until the duplicate is removed.
            while (st.find(nums[j]) != st.end())
            {
                // Remove nums[i] from the current sum
                // because we are removing it from the window.
                sum -= nums[i];

                // Remove nums[i] from the set as well.
                st.erase(nums[i]);

                // Move the left boundary forward.
                i++;
            }

            // Now nums[j] is NOT present in the window,
            // so it is safe to add it.
            sum += nums[j];

            // Insert the new element into the set.
            st.insert(nums[j]);

            // The current window [i ... j] contains
            // only unique elements.
            //
            // Check whether its sum is the maximum
            // we have seen so far.
            ans = max(ans, sum);

            // Expand the window from the right.
            j++;
        }

        // Return the maximum sum of a subarray
        // containing only unique elements.
        return ans;
    }
};

/*

╔══════════════════════════════════════════════╗
║       MAXIMUM UNIQUE SUBARRAY — 1695         ║
╠══════════════════════════════════════════════╣
║ 🎯 Goal: MAXIMUM SUM of unique elements     ║
║                                              ║
║ Pattern: Sliding Window + HashSet            ║
║                                              ║
║ Window [i...j] → only UNIQUE elements        ║
║                                              ║
║ If nums[j] is unique:                        ║
║ → Add nums[j] to set and sum                 ║
║                                              ║
║ If nums[j] is duplicate:                     ║
║ → Remove nums[i] from set and sum            ║
║ → Move i until duplicate is removed          ║
║                                              ║
║ Maintain:                                    ║
║ set → elements in current window             ║
║ sum → current window sum                     ║
║ ans → maximum sum found                      ║
║                                              ║
║ ⭐ Duplicate → shrink LEFT                  ║
║ ⭐ Unique → expand RIGHT                    ║
║                                              ║
║ TC: O(N) average                             ║
║ SC: O(N)                                     ║
╚══════════════════════════════════════════════╝

*/
