
class Solution {// TC--->O(3N)                                SC--->O(3N)
public: 
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        // Arrays to store the nearest 'R' to the left and 'L' to the right for each position
        vector<int> leftClosestR(n);
        vector<int> rightClosestL(n);

        // Fill leftClosestR[]: find the nearest 'R' to the left (or same position)
        for (int i = 0; i < n; i++) 
        {
            if (dominoes[i] == 'R') 
            {
                leftClosestR[i] = i;  // If current is 'R', store its index
            }
            else if (dominoes[i] == '.') 
            {
                // If '.', inherit the previous closest R (or -1 if none)
                leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
            }
            else 
            {
                // If 'L', no force from left R can reach here
                leftClosestR[i] = -1;
            }
        }

        // Fill rightClosestL[]: find the nearest 'L' to the right (or same position)
        for (int i = n - 1; i >= 0; i--) 
        {
            if (dominoes[i] == 'L') 
            {
                 // If current is 'L', store its index
                rightClosestL[i] = i; 
            }
            else if (dominoes[i] == '.') 
            {
                // If '.', inherit the next closest L (or -1 if none)
                rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
            }
            else 
            {
                // If 'R', no force from right L can reach here
                rightClosestL[i] = -1;
            }
        }

        // Prepare result string with empty placeholders
        string ans(n, ' ');

        // Decide the final direction of each domino
        for (int i = 0; i < n; i++) 
        {
            int distLeftR = abs(i - leftClosestR[i]);     // Distance to nearest 'R' on the left
            int distRightL = abs(i - rightClosestL[i]);   // Distance to nearest 'L' on the right

            if (leftClosestR[i] == rightClosestL[i]) 
            {
                // If both are same (or both are -1), domino stays upright
                ans[i] = '.';
            }
            else if (leftClosestR[i] == -1) 
            {
                // Only 'L' force affects it
                ans[i] = 'L';
            }
            else if (rightClosestL[i] == -1) 
            {
                // Only 'R' force affects it
                ans[i] = 'R';
            }
            else if (distLeftR == distRightL) 
            {
                // Equal distance to both forces => cancel out
                ans[i] = '.';
            }
            else 
            {
                // Choose the closer force: 'R' if left R is closer, otherwise 'L'
                ans[i] = distLeftR < distRightL ? 'R' : 'L';
            }
        }

        return ans;  // Return final state of dominoes
    }
};
