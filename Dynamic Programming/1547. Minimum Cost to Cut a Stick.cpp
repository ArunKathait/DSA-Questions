***************************************************APPROACH 1st(USING RECURSION)***************************************

class Solution {// TC ---> O(2^n)​                                SC ---> O(N)
public:
    /*
        This function returns the minimum cost to cut the stick
        between cuts[leftIndex] and cuts[rightIndex]
    */
    int findMinCost(int leftIndex, int rightIndex, vector<int>& cuts) {

        // Base case:
        // If there is no cut possible between leftIndex and rightIndex
        // (i.e., adjacent positions), cost is 0
        if (rightIndex - leftIndex <= 1) 
        {
            return 0;
        }

        int minimumCost = INT_MAX;

        // Try placing each possible cut between leftIndex and rightIndex
        for (int cutIndex = leftIndex + 1; cutIndex <= rightIndex - 1; cutIndex++) 
        {
            // Cost of making the current cut
            int currentCutCost = cuts[rightIndex] - cuts[leftIndex];

            // Recursively calculate left and right segment costs
            int costLeftPart  = findMinCost(leftIndex, cutIndex, cuts);
            int costRightPart = findMinCost(cutIndex, rightIndex, cuts);

            // Total cost for this choice of cut
            int totalCost = currentCutCost + costLeftPart + costRightPart;

            // Choose minimum among all possibilities
            minimumCost = min(minimumCost, totalCost);
        }

        return minimumCost;
    }

    int minCost(int stickLength, vector<int>& cuts) {

        // Sort cuts to process in correct order
        sort(cuts.begin(), cuts.end());

        // Add start (0) and end (stickLength) as boundaries
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(stickLength);

        int totalCuts = cuts.size();

        // Start recursion from full stick
        return findMinCost(0, totalCuts - 1, cuts);
    }
};

************************************************APPROACH 2nd(USING MEMOIZATION)*************************************

class Solution {// TC ---> O(N^3)                                    SC ---> O(N^2)
public: 
    /*
        This function returns the minimum cost to cut the stick
        between cuts[leftIndex] and cuts[rightIndex]
        dp[leftIndex][rightIndex] stores the already computed result
    */
    int solve(int leftIndex, int rightIndex,vector<int>& cuts,vector<vector<int>>& dp)
    {
        // Base case:
        // If there are no cuts possible between leftIndex and rightIndex
        if (rightIndex - leftIndex <= 1) 
        {
            return 0;
        }

        // If this subproblem is already solved, return it
        if (dp[leftIndex][rightIndex] != -1) 
        {
            return dp[leftIndex][rightIndex];
        }

        int minimumCost = INT_MAX;

        // Try all possible cuts between leftIndex and rightIndex
        for (int cutIndex = leftIndex + 1; cutIndex <= rightIndex - 1; cutIndex++) 
        {
            // Cost of making the current cut
            int currentSegmentCost = cuts[rightIndex] - cuts[leftIndex];

            // Cost of left and right segments after the cut
            int leftPartCost  = solve(leftIndex, cutIndex, cuts, dp);
            int rightPartCost = solve(cutIndex, rightIndex, cuts, dp);

            // Total cost if we cut at cutIndex
            int totalCost = currentSegmentCost + leftPartCost + rightPartCost;

            // Choose minimum cost among all possible cuts
            minimumCost = min(minimumCost, totalCost);
        }

        // Store and return result for this subproblem
        return dp[leftIndex][rightIndex] = minimumCost;
    }

    int minCost(int stickLength, vector<int>& cuts) {

        // Sort the cuts so they are in increasing order
        sort(cuts.begin(), cuts.end());

        // Add boundaries of the stick
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(stickLength);

        int totalCuts = cuts.size();

        // DP table where dp[i][j] represents minimum cost
        // to cut the stick between cuts[i] and cuts[j]
        vector<vector<int>> dp(totalCuts, vector<int>(totalCuts, -1));

        // Solve for the full stick
        return solve(0, totalCuts - 1, cuts, dp);
    }
};
