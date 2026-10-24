

class Solution {// TC ---> O(1)                                  SC ---> O(1)
public:
    // Stores the total number of days before each month begins.
    // Index 0 = January, index 1 = February, and so on.
    // Assumes a non-leap year.
    vector<int> daysBeforeMonth = {
        0, 31, 59, 90, 120, 151,
        181, 212, 243, 273, 304, 334
    };

    // Converts a date in "MM-DD" format into its day number in the year.
    int findDayOfYear(string &date)
    {
        // Extract the month from the first two characters.
        int months = stoi(date.substr(0, 2));

        // Extract the day from the string starting at index 3.
        int days = stoi(date.substr(3));

        // Days before the current month + day of the current month.
        // Example: "03-15" = 59 + 15 = 74.
        return daysBeforeMonth[months - 1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,  string arriveBob, string leaveBob) {

        // Convert Alice's arrival and departure dates into day numbers.
        int arriveAliceDay = findDayOfYear(arriveAlice);
        int leaveAliceDay = findDayOfYear(leaveAlice);

        // Convert Bob's arrival and departure dates into day numbers.
        int arriveBobDay = findDayOfYear(arriveBob);
        int leaveBobDay = findDayOfYear(leaveBob);

        // The overlap starts on the later arrival date.
        int overlapStart = max(arriveAliceDay, arriveBobDay);

        // The overlap ends on the earlier departure date.
        int overlapEnd = min(leaveAliceDay, leaveBobDay);

        // +1 includes both the starting and ending days.
        int overlapDays = overlapEnd - overlapStart + 1;

        // If the end is before the start, there is no overlap.
        return overlapDays < 0 ? 0 : overlapDays;
    }
};

/*

┌──────────────────────────────────────┐
│ Count Days Together                  │
├──────────────────────────────────────┤
│ Convert date to day number           │
│   → daysBeforeMonth[month - 1] + day │
│                                      │
│ Overlap Start                        │
│   → max(arriveAlice, arriveBob)      │
│                                      │
│ Overlap End                          │
│   → min(leaveAlice, leaveBob)        │
│                                      │
│ Overlap Days                         │
│   → overlapEnd - overlapStart + 1    │
│                                      │
│ No overlap (result < 0) → 0          │
├──────────────────────────────────────┤
│ Time Complexity:       O(1)          │
│ Auxiliary Space:       O(1)          │
│ Extra Space:           O(1)          │
└──────────────────────────────────────┘

*/
