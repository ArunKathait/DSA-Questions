
class Solution {// TC ---> O(NLogN)                    SC ---> O(k)
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        // Number of children
        int n = happiness.size();

        // Sort happiness in descending order
        // So that we pick the happiest children first
        sort(happiness.begin(), happiness.end(), greater<int>());

        // This will store the maximum total happiness
        long long ans = 0;

        // Select k children (one per turn)
        for(int i = 0; i < k; i++)
        {
            // After i turns, happiness of remaining children
            // is reduced by i
            int current = happiness[i] - i;

            // Happiness cannot be negative
            if(current > 0)
            {
                // Add the effective happiness to the answer
                ans += current;
            }
            // If current <= 0, we add nothing (0 contribution)
        }

        // Return the maximum happiness sum
        return ans;
    }
};
