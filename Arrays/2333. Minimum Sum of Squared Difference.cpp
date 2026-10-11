***********************************************APPROACH 1st(PRIORITY - QUEUE)******************************************

class Solution {// Time  : O(n + K log n)              Space : O(n)
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        // Max heap: the largest difference stays at the top.
        // We reduce the largest difference first to minimize
        // the sum of squared differences.
        priority_queue<int> pq;

        // Calculate the absolute difference at each index
        // and insert it into the max heap.
        for (int i = 0; i < n; i++) 
        {
            pq.push(abs(nums1[i] - nums2[i]));
        }

        // Total number of operations available across both arrays.
        int K = k1 + k2;

        // Perform at most K operations.
        // Stop early if the largest difference becomes zero,
        // because no difference can be reduced below zero.
        while (K-- && pq.top() > 0) 
        {
            // Get the largest difference.
            int val = pq.top();
            pq.pop();

            // Reduce this difference by one.
            // This is optimal because reducing a larger difference
            // gives a greater reduction in the squared sum.
            pq.push(val - 1);
        }

        // Calculate the sum of squared differences.
        long long ans = 0;

        while (!pq.empty()) 
        {
            int num = pq.top();
            pq.pop();

            // Add the square of the current difference.
            // Cast to long long before multiplication to avoid
            // integer overflow in num * num.
            ans += 1LL * num * num;
        }

        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│       MIN SUM SQUARE DIFF           │
├─────────────────────────────────────┤
│                                     │
│ diff[i] = abs(nums1[i] - nums2[i])  │
│ K = k1 + k2                         │
│                                     │
│ MAX HEAP:                           │
│ Largest difference stays on top     │
│                                     │
│ Repeat K times:                     │
│   Get largest difference            │
│   Reduce it by 1                    │
│   Push it back into heap            │
│                                     │
│ Stop if maximum difference is 0     │
│                                     │
│ FINAL: Sum of diff[i]²              │
│                                     │
│ KEY TRICK: Reduce largest first     │
│                                     │
│ Time  : O(n + K log n)              │
│ Space : O(n)                        │
└─────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(OPTIMAL)***********************************************


class Solution {// Time  : O(n + D)                    Space : O(D)  
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();

        // countDiff[d] stores the number of elements
        // whose absolute difference is exactly d.
        // Maximum possible difference is 100000.
        vector<int> countDiff(1e5 + 1, 0);

        // Step 1: Calculate differences and count their frequencies.
        for (int i = 0; i < n; i++) 
        {
            int d = abs(nums1[i] - nums2[i]);

            // One element has difference d.
            countDiff[d]++;
        }

        // Total operations available from both arrays.
        int K = k1 + k2;

        // Step 2: Reduce the largest differences first.
        // Start from the maximum possible difference and go down to 1.
        for (int currDiff = 1e5; currDiff > 0 && K > 0; currDiff--) 
        {
            // We can reduce at most:
            // 1. K operations available
            // 2. countDiff[currDiff] elements at this difference
            int countOps = min(K, countDiff[currDiff]);

            // These elements move from difference currDiff
            // to difference currDiff - 1.
            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;

            // Each reduction uses one operation.
            K -= countOps;
        }

        // Step 3: Calculate the sum of squared differences.
        long long ans = 0;

        for (long long d = 0; d <= 1e5; d++) 
        {
            // If countDiff[d] elements have difference d,
            // their total contribution is countDiff[d] * d * d.
            ans += (1LL * countDiff[d] * d * d);
        }

        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│     MIN SUM SQUARE DIFFERENCE       │
├─────────────────────────────────────┤
│ 1. Initialize countDiff[100001]     │
│                                     │
│ 2. Count absolute differences       │
│    d = abs(nums1[i] - nums2[i])     │
│    countDiff[d]++                   │
│                                     │
│ 3. K = k1 + k2                      │
│                                     │
│ 4. Traverse d from 100000 to 1      │
│    countOps = min(K, countDiff[d])  │
│    countDiff[d] -= countOps         │
│    countDiff[d-1] += countOps       │
│    K -= countOps                    │
│                                     │
│ 5. Calculate final answer           │
│    ans += countDiff[d] * d * d      │
│                                     │
│ KEY TRICK:                          │
│ Reduce largest differences first    │
│ Process equal differences in batch  │
│                                     │
│ Time  : O(n + D)                    │
│ Space : O(D)                        │
│ D = 100000                          │
└─────────────────────────────────────┘

*/
