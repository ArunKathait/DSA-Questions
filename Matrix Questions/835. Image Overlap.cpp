*******************************************APPROACH 1st****************************************************************

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        // Store the coordinates of all 1s in img1.
        // Example: if img1[1][2] == 1,
        // we store {1, 2}.
        vector<pair<int, int>> a;

        // Store the coordinates of all 1s in img2.
        vector<pair<int, int>> b;


        // Traverse both matrices and collect positions of 1s.
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                // If current cell of img1 is 1,
                // store its row and column.
                if (img1[i][j] == 1) 
                {
                    a.push_back({i, j});
                }

                // If current cell of img2 is 1,
                // store its row and column.
                if (img2[i][j] == 1) 
                {
                    b.push_back({i, j});
                }
            }
        }


        // map stores:
        //
        //     shift (dx, dy) -> frequency
        //
        // If the same shift occurs many times,
        // it means many 1s can overlap using that same shift.
        //
        // Example:
        // (1,1) -> 3
        //
        // means 3 pairs of 1s have the same relative shift.
        map<pair<int, int>, int> mp;


        // Stores the maximum overlap found so far.
        int ans = 0;


        // Take every 1 from img1.
        for (auto p1 : a) 
        {
            // Take every 1 from img2.
            for (auto p2 : b) 
            {
                // p1 = position of a 1 in img1
                // p2 = position of a 1 in img2
                //
                // Suppose:
                // p1 = (1, 2)
                // p2 = (3, 4)
                //
                // To move p1 onto p2:
                //
                // row shift = 3 - 1 = 2
                // col shift = 4 - 2 = 2
                //
                // So the required shift is (2, 2).

                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;


                // Count how many pairs have this same shift.
                //
                // If the same (dx, dy) occurs again,
                // it means another pair of 1s also overlaps
                // using exactly the same movement.
                mp[{dx, dy}]++;


                // The frequency of this shift represents
                // how many 1s overlap for this particular shift.
                //
                // Keep the maximum frequency.
                ans = max(ans, mp[{dx, dy}]);
            }
        }

        // Maximum number of overlapping 1s.
        return ans;
    }
};

/*

╔════════════════════════════════════════════════════╗
║              IMAGE OVERLAP — CHEAT BOX             ║
╠════════════════════════════════════════════════════╣
║ 🎯 CORE IDEA                                       ║
║ Store coordinates of all 1s in both images.        ║
║ Same relative shift → those 1s overlap together.   ║
║                                                    ║
║ 📌 KEY FORMULA                                     ║
║ dx = r2 - r1                                       ║
║ dy = c2 - c1                                       ║
║                                                    ║
║ map[(dx,dy)]++                                     ║
║ → frequency = overlap for that shift               ║
║                                                    ║
║ 🔄 STEPS                                           ║
║ 1. Store positions of 1s in img1 → a               ║
║ 2. Store positions of 1s in img2 → b               ║
║ 3. Pair every p1 with every p2                     ║
║ 4. Calculate (dx,dy)                               ║
║ 5. Count frequency of each shift                   ║
║ 6. Maximum frequency = answer                      ║
║                                                    ║
║ 🧠 INTUITION                                       ║
║ Same shift occurring multiple times means          ║
║ multiple 1s align after one translation.           ║
║                                                    ║
║ ⏱ TIME                                             ║
║ O(n² + k1×k2×log(k1×k2))                           ║
║ Worst: O(n⁴ log n)                                 ║
║                                                    ║
║ 💾 SPACE                                           ║
║ O(k1 + k2 + k1×k2)                                 ║
║ Worst: O(n⁴)                                       ║
╚════════════════════════════════════════════════════╝

*/

*********************************************APPROACH 2nd************************************************************

class Solution {// Time  : O(n⁴)                                   Space : O(1) 
public:

    // This function calculates how many 1s overlap
    // when matrix B is shifted by (rowOffSet, colOffSet)
    // relative to matrix A.
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffSet, int colOffSet)
    {
        int n = A.size();

        // Stores the number of positions where
        // A[i][j] == 1 and the shifted B position == 1.
        int count = 0;

        // Visit every cell of matrix A.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If A[i][j] is compared with B,
                // after shifting B by (rowOffSet, colOffSet),
                // the corresponding position in B becomes:
                //
                // B_i = i + rowOffSet
                // B_j = j + colOffSet
                int B_i = i + rowOffSet;
                int B_j = j + colOffSet;

                // The shifted position may go outside
                // the boundaries of matrix B.
                //
                // Example:
                // If B_i = -1, there is no such row in B.
                //
                // So simply ignore this position.
                if (B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                {
                    continue;
                }

                // Now both positions are valid.
                //
                // If A[i][j] == 1
                // AND
                // B[B_i][B_j] == 1
                //
                // then these two 1s overlap.
                if (A[i][j] == 1 && B[B_i][B_j] == 1)
                {
                    count++;
                }
            }
        }

        // Return the number of overlapping 1s
        // for this particular shift.
        return count;
    }


    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int n = img1.size();

        // Stores the maximum overlap found
        // among all possible shifts.
        int maxOverlap = 0;


        // Try every possible row shift.
        //
        // Possible row offsets are:
        // -(n-1) ... 0 ... +(n-1)
        //
        // Example for n = 3:
        // -2, -1, 0, 1, 2
        for (int rowOffSet = -n + 1; rowOffSet < n; rowOffSet++)
        {
            // Try every possible column shift.
            //
            // Again, possible values are:
            // -(n-1) ... +(n-1)
            for (int colOffSet = -n + 1;colOffSet < n; colOffSet++)
            {
                // Calculate the overlap between img1
                // and img2 for the current shift.
                int count = countOverlaps(img1,img2,rowOffSet,colOffSet);

                // Keep the maximum overlap found so far.
                maxOverlap = max(maxOverlap, count);
            }
        }

        // After trying every possible translation,
        // return the largest overlap.
        return maxOverlap;
    }
};

/*

╔══════════════════════════════════════════════════╗
║        IMAGE OVERLAP — BRUTE FORCE               ║
╠══════════════════════════════════════════════════╣
║ 🎯 CORE IDEA                                     ║
║ Try every possible row + column shift.           ║
║ For each shift, count overlapping 1s.            ║
║                                                  ║
║ 🔑 KEY FORMULA                                   ║
║ B_i = i + rowOffset                              ║
║ B_j = j + colOffset                              ║
║                                                  ║
║ If B_i/B_j are valid AND                         ║
║ A[i][j] == 1 && B[B_i][B_j] == 1                 ║
║ → count++                                        ║
║                                                  ║
║ 🔄 STEPS                                         ║
║ 1. Try rowOffset = -(n-1) ... (n-1)              ║
║ 2. Try colOffset = -(n-1) ... (n-1)              ║
║ 3. Compare every cell                            ║
║ 4. Count overlapping 1s                          ║
║ 5. Keep maximum                                  ║
║                                                  ║
║ ⏱ TIME  : O(n⁴)                                  ║
║ 💾 SPACE : O(1)                                  ║
╚══════════════════════════════════════════════════╝

*/
