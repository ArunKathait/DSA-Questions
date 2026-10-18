

class Solution {// Time  : O(n²)                       Space : O(n²) 
public:
    // Modulo value to prevent numbers from becoming too large.
    int M = 1e9 + 7;

    // PT[i][j] stores the number of ways to choose j elements
    // from i elements, i.e., C(i, j).
    vector<vector<long long>> PT;

    int solve(vector<int>& nums) 
    {
        int m = nums.size();

        // If there are fewer than 3 elements, there is only
        // one ordering that needs to be counted at this level.
        if (m < 3) 
        {
            return 1;
        }

        vector<int> leftSide, rightSide;

        // The first element becomes the root of the BST.
        int root = nums[0];

        // Divide the remaining elements into left and right subtrees.
        for (int i = 1; i < m; i++) 
        {
            if (nums[i] < root) 
            {
                // Smaller values belong to the left subtree.
                leftSide.push_back(nums[i]);
            } 
            else 
            {
                // Larger values belong to the right subtree.
                rightSide.push_back(nums[i]);
            }
        }

        // Count the valid reorderings for the left subtree.
        long long leftWays = solve(leftSide) % M;

        // Count the valid reorderings for the right subtree.
        long long rightWays = solve(rightSide) % M;

        // We must preserve the relative order of elements within
        // each subtree, but can interleave left and right elements.
        //
        // There are m - 1 elements after the root.
        // Choose leftSide.size() positions for the left elements.
        // The remaining positions are filled by right elements.
        long long combinations = PT[m - 1][leftSide.size()];

        // Total ways = left subtree ways
        //            * right subtree ways
        //            * ways to interleave both subtrees.
        return (((leftWays * rightWays) % M) * combinations) % M;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Build Pascal's Triangle up to row n.
        // This allows us to calculate combinations C(i, j).
        PT.resize(n + 1);

        for (int i = 0; i <= n; i++) 
        {
            // Initialize row i with 1s.
            PT[i] = vector<long long>(i + 1, 1);

            // Pascal's Triangle recurrence:
            // C(i, j) = C(i-1, j-1) + C(i-1, j).
            for (int j = 1; j < i; j++) 
            {
                PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1][j]) % M;
            }
        }

        // solve(nums) includes the original ordering itself.
        // The question asks for other reorderings, so subtract 1.
        // Add M before taking modulo to avoid a negative result.
        return (solve(nums) - 1 + M) % M;
    }
};

/*

┌──────────────────────────────────────┐
│       REORDER ARRAY TO GET SAME BST  │
├──────────────────────────────────────┤
│ 1. First element = root              │
│ 2. Split into left (< root)          │
│    and right (> root)                │
│ 3. Recursively calculate leftWays    │
│    and rightWays                     │
│ 4. Interleave both subtrees using    │
│    C(m-1, leftSize)                  │
│ 5. Subtract 1 for original ordering  │
│                                      │
│ FORMULA:                             │
│ W = leftWays × rightWays             │
│     × C(m-1, leftSize)               │
│                                      │
│ Time  : O(n²)                        │
│ Space : O(n²)                        │
│                                      │
│ KEY IDEA: Pascal's Triangle gives    │
│ the number of ways to interleave     │
│ left and right subtree elements.     │
└──────────────────────────────────────┘

*/
