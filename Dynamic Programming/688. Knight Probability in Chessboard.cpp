*************************************************APPROACH 1st(RECURSION)***********************************************

class Solution {// TC--->O(8^k)                                 SC--->O(k)
public:

    // Recursive function to calculate the probability that the knight
    // remains on the chessboard after 'k' moves.
    double solve(int row, int col, int n, int k)
    {
        // Base Case 1: If the knight goes outside the board
        // Probability becomes 0 because the knight is out.
        if (row < 0 || col < 0 || row >= n || col >= n)
        {
            return 0;
        }

        // Base Case 2: If no moves are left (k == 0)
        // It means the knight is still on the board, so probability = 1.
        if (k == 0)
        {
            return 1;
        }

        // Possible moves of a knight in chess:
        // (row change, column change) for all 8 directions
        vector<int> delRow = {-2, -2, -1, 1, 2, 2, 1, -1};
        vector<int> delCol = {-1, 1, 2, 2, 1, -1, -2, -2};

        // 'ans' stores the total probability of staying on board
        double ans = 0;

        // Explore all 8 possible knight moves
        for (int j = 0; j < 8; j++)
        {
            // Calculate new position after the knight moves
            int newRow = row + delRow[j];
            int newCol = col + delCol[j];

            // Recursively calculate the probability from this new position
            // with one fewer move remaining (k - 1)
            // Each move has equal probability (1/8), so divide by 8
            ans += (double)solve(newRow, newCol, n, k - 1) / 8.0;
        }

        // Return total probability from this cell and step count
        return ans;
    }

    // Main function: Entry point
    double knightProbability(int n, int k, int row, int column)
    {
        // Start recursion from the initial position (row, column)
        // on an 'n x n' chessboard, with 'k' total moves allowed
        return solve(row, column, n, k);
    }
};

***********************************************APPROACH 2nd(USING MEMOIZATION)**************************************

class Solution { // ✅ Time Complexity → O(n² * k), because each state (row, col, k) is computed once
                 // ✅ Space Complexity → O(n² * k) for dp + O(k) recursion stack

public:

    // Recursive helper function that calculates the probability that
    // a knight remains on the chessboard after 'k' moves starting from (row, col)
    double solve(int row, int col, int n, int k, vector<vector<vector<double>>>& dp)
    {
        // 🧩 Base Case 1: If knight moves outside the chessboard boundaries,
        // it’s no longer on the board → probability = 0
        if (row < 0 || col < 0 || row >= n || col >= n)
        {
            return 0;
        }

        // 🧩 Base Case 2: If no moves left (k == 0),
        // that means the knight is still on the board → probability = 1
        if (k == 0)
        {
            return 1;
        }

        // ⚡ Memoization check:
        // If this state (row, col, k) was already calculated, just return it
        if (dp[row][col][k] != -1)
        {
            return dp[row][col][k];
        }

        // ♞ Possible knight moves in chess (8 directions)
        // Each pair of (row, col) represents one possible L-shaped move
        vector<int> delRow = {-2, -2, -1, 1, 2, 2, 1, -1};
        vector<int> delCol = {-1, 1, 2, 2, 1, -1, -2, -2};

        // 🧮 Variable to accumulate total probability from all 8 moves
        double ans = 0;

        // 🔁 Try all 8 possible moves from current position
        for (int j = 0; j < 8; j++)
        {
            // Calculate new row and column after the knight moves
            int newRow = row + delRow[j];
            int newCol = col + delCol[j];

            // Each move has equal probability (1/8)
            // Recursively find probability from new position with one fewer move (k - 1)
            ans += solve(newRow, newCol, n, k - 1, dp) / 8.0;
        }

        // 💾 Store the result in dp to avoid recomputation
        dp[row][col][k] = ans;

        // Return final probability for current (row, col, k)
        return ans;
    }

    // 🏁 Main function: entry point of the algorithm
    double knightProbability(int n, int k, int row, int column)
    {
        // 🧱 3D DP array:
        // dp[row][col][k] stores probability that knight stays on board
        // starting from (row, col) with k moves remaining
        vector<vector<vector<double>>> dp(
            n, vector<vector<double>>(n, vector<double>(k + 1, -1.0))
        );

        // 🚀 Start recursion from given (row, column)
        // and return the probability that knight stays on board after k moves
        return solve(row, column, n, k, dp);
    }
};

******************************************************APPROACH 3rd(USING MAP FOR MEMOIZATION)***************************************************

class Solution {
public:
    // Recursive helper function that calculates probability
    // of knight staying on board starting from (row, col) with k moves left
    double solve(int row, int col, int n, int k, map<string,double>& dp) {

        // 🧩 Base Case 1: If knight goes outside the board
        if(row < 0 || col < 0 || row >= n || col >= n)
        {
            return 0;
        }

        // 🧩 Base Case 2: If no moves are left (k == 0),
        // the knight is still on the board → probability = 1
        if(k == 0)
        {
            return 1;
        }

        // ⚡ Memoization key: uniquely identify each state
        // Format: "row-col-k"
        string key = to_string(row) + "-" + to_string(col) + "-" + to_string(k);

        // ⚡ Check if this state is already computed
        if(dp.find(key) != dp.end())
        {
            return dp[key];
        }

        // ♞ Knight's 8 possible moves
        vector<int> delRow = {-2, -2, -1, 1, 2, 2, 1, -1};
        vector<int> delCol = {-1, 1, 2, 2, 1, -1, -2, -2};

        // 🧮 Variable to accumulate total probability from all 8 moves
        double ans = 0;

        // 🔁 Explore all 8 possible knight moves
        for(int i = 0; i < 8; i++) 
        {
            int newRow = row + delRow[i];  // new row after knight move
            int newCol = col + delCol[i];  // new column after knight move

            // Recursively calculate probability from new position
            // Each move has equal chance = 1/8
            ans += solve(newRow, newCol, n, k-1, dp) / 8.0;
        }

        // 💾 Store computed probability in map to avoid recomputation
        dp[key] = ans;

        // 🔙 Return probability for current state
        return ans;
    }

    // Main function: entry point
    double knightProbability(int n, int k, int row, int column) {
        // 🗺️ Map for memoization: stores probability of each (row,col,k)
        map<string,double> dp;

        // 🚀 Start recursion from initial knight position (row,column) with k moves
        return solve(row, column, n, k, dp);
    }
};
