**********************************************APPROACH 1st(USING RECURSION)*****************************************

class Solution {
public:
    // Time Complexity = O(2^n) (exponential).
    // Space Complexity = O(n) (stack space).
    
    // Recursive function to calculate the maximum score a player can achieve
    // when it's their turn to pick from the subarray nums[i...j]
    int solve(int i,int j,vector<int>&nums)
    {
        // Base case 1: If i > j, no elements left, return 0
        if(i > j)
        {
            return 0;
        }

        // Base case 2: If only one element left, player must take it
        if(i == j)
        {
            return nums[i];
        }

        // Player has two choices:
        // 1. Take nums[i], then the opponent will play optimally.
        //    - Opponent can then choose nums[i+1] or nums[j].
        //    - So player will get nums[i] + min(remaining cases),
        //      because opponent tries to minimize player’s score.
        int take_i = nums[i] + min(
            solve(i+2,j,nums),     // opponent takes i+1, so we start from i+2
            solve(i+1,j-1,nums)    // opponent takes j, so we have [i+1...j-1]
        );

        // 2. Take nums[j], then the opponent will play optimally.
        //    - Opponent can then choose nums[i] or nums[j-1].
        //    - So player will get nums[j] + min(remaining cases).
        int take_j = nums[j] + min(
            solve(i,j-2,nums),     // opponent takes j-1, so we have [i...j-2]
            solve(i+1,j-1,nums)    // opponent takes i, so we have [i+1...j-1]
        );

        // Player will choose the option that gives maximum score
        return max(take_i,take_j);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Calculate the total sum of all numbers
        int totalSum = 0;
        for(auto x:nums)
        {
            totalSum += x;
        }

        // Find maximum score Player 1 can achieve if both play optimally
        int player1Score = solve(0,n-1,nums);

        // Player 2's score = totalSum - player1Score
        int player2Score = totalSum - player1Score;

        // If Player 1's score is greater or equal, Player 1 wins
        return player1Score >= player2Score;
    }
};

*******************************************APPROACH 1st(USING MEMOIZATION)************************************

// Time = O(n²) (since there are n² possible (i, j) ranges).
// Space = O(n²) (for the DP table).
class Solution {
public:
    // Recursive function to calculate maximum score player can get
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        // Case 1: If indexes cross, no numbers left
        if(i > j) 
        {
            return 0;
        }

        // Case 2: If only one number left, player must take it
        if(i == j) 
        {
            return nums[i];
        }

        // If already solved for this range, return stored answer
        if(dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        // Choice 1: Player picks nums[i]
        // After this, opponent plays optimally.
        // Opponent can pick either nums[i+1] or nums[j].
        // So we take the minimum of the two possible cases (because opponent wants to minimize our score).
        int take_i = nums[i] + min(
            solve(i+2, j, nums, dp),    // Opponent picked i+1, now our turn from (i+2..j)
            solve(i+1, j-1, nums, dp)   // Opponent picked j, now our turn from (i+1..j-1)
        );

        // Choice 2: Player picks nums[j]
        // Similarly, opponent will play optimally next.
        int take_j = nums[j] + min(
            solve(i, j-2, nums, dp),    // Opponent picked j-1, now our turn from (i..j-2)
            solve(i+1, j-1, nums, dp)   // Opponent picked i, now our turn from (i+1..j-1)
        );

        // Store the best of two choices in dp and return
        return dp[i][j] = max(take_i, take_j);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // DP table: dp[i][j] stores best score player can achieve from nums[i..j]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Step 1: Find total sum of all numbers
        int totalSum = 0;
        for(int x : nums) 
        {
            totalSum += x;
        }

        // Step 2: Find maximum score Player 1 can get if both play optimally
        int player1Score = solve(0, n-1, nums, dp);

        // Step 3: Player 2’s score = totalSum - player1Score
        int player2Score = totalSum - player1Score;

        // Step 4: If Player 1’s score is greater or equal, Player 1 wins
        return player1Score >= player2Score;
    }
};

*********************************************APPROACH 2nd(USING RECURSION)************************************

class Solution {// TC--->O(2^N)                          SC--->O(N)
public:
    // Recursive function to calculate the maximum score difference
    // (currentPlayerScore - opponentScore) for the subarray nums[i...j]
    int solve(int i, int j, vector<int>& nums)
    {
        // Base case 1: If the range is invalid (i > j), no numbers are left
        // → score difference is 0
        if (i > j) 
        {
            return 0;
        }

        // Base case 2: If only one number is left,
        // the current player will take it, so difference = nums[i]
        if (i == j) 
        {
            return nums[i];
        }

        // Choice 1: Current player picks the leftmost number (nums[i])
        // After taking nums[i], opponent plays optimally on (i+1...j),
        // so subtract that result.
        int pickLeft = nums[i] - solve(i + 1, j, nums);

        // Choice 2: Current player picks the rightmost number (nums[j])
        // After taking nums[j], opponent plays optimally on (i...j-1),
        // so subtract that result.
        int pickRight = nums[j] - solve(i, j - 1, nums);

        // The current player will choose the option that gives the larger advantage
        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // scoreDifference = (Player1 score - Player2 score) if both play optimally
        int scoreDifference = solve(0, n - 1, nums);

        // If scoreDifference >= 0, Player1 can either win or tie
        return scoreDifference >= 0;
    }
};

********************************************APPROACH 2nd(USING MEMOIZATION)*************************************

class Solution { // TC -> O(N^2), SC -> O(N^2)
public:
    // Recursive + Memoization function
    // Returns the maximum score difference (currentPlayer - opponent)
    // for subarray nums[i...j]
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case 1: If the range is invalid (i > j), no numbers remain
        // so the score difference is 0
        if (i > j) 
        {
            return 0;
        }

        // Base case 2: If only one number is left,
        // current player must take it, so difference = nums[i]
        if (i == j) 
        {
            return nums[i];
        }

        // If this subproblem was already solved, return stored result
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        // Choice 1: Current player picks nums[i]
        // After picking nums[i], the opponent plays optimally on (i+1...j),
        // so subtract that result from nums[i]
        int pickLeft = nums[i] - solve(i + 1, j, nums, dp);

        // Choice 2: Current player picks nums[j]
        // After picking nums[j], the opponent plays optimally on (i...j-1),
        // so subtract that result from nums[j]
        int pickRight = nums[j] - solve(i, j - 1, nums, dp);

        // Store the best option in dp table and return it
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Initialize DP table with -1 (means "uncomputed")
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // scoreDifference = (Player1 - Player2) if both play optimally
        int scoreDifference = solve(0, n - 1, nums, dp);

        // If scoreDifference >= 0, Player1 can win or tie
        return scoreDifference >= 0;
    }
};
