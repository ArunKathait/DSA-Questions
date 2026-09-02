**********************************************APPROACH 1st(USING BINARY SEARCH)****************************************

// This solution will give TLE.
  
class Solution {// Time: O(n × m × H × log H) worst case            Space: O(n × m × H)
public:
    // Memoization map:
    // key = row + column + current health
    // value = whether we can reach the destination alive from this state
    unordered_map<string, bool> ump;

    bool canSurvive(int minHealth, int row, int col, int n, int m, vector<vector<int>>& dungeon) {
        
        // If we move outside the dungeon, this path is invalid
        if(row >= n || col >= m) 
        {
            return false;
        }

        // Add the current cell's effect to our health
        minHealth += dungeon[row][col];

        // If health becomes 0 or negative, the knight dies
        if(minHealth <= 0) 
        {
            return false;
        }

        // If we reached the bottom-right cell alive,
        // then the current starting health is sufficient
        if(row == n - 1 && col == m - 1) 
        {
            return true;
        }

        // Create a unique key for the current state
        string key = to_string(row) + "_" + to_string(col) + "_" + to_string(minHealth);

        // If this state has already been calculated,
        // return the stored result
        if(ump.count(key)) 
        {
            return ump[key];
        }

        // Try moving right
        int right = canSurvive(minHealth, row, col + 1, n, m, dungeon);

        // Try moving down
        int down = canSurvive(minHealth, row + 1, col, n, m, dungeon);

        // If either right or down path is successful,
        // then this state is also successful
        return ump[key] = right || down;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();

        // Minimum possible starting health
        int left = 1;

        // Maximum possible starting health
        int right = 4 * 1e7;

        int minHealth = right;

        // Binary search for the minimum starting health
        while(left <= right) {
            
            int mid = left + (right - left) / 2;

            // Clear memoization for every new starting health
            ump.clear();

            // Check if we can survive with 'mid' starting health
            if(canSurvive(mid, 0, 0, n, m, dungeon)) 
            {    
                // 'mid' is sufficient, so store it
                minHealth = mid;

                // Try to find an even smaller answer
                right = mid - 1;
            }
            else 
            {    
                // 'mid' is not sufficient, so we need more health
                left = mid + 1;
            }
        }

        return minHealth;
    }
};

*************************************************APPROACH 2nd(MEMOIZATION)*********************************************

