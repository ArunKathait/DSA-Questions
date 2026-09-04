
class Solution {// Time: O(n + 1000) → effectively O(n)               Space: O(1001) → effectively O(1)
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Difference array.
        // vec[i] represents the CHANGE in the number
        // of passengers at location i.
        //
        // Initially, every location has 0 change.
        vector<int> vec(1001, 0);

        // Process every trip
        for(auto &trip : trips)
        {
            int passengers = trip[0];  // Number of passengers
            int from = trip[1];        // Pickup location
            int to = trip[2];          // Drop-off location

            // At 'from', passengers ENTER the car,
            // so increase the passenger count.
            vec[from] += passengers;

            // At 'to', passengers LEAVE the car,
            // so decrease the passenger count.
            vec[to] -= passengers;
        }

        // Stores the actual number of passengers
        // currently inside the car.
        int currentSum = 0;

        // Traverse all possible locations
        for(int i = 0; i < 1001; i++)
        {
            // Add the change happening at this location.
            //
            // If passengers enter:
            //     currentSum increases
            //
            // If passengers leave:
            //     currentSum decreases
            currentSum += vec[i];

            // If the number of passengers currently
            // in the car exceeds its capacity,
            // the trips cannot be completed.
            if(currentSum > capacity)
            {
                return false;
            }
        }

        // At every location, the number of passengers
        // was within the given capacity.
        return true;
    }
};

/*

Key idea to remember

This is a classic difference array + prefix sum pattern:

At the starting point → add passengers.
At the ending point → subtract passengers.
Prefix sum → gives current passengers.

┌─────────────────────────────────────────────┐
│             CAR POOLING CHEAT BOX           │
├─────────────────────────────────────────────┤
│ Pattern: Difference Array + Prefix Sum      │
│                                             │
│ At pickup:                                  │
│     vec[from] += passengers                 │
│                                             │
│ At drop:                                    │
│     vec[to] -= passengers                   │
│                                             │
│ Running passengers:                         │
│     currentSum += vec[i]                    │
│                                             │
│ Check:                                      │
│     currentSum > capacity → false           │
│                                             │
│ Finish all locations → true                 │
├─────────────────────────────────────────────┤
│ TIME  : O(n + 1000) → O(n)                  │
│ SPACE : O(1001) → O(1)                      │
└─────────────────────────────────────────────┘

*/
