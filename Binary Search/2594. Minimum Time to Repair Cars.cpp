
class Solution {// Time Complexity: O(N * log(R * C²))                        Space Complexity: O(1)
public:

    // Checks whether all cars can be repaired within the given time
    bool isPossible(long long time, vector<int>& ranks, int cars)
    {
        long long totalCars = 0;

        // Calculate how many cars each mechanic can repair
        for(int i = 0; i < ranks.size(); i++)
        {
            // If a mechanic has rank r, repairing n cars takes r * n^2 time.
            //
            // r * n^2 <= time
            // n^2 <= time / r
            // n <= sqrt(time / r)
            //
            // Therefore, this mechanic can repair sqrt(time / rank) cars.

            totalCars += sqrt(time / ranks[i]);
        }

        // If the total number of repaired cars is at least the required cars,
        // then repairing all cars within this time is possible.
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        // Minimum possible time is 1
        long long low = 1;

        // Find the maximum rank among all mechanics
        int maxRank = *max_element(ranks.begin(), ranks.end());

        // Upper bound:
        // Consider the slowest mechanic (maximum rank) repairing all cars.
        //
        // Time required = maxRank * cars * cars
        //
        // This is a valid upper bound because all mechanics together
        // can repair the cars within this time.
        long long high = 1LL * maxRank * cars * cars;

        // Stores the minimum time required to repair all cars
        long long ans = 0;

        // Binary Search on Answer
        while(low <= high)
        {
            // Find the middle time in the current search space
            long long mid = low + (high - low) / 2;

            // Check whether all cars can be repaired within mid time
            if(isPossible(mid, ranks, cars))
            {
                // mid is a possible answer
                ans = mid;

                // Try finding a smaller time
                high = mid - 1;
            }
            else
            {
                // mid is insufficient, so we need more time
                low = mid + 1;
            }
        }

        // Return the minimum feasible time
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Repair Cars                                  │
├──────────────────────────────────────────────┤
│ Approach: Binary Search on Answer            │
│                                              │
│ Key Idea:                                    │
│ Find the minimum time required to repair     │
│ all cars using binary search.                │
│                                              │
│ 1. Set low = 1 and high = maxRank * cars².   │
│ 2. Calculate mid = low + (high - low) / 2.   │
│ 3. For each mechanic, calculate              │
│    sqrt(mid / rank) cars repaired.           │
│ 4. Sum the cars repaired by all mechanics.   │
│ 5. If total >= cars, store ans and search    │
│    left for a smaller time.                  │
│ 6. Otherwise, search right for more time.    │
│                                              │
│ Feasibility: totalCars >= cars               │
│                                              │
│ Time Complexity:  O(n * log(R * C²))         │
│ Space Complexity: O(1)                       │
│ Extra Space:      O(1)                       │
└──────────────────────────────────────────────┘

*/
