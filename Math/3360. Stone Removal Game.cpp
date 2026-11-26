
class Solution {// TC: O(1)                           SC: O(1)
public:
    bool canAliceWin(int n) {

        int steps = 0;  // Counts the number of turns taken

        int take = 10;  // Alice starts by removing 10 stones

        // Continue while the current player can remove the required stones
        while(take <= n)
        {
            n -= take;       // Remove the required number of stones
            take -= 1;       // Decrease the number of stones to remove by 1
            steps++;         // Increment the turn counter
        } 

        // Alice wins if the number of successful moves is odd
        // because Alice plays first and players alternate turns
        return steps % 2 != 0 ? true : false;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Can Alice Win                       │
│ Approach: Greedy / Simulation                │
│                                              │
│ Key Idea:                                    │
│ • Alice starts by removing 10 stones.        │
│ • Each subsequent turn removes one less      │
│   stone (9, 8, 7, ...).                      │
│ • Continue while enough stones are present.  │
│ • Count the number of successful moves.      │
│ • Odd moves → Alice wins; Even moves → Bob.  │
│                                              │
│ TC: O(1) – At most 10 iterations.            │
│ SC: O(1) – Only constant extra variables.    │
└──────────────────────────────────────────────┘

*/
