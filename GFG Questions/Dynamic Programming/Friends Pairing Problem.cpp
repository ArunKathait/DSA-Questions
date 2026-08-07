
class Solution {// TC ---> O(N)                                           SC ---> O(N)
public:

    // solve(n) returns the number of ways
    // n friends can remain single or get paired.
    //
    // dp stores already calculated answers
    int solve(int n, vector<int>& dp)
    {
        // Base case:
        //
        // If there are 0 friends:
        // No arrangement possible -> 0
        //
        // If there is 1 friend:
        // Only one option: remain single
        //
        // If there are 2 friends:
        // Options:
        // 1) Both remain single
        // 2) Both pair together
        //
        // Total = 2
        if(n <= 2)
        {
            return n;
        }


        // If answer is already calculated,
        // return it directly.
        //
        // This avoids repeated recursion calls.
        if(dp[n] != -1)
        {
            return dp[n];
        }


        // Case 1:
        //
        // The nth friend remains single.
        //
        // Remaining friends = n-1
        int single = solve(n - 1, dp);



        // Case 2:
        //
        // The nth friend pairs with someone.
        //
        // Choose a partner for nth friend:
        //
        // There are (n-1) choices.
        //
        // After choosing a partner:
        // Remaining friends = n-2
        //
        // Ways:
        // (n-1) * solve(n-2)
        int pair = (n - 1) * solve(n - 2, dp);



        // Total ways =
        // friends stays single +
        // friends gets paired
        //
        // Store answer in dp array
        return dp[n] = single + pair;
    }


    int countFriendsPairings(int n) {

        // dp[i] stores number of ways
        // for i friends.
        vector<int> dp(n + 1, -1);


        return solve(n, dp);
    }
};

/* NOTE:    

Main Recurrence

The important formula is:

f(n)=f(n−1)+(n−1)∗f(n−2)

Why (n-1) * solve(n-2)?

Suppose:

n = 4 friends

A B C D

Take friend D.

Option 1: D stays single

Remaining:

A B C

Ways:

f(3)

Option 2: D pairs with someone

D can choose:

A
B
C

Total:

3 choices = n-1

After pairing D:

Example:

D pairs with A

Remaining:

B C

Ways:

f(2)

So:

(n-1) * f(n-2)
