************************************************APPROACH 1st(BRUTE FORCE)********************************************

class Solution {// TC--->O(N^3)                            SC--->O(1)
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        // If there's only one point, max points on a line = 1
        if (n == 1) 
        {
            return 1;   
        }

        int ans = 0;  // stores the maximum number of points lying on a single line

        // Fix the first point 'i' as the base point
        for (int i = 0; i < n; i++) 
        {
            // Pick the second point 'j' to define a line with point 'i'
            for (int j = i + 1; j < n; j++) 
            {
                
                int count = 2;  // Line already has points i and j

                // Find slope between i and j
                int dy = points[j][1] - points[i][1];  // difference in y
                int dx = points[j][0] - points[i][0];  // difference in x

                // Now check every other point 'k' to see if it lies on the same line
                for (int k = 0; k < n; k++) 
                {
                    // skip the two points already on the line
                    if (k != i && k != j) 
                    {  
                        
                        int dy_ = points[k][1] - points[i][1];  // y difference (i, k)
                        int dx_ = points[k][0] - points[i][0];  // x difference (i, k)

                        // Check if slopes (i-j) and (i-k) are equal using cross multiplication
                        // dy/dx == dy_/dx_  →  dy * dx_ == dx * dy_
                        if (dy * dx_ == dx * dy_) 
                        {
                            count++;  // point k also lies on the same line
                        }
                    }
                }

                // Update global maximum
                ans = max(ans, count);
            }
        }

        // Return the maximum number of collinear points
        return ans;
    }
};


**************************************************APPROACH 2nd(OPTIMAL APPROACH)***********************************

class Solution {// TC--->O(N^2)                                     SC--->O(N)
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // If there is only one point, the answer is obviously 1
        if (n == 1) 
        {
            return 1;
        }

        int ans = 0;  // To store the final answer (max points on the same line)

        // Outer loop: fix one point as the reference point 'i'
        for (int i = 0; i < n; i++) 
        {
            // Hash map to store slope frequencies
            // key: slope represented as "dx_dy" (normalized)
            // value: how many points have this slope with point i
            unordered_map<string, int> ump;

            // Inner loop: compare every other point 'j' with point 'i'
            for (int j = 0; j < n; j++) 
            {
                if (i == j) 
                {
                    continue; // skip same point
                }

                // Calculate slope components (dy/dx)
                auto dy = points[j][1] - points[i][1];  // change in y
                auto dx = points[j][0] - points[i][0];  // change in x

                // Compute GCD to reduce the slope fraction (dy/dx)
                int gcd = __gcd(dy, dx);

                // Normalize the slope by dividing both by gcd
                // Example: slope (2,4) becomes (1,2)
                string key = to_string(dx / gcd) + "_" + to_string(dy / gcd);

                // Increment the frequency of this slope
                ump[key]++;
            }

            // Find the slope with the maximum frequency for this reference point
            for (auto &it : ump) 
            {
                // +1 to include the current point 'i' itself
                ans = max(ans, it.second + 1);
            }
        }

        // Return the maximum number of collinear points found
        return ans;
    }
};

🧠 Step-by-step Explanation

1. You fix one point i.

2. For every other point j, you compute the slope (dy/dx) between i and j.

3. You normalize this slope by dividing both dy and dx by their gcd,
   so that slopes like (2,4) and (1,2) are treated as the same.

4. You store each normalized slope in a hash map (unordered_map) —
   counting how many points have the same slope with respect to point i.

5. The line with the most repeated slope means the most points lie on the same line with point i.

6. You update ans with the max value found across all reference points.
