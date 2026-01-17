
class Solution {// TC ---> O(H² + V²)                              SC ---> O(H²)
public:
    // Mod value as required by the problem
    int M = 1e9 + 7;

    int maximizeSquareArea(int m, int n,vector<int>& hFences,vector<int>& vFences) {

        // Add boundary fences for horizontal direction
        // so that edges of the grid are also considered
        hFences.push_back(1);
        hFences.push_back(m);

        // Add boundary fences for vertical direction
        vFences.push_back(1);
        vFences.push_back(n);

        // Sort fence positions to compute distances correctly
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Set to store all possible heights formed
        // by choosing any two horizontal fences
        unordered_set<int> heights;

        int maxSide = 0;

        // ----------- Compute all possible heights -----------
        for (int i = 0; i < hFences.size(); i++) 
        {
            for (int j = i + 1; j < hFences.size(); j++) 
            {
                // Distance between two horizontal fences
                int height = hFences[j] - hFences[i];
                heights.insert(height);
            }
        }

        // ----------- Check vertical widths -----------
        for (int i = 0; i < vFences.size(); i++) 
        {
            for (int j = i + 1; j < vFences.size(); j++) 
            {
                // Distance between two vertical fences
                int width = vFences[j] - vFences[i];

                // If same distance exists in horizontal heights,
                // it can form a square
                if (heights.find(width) != heights.end()) 
                {
                    maxSide = max(maxSide, width);
                }
            }
        }

        // If no square is possible, return -1
        // Else return area of the largest square modulo M
        return maxSide == 0 ? -1 : (1LL * maxSide * maxSide) % M;
    }
};
