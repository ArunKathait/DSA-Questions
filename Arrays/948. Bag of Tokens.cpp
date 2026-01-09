
class Solution {// TC ---> O(nlogn)                              SC ---> O(1)
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        int n = tokens.size();

        // Sort tokens in ascending order
        // Smallest token → spend power to gain score
        // Largest token → spend score to gain power
        sort(tokens.begin(), tokens.end());

        // Two pointers
        int i = 0;        // points to smallest token
        int j = n - 1;    // points to largest token

        int score = 0;     // current score
        int maxScore = 0;  // maximum score achieved

        // Continue while there are tokens to consider
        while (i <= j) 
        {
            // Case 1: We have enough power to play the smallest token face up
            if (power >= tokens[i]) 
            {

                // Spend power to gain 1 score
                power -= tokens[i];
                score++;
                i++;  // move to next smallest token

                // Update maximum score
                maxScore = max(maxScore, score);
            }

            // Case 2: Not enough power, but we have score to trade
            else if (score >= 1) 
            {

                // Spend 1 score to gain power from the largest token
                score--;
                power += tokens[j];
                j--;  // move to next largest token
            }

            // Case 3: No power and no score → cannot play anymore
            else 
            {
                return maxScore;
            }
        }

        // Return the maximum score obtained
        return maxScore;
    }
};