class Solution {// Time: O(n × m)                           Space: O(n × m)
public:
    int solve(int row, int col, int n, int m, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {

        // If we move outside the dungeon,
        // this path is invalid.
        //
        // Return a very large value so that this path
        // will never be selected by min(right, down).
        if(row >= n || col >= m) 
        {
            return 1e9;
        }

        // Base case:
        // We have reached the bottom-right cell.
        if(row == n - 1 && col == m - 1) 
        {
            // If the last cell is positive,
            // we only need 1 health to enter it.
            //
            // Example:
            // dungeon = +10
            // Starting with 1 health is enough.
            if(dungeon[row][col] > 0) 
            {
                return 1;
            }

            // If the last cell is negative,
            // we need enough health to survive its damage.
            //
            // Example:
            // dungeon = -5
            // We need 6 health:
            // 6 + (-5) = 1
            else 
            {
                return abs(dungeon[row][col]) + 1;
            }
        }

        // If we have already calculated the minimum
        // health required for this cell, return it.
        if(dp[row][col] != -1) 
        {
            return dp[row][col];
        }

        // Find the minimum health required if we move right.
        int right = solve(row, col + 1, n, m, dungeon, dp);

        // Find the minimum health required if we move down.
        int down = solve(row + 1, col, n, m, dungeon, dp);

        // We only need to choose one path:
        // either right or down.
        //
        // So choose the path requiring less health.
        int ans = min(right, down) - dungeon[row][col];

        // Health can never be less than 1.
        //
        // Example:
        // If ans = -5, we don't need negative health.
        // We only need 1 health.
        return dp[row][col] = ans > 0 ? ans : 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        // dp[row][col] stores:
        // minimum health required when entering
        // dungeon[row][col] to eventually reach the destination alive.
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start from the top-left cell.
        // The answer is the minimum health required
        // when entering (0,0).
        return solve(0, 0, n, m, dungeon, dp);
    }
};

*******************************************APPROACH 3rd(TABULATION)*************************************************

class Solution {// Time: O(n × m)                                                Space: O(n × m)
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        // dp[i][j] = minimum health required when entering
        // cell (i,j) so that we can eventually reach the destination alive.
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // We start from the destination and move backwards
        // because the answer for the current cell depends on
        // the answer of the right or down cell.
        for(int i = n - 1; i >= 0; i--) 
        {
            for(int j = m - 1; j >= 0; j--) 
            {
                // If we are at the bottom-right cell,
                // this is our destination.
                if(i == n - 1 && j == m - 1) 
                {
                    // If the destination gives us health,
                    // we only need 1 health to enter it.
                    //
                    // Example:
                    // dungeon[i][j] = +5
                    // 1 + 5 = 6
                    // So 1 health is enough.
                    if(dungeon[i][j] > 0) 
                    {
                        dp[i][j] = 1;
                    }
                    else 
                    {
                        // If the destination causes damage,
                        // we need enough health to survive the damage
                        // and still have at least 1 health.
                        //
                        // Example:
                        // dungeon[i][j] = -5
                        // We need 6 health.
                        // 6 + (-5) = 1
                        dp[i][j] = abs(dungeon[i][j]) + 1;
                    }
                }
                else 
                {

                    // Find the minimum health required by the right cell.
                    //
                    // If right cell does not exist, give it a very large
                    // value so that we don't choose this invalid path.
                    int right = (j + 1 >= m) ? 1e9 : dp[i][j + 1];

                    // Find the minimum health required by the down cell.
                    //
                    // If down cell does not exist, give it a very large
                    // value so that we don't choose this invalid path.
                    int down = (i + 1 >= n) ? 1e9 : dp[i + 1][j];

                    // We can move either right or down.
                    // Choose the path that requires less health.
                    //
                    // min(right, down) tells us how much health
                    // we need when we leave the current cell.
                    //
                    // dungeon[i][j] tells us how much health
                    // the current cell adds or removes.
                    //
                    // Therefore:
                    // required health = next cell requirement - current cell value
                    int ans = min(right, down) - dungeon[i][j];

                    // Health can never be less than 1.
                    //
                    // Example:
                    // If ans = -3 or 0,
                    // we still need at least 1 health.
                    dp[i][j] = (ans > 0) ? ans : 1;
                }
            }
        }

        // dp[0][0] contains the minimum initial health
        // required to start from the top-left cell.
        return dp[0][0];
    }
};

/*

┌──────────────────────────────────────────┐
│              DUNGEON GAME                │
├──────────────────────────────────────────┤
│                                          │
│ Pattern: BOTTOM-UP DP                    │
│                                          │
│ Start from DESTINATION                   │
│ Move towards SOURCE                      │
│                                          │
│       DESTINATION → SOURCE               │
│                                          │
│ For every cell:                          │
│                                          │
│ 1. If bottom-right cell                  │
│       → calculate health directly        │
│                                          │
│    If dungeon[i][j] > 0                  │
│       → dp[i][j] = 1                     │
│                                          │
│    Otherwise                             │
│       → dp[i][j] = abs(value) + 1        │
│                                          │
│ 2. Find RIGHT requirement                │
│       right = dp[i][j + 1]               │
│                                          │
│ 3. Find DOWN requirement                 │
│       down = dp[i + 1][j]                │
│                                          │
│ 4. Choose minimum required path          │
│       min(right, down)                   │
│                                          │
│ 5. Subtract current cell's value         │
│       ans = min(right, down)             │
│             - dungeon[i][j]              │
│                                          │
│ 6. Health must always be at least 1      │
│       dp[i][j] = max(ans, 1)             │
│                                          │
│ KEY IDEA:                                │
│ dp[i][j] = minimum health needed         │
│ when ENTERING cell (i,j).                │
│                                          │
│ We work backwards because the required   │
│ health of the current cell depends on    │
│ the next cell.                           │
│                                          │
│ Why min(right, down)?                    │
│ We can choose either RIGHT or DOWN,      │
│ so choose the path requiring less health.│
│                                          │
│ Complexity:                              │
│ Time  → O(n × m)                         │
│ Space → O(n × m)                         │
└──────────────────────────────────────────┘

*/
