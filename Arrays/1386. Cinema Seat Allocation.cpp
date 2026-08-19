*************************************************APPROACH 1st*********************************************************

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Store reserved seats row-wise.
        //
        // Key   -> row number
        // Value -> set of reserved seat numbers in that row
        //
        // We use a map instead of an n x 10 matrix because
        // n can be very large and only rows with reservations matter.
        unordered_map<int, unordered_set<int>> ump;

        for(auto x : reservedSeats)
        {
            int row = x[0];
            int seat = x[1];

            // Mark this seat as reserved for this row.
            ump[row].insert(seat);
        }

        // Rows that don't appear in ump have NO reserved seats.
        //
        // A completely empty row can always accommodate
        // two families:
        //
        // Family 1 -> seats 2,3,4,5
        // Family 2 -> seats 6,7,8,9
        //
        // Therefore, directly add 2 families for every
        // row that has no reservation.
        int ans = (n - ump.size()) * 2;

        // Now process only the rows that contain
        // at least one reserved seat.
        for(auto &[row, bookedSeats] : ump)
        {
            // Lambda function to check whether a particular
            // seat is available in the current row.
            auto isAvailable = [&](int seat)
            {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            // Possible group A:
            // Seats 2,3,4,5
            bool groupA = isAvailable(2) && isAvailable(3)
                       && isAvailable(4) && isAvailable(5);

            // Possible group B:
            // Seats 4,5,6,7
            bool groupB = isAvailable(4) && isAvailable(5)
                       && isAvailable(6) && isAvailable(7);

            // Possible group C:
            // Seats 6,7,8,9
            bool groupC = isAvailable(6) && isAvailable(7)
                       && isAvailable(8) && isAvailable(9);

            // If both A and C are available, we can place
            // TWO families in the same row.
            //
            // A -> 2,3,4,5
            // C -> 6,7,8,9
            //
            // They don't overlap.
            if(groupA && groupC)
            {
                ans += 2;
            }

            // Otherwise, if ANY one of A, B or C is available,
            // we can place exactly ONE family.
            //
            // We use else-if because if A && C was true,
            // we already counted the maximum possible 2 families.
            else if(groupA || groupB || groupC)
            {
                ans += 1;
            }

            // If none of the groups is available,
            // we cannot place a family in this row.
        }

        return ans;
    }
};

/* 

┌──────────────────────────────────────────┐
│       CINEMA SEAT ALLOCATION             │
├──────────────────────────────────────────┤
│ Only seats 2 → 9 matter                  │
│                                          │
│ Group A = [2,3,4,5]                      │
│ Group B = [4,5,6,7]                      │
│ Group C = [6,7,8,9]                      │
│                                          │
│ A + C → 2 families                      │
│ A/B/C → 1 family                         │
│ None  → 0 families                       │
│                                          │
│ Empty rows → directly add 2              │
│                                          │
│ Data Structure:                          │
│ unordered_map<row, unordered_set<seat>>  │
│                                          │
│ Time  → O(R)                             │
│ Space → O(R)                             │
│                                          │
│ R = number of reserved seats             │
└──────────────────────────────────────────┘

*/

**********************************************APPROACH 2nd***********************************************************

class Solution {// TC ---> O(R)                                 SC ---> O(R)
// R means the number of reserved seat entries:
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // For every row, store all reserved seats using a bitmask.
        //
        // Example:
        // If seat 3 is reserved:
        //     1 << 3
        // sets the 3rd bit to 1.
        //
        // ump[row] represents the reserved seats of that row.
        unordered_map<int, int> ump;

        // Store reserved seats using a bitmask for each row.
        for(auto &x : reservedSeats)
        {
            int row = x[0];
            int seat = x[1];

            // Set the bit corresponding to this reserved seat.
            //
            // |= is used so that previously reserved seats
            // in the same row are also preserved.
            //
            // Example:
            // seat = 3
            // 1 << 3 = 00001000
            //
            // If seat 5 is also reserved:
            // 00001000
            // |
            // 00100000
            // =
            // 00101000
            ump[row] |= (1 << seat);
        }

        // Rows that don't exist in ump have NO reserved seats.
        //
        // A completely empty row can always accommodate
        // 2 families:
        //
        // Family 1 -> seats 2,3,4,5
        // Family 2 -> seats 6,7,8,9
        //
        // ump.size() = number of rows having at least
        // one reserved seat.
        //
        // Therefore:
        // (n - ump.size()) = rows with no reservations.
        int ans = (n - ump.size()) * 2;


        // There are only 3 possible ways to place
        // a group of 4 people in seats 2 to 9.
        //
        // Group A -> 2,3,4,5
        // Group B -> 4,5,6,7
        // Group C -> 6,7,8,9
        //
        // Convert each group into a bitmask.
        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);


        // Process only rows which have at least
        // one reserved seat.
        for(auto &[row, seatMask] : ump)
        {
            // Check whether Group A is completely available.
            //
            // If:
            //     seatMask & maskA == 0
            //
            // it means there is NO reserved seat
            // among seats 2,3,4,5.
            bool groupA = (seatMask & maskA) == 0;

            // Check whether Group B is completely available.
            //
            // No reserved seat among 4,5,6,7.
            bool groupB = (seatMask & maskB) == 0;

            // Check whether Group C is completely available.
            //
            // No reserved seat among 6,7,8,9.
            bool groupC = (seatMask & maskC) == 0;


            // Group A and Group C don't overlap.
            //
            // A -> 2,3,4,5
            // C -> 6,7,8,9
            //
            // Therefore, if BOTH are available,
            // we can place TWO families in this row.
            if(groupA && groupC)
            {
                ans += 2;
            }

            // Otherwise, if ANY one group is available,
            // we can place ONE family.
            //
            // We use else-if because if A and C were both
            // available, we already added the maximum 2.
            else if(groupA || groupB || groupC)
            {
                ans += 1;
            }

            // If none of A, B or C is available,
            // this row cannot accommodate any family.
        }

        return ans;
    }
};

/* 

┌──────────────────────────────────────────────┐
│       MAX NUMBER OF FAMILIES — BITMASK       │
├──────────────────────────────────────────────┤
│ 1️⃣ Store reserved seats row-wise             │
│    row → bitmask of reserved seats           │
│                                              │
│    ump[row] |= (1 << seat)                   │
│                                              │
│ 2️⃣ Empty rows                                │
│    No reservation → always 2 families        │
│    ans += (n - reservedRows) * 2             │
│                                              │
│ 3️⃣ Only 3 possible groups matter             │
│                                              │
│    A → [2,3,4,5]                             │
│    B → [4,5,6,7]                             │
│    C → [6,7,8,9]                             │
│                                              │
│ 4️⃣ Check availability using bitwise AND      │
│                                              │
│    (seatMask & groupMask) == 0               │
│    → no reserved seat in that group          │
│                                              │
│ 5️⃣ Count maximum families                   │
│                                              │
│    A && C → 2 families                       │
│    A/B/C   → 1 family                        │
│    None    → 0 families                      │
│                                              │
│ 🔑 Key Idea:                                 │
│ Use BITMASK to represent reserved seats      │
│ and check groups in O(1).                    │
└──────────────────────────────────────────────┘

*/
