
class Solution {// Time  : O(n²)            Space : O(n)
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;

        // Fix every point i as the MIDDLE point of the boomerang.
        //
        // A boomerang (i, j, k) requires:
        // distance(i, j) == distance(i, k)
        //
        // So for every fixed i, we count how many points
        // are at each distance from i.
        for(int i = 0; i < n; i++)
        {
            // IMPORTANT:
            // This map must be created for every new i.
            //
            // ump[dist] = number of points already seen
            // having the same distance 'dist' from point i.
            unordered_map<int, int> ump;

            for(int j = 0; j < n; j++)
            {
                // A point cannot form a boomerang with itself.
                if(i == j)
                {
                    continue;
                }

                // Coordinates of point i
                int x1 = points[i][0];
                int y1 = points[i][1];

                // Coordinates of point j
                int x2 = points[j][0];
                int y2 = points[j][1];

                // Difference in x and y coordinates
                int dx = x1 - x2;
                int dy = y1 - y2;

                // Squared Euclidean distance.
                //
                // We don't need sqrt(), because:
                //
                // distance1 == distance2
                //
                // is equivalent to:
                //
                // distance1^2 == distance2^2
                //
                // Using squared distance is faster and avoids
                // floating-point calculations.
                int dist = (dx * dx) + (dy * dy);

                // Suppose this distance has already appeared
                // 'ump[dist]' times.
                //
                // The current point j can be paired with EACH
                // of those previous points.
                //
                // Why multiply by 2?
                //
                // Because a boomerang is ORDERED:
                //
                // (i, j, k)
                // (i, k, j)
                //
                // are two different boomerangs.
                //
                // Therefore, each previous point gives 2 new
                // boomerangs.
                ans += 2 * ump[dist];

                // Now include the current point in the map.
                ump[dist]++;
            }
        }

        return ans;
    }
};

/*  

┌──────────────────────────────────────────┐
│           BOOMERANG APPROACH             │
├──────────────────────────────────────────┤
│                                          │
│ Fix i = middle point                     │
│                                          │
│ Calculate distance(i, j) for every j    │
│                                          │
│ Map: distance → frequency                │
│                                          │
│ Same distance means:                     │
│ distance(i,j) == distance(i,k)           │
│                                          │
│ If frequency = k:                        │
│     contribution = k × (k - 1)           │
│                                          │
│ Incremental form:                        │
│     ans += 2 × ump[dist]                 │
│                                          │
│ IMPORTANT:                               │
│ unordered_map must be reset for every i  │
│                                          │
│ Time  : O(n²) average                    │
│ Space : O(n) average                     │
└──────────────────────────────────────────┘

*/
