********************************************APPROACH 1st(USING RECURSION)***********************************

class Solution {// TC--->O(2^N)                            SC--->O(N)--->Recursion Stack
public:
    // Recursive function to find the maximum points that can be earned
    long long solve(int index,int n,vector<vector<int>>&questions)
    {
         // Base case: If index goes out of bounds, return 0 (no more questions to solve)
         if(index >= n)
         {
            return 0;
         }

        
        // Option 1: Take the current question
        // - Earn `questions[index][0]` points (point value of current question)
        // - Move to the next available question after skipping `questions[index][1]` questions 
         long long take = questions[index][0] + solve((questions[index][1] + index + 1),n,questions);
         
         // Option 2: Skip the current question and move to the next question
         long long not_take = solve(index + 1,n,questions);

         // Return the maximum of both choices
         return max(take,not_take);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        // Start solving from index 0
        return solve(0,n,questions);
    }
};


****************************************APPROACH 2(USING MEMOIZATION)*******************************************

class Solution {// TC--->O(N)                               SC--->O(N)
public:
    // Recursive function with memoization to solve the problem
    long long solve(int index,int n,vector<vector<int>>&questions,vector<long long>&dp)
    {
         // Base case: If index goes beyond the total number of questions, return 0
         if(index >= n)
         {
            return 0;
         }

         // If the result for this index is already computed, return it (memoization)
         if(dp[index] != -1)
         {
            return dp[index];
         }
         
         // Option 1: Take the current question
        // Gain = questions[index][0] (points for this question)
        // Next question we can take = index + questions[index][1] + 1 (as we must skip "questions[index][1]" questions)
         long long take = questions[index][0] + solve((questions[index][1] + index + 1),n,questions,dp);
         
         // Option 2: Skip the current question and move to the next one
         long long not_take = solve(index + 1,n,questions,dp);

         // Store the maximum of both choices in dp array and return it
         return dp[index] = max(take,not_take);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        // Initialize DP array with -1 to indicate uncomputed values
        vector<long long>dp(n,-1);

        // Start solving from question index 0
        return solve(0,n,questions,dp);
    }
};

***************************************APPROACH 3rd(USING TABULATION)***************************************

class Solution {// TC--->O(N)                                     SC--->O(N)
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // Get the total number of questions
        int n = questions.size();

        // If there's only one question, return its points directly
        if(n == 1)
        {
            return questions[0][0];
        }

        // DP array to store max points from index 'i' to 'n-1'
        vector<long long>dp(n+1,0);

        // Iterate from the last question to the first
        for(int i=n-1;i>=0;i--)
        {
            // Points for solving the current question
            long long take = questions[i][0]; 

            // Jump to the next valid question
            int next_index = i + questions[i][1] + 1;

            // If the next valid question is within bounds, add its max points
            if(next_index < n)
            {
                take += dp[next_index];
            }

            // If we skip this question
            long long not_take = dp[i+1];

            // Store the max points possible from this index onwards
            dp[i] = max(take,not_take);
        }
        
        // Answer is stored in dp[0] (max points starting from first question)
       return dp[0];
    }
};


/*   *************Space Optimisation******************** TC--->O(N)                SC--->O(1)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long next = 0, curr = 0; // `curr` = dp[i], `next` = dp[i+1]

        for(int i = n - 1; i >= 0; i--) {
            long long take = questions[i][0]; 
            int next_index = i + questions[i][1] + 1;

            if(next_index < n) {
                take += next; // Use the stored next value instead of dp[next_index]
            }

            long long not_take = curr; // dp[i+1] stored in `curr`

            long long temp = max(take, not_take);
            next = curr; // Move `curr` to `next`
            curr = temp; // Update `curr` to new max
        }

        return curr; // Answer is stored in `curr` (equivalent to dp[0])
    }
};

*/
