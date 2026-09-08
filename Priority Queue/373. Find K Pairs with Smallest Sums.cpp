************************************************APPROACH 1st**********************************************************
class Solution {// Time: O(n × m × log k)                                     Space: O(k)
public:

    // P represents:
    // {
    //     sum of pair,
    //     {index of nums1, index of nums2}
    // }
    //
    // Example:
    // nums1 = [1, 7]
    // nums2 = [2, 4]
    //
    // Pair (1,2):
    // sum = 3, i = 0, j = 0
    //
    // So:
    // {3, {0, 0}}
    typedef pair<int, pair<int,int>> P;


    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        int m = nums2.size();

        // Max-heap.
        //
        // The largest sum among the elements currently
        // stored in the heap will always be at pq.top().
        //
        // We maintain at most k elements in this heap.
        priority_queue<P> pq;


        // Try every possible pair.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Calculate the sum of the current pair.
                int sum = nums1[i] + nums2[j];


                // If we haven't collected k pairs yet,
                // simply insert the current pair.
                if(pq.size() < k)
                {
                    pq.push({sum, {i, j}});
                }


                // If we already have k pairs,
                // compare the current sum with the
                // largest sum currently in the heap.
                //
                // Since this is a MAX heap:
                // pq.top() = pair having the largest sum.
                //
                // If current sum is smaller, then the
                // current pair deserves to be in the
                // k smallest pairs.
                else if(pq.top().first > sum)
                {
                    // Remove the largest sum.
                    pq.pop();

                    // Add the smaller sum.
                    pq.push({sum, {i, j}});
                }


                // nums2 is sorted.
                //
                // Therefore, for the same i:
                //
                // nums1[i] + nums2[j+1]
                //
                // will be >=
                //
                // nums1[i] + nums2[j]
                //
                // So if the current sum is already >=
                // the largest sum in our heap, later
                // j values cannot improve the answer.
                else
                {
                    break;
                }
            }
        }


        // Store the final k pairs.
        vector<vector<int>> ans;


        // The max-heap contains the k smallest sums,
        // but in decreasing order.
        //
        // We remove elements from the heap one by one
        // and construct the actual pairs.
        while(!pq.empty())
        {
            auto pair = pq.top();
            pq.pop();

            // Extract indices.
            int i = pair.second.first;
            int j = pair.second.second;

            // Convert indices back to actual values.
            ans.push_back({nums1[i], nums2[j]});
        }


        return ans;
    }
};

*************************************************APPROACH 2nd(OPTIMAL)************************************************

class Solution {// Time: O(k log k)                                         Space: O(k)
public:

    // P represents one entry in the priority queue.
    //
    // Structure:
    //
    // {
    //     sum,
    //     {i, j}
    // }
    //
    // sum = nums1[i] + nums2[j]
    // i   = index in nums1
    // j   = index in nums2
    //
    // Example:
    // nums1 = [1, 7]
    // nums2 = [2, 4]
    //
    // Pair (1,2):
    // sum = 3
    // i = 0, j = 0
    //
    // Therefore:
    // {3, {0,0}}
    typedef pair<int,pair<int,int>> P;


    vector<vector<int>> kSmallestPairs(vector<int>& nums1,vector<int>& nums2,int k) 
    {
        // Size of both arrays.
        int n = nums1.size();
        int m = nums2.size();


        // Min-heap.
        //
        // The pair having the smallest SUM will always
        // be available at pq.top().
        //
        // Normally priority_queue is a MAX heap.
        //
        // greater<P> changes it into a MIN heap.
        priority_queue<P, vector<P>, greater<P>> pq;


        // Stores index pairs that have already been
        // inserted into the priority queue.
        //
        // Example:
        // visited = {(0,0), (1,0), (0,1)}
        //
        // This prevents the same index pair from
        // being inserted multiple times.
        set<pair<int,int>> visited;


        // Since both arrays are sorted, the smallest
        // possible pair is:
        //
        // nums1[0] + nums2[0]
        //
        // So we start our search from (0,0).
        int sum = nums1[0] + nums2[0];

        // Insert:
        //
        // {
        //     sum,
        //     {0,0}
        // }
        //
        // into the min-heap.
        pq.push({sum,{0,0}});


        // Mark (0,0) as visited because it is already
        // present in the priority queue.
        visited.insert({0,0});


        // Stores the k smallest pairs.
        vector<vector<int>> ans;


        // We need at most k pairs.
        //
        // Each iteration removes one pair from the
        // min-heap.
        //
        // !pq.empty() makes sure the heap still has
        // some candidate pairs.
        while(k-- && !pq.empty())
        {

            // Get the pair with the smallest sum.
            auto pair = pq.top();

            // Remove it from the heap.
            pq.pop();


            // Extract the indices from the pair.
            //
            // pair.first  = sum
            // pair.second = {i,j}
            int i = pair.second.first;
            int j = pair.second.second;


            // Add the actual values to the answer.
            //
            // pair = (nums1[i], nums2[j])
            ans.push_back({nums1[i],nums2[j]});


            // ------------------------------------------------
            // Generate the DOWN neighbor
            // ------------------------------------------------
            //
            // Current position:
            //
            //       (i,j)
            //
            // Move down:
            //
            //       (i+1,j)
            //
            // This means we take the next element from nums1
            // while keeping the same element from nums2.
            if(i+1 < n && visited.find({i+1,j}) == visited.end())
            {

                // Calculate the sum of the new pair.
                //
                // nums1[i+1] + nums2[j]
                pq.push({nums1[i+1] + nums2[j],{i+1,j}});


                // Mark this index pair as visited.
                //
                // This prevents the same pair from
                // entering the heap again.
                visited.insert({i+1,j});
            }


            // ------------------------------------------------
            // Generate the RIGHT neighbor
            // ------------------------------------------------
            //
            // Current position:
            //
            //       (i,j)
            //
            // Move right:
            //
            //       (i,j+1)
            //
            // This means we keep the same element from nums1
            // and take the next element from nums2.
            if(j+1 < m && visited.find({i,j+1}) == visited.end())
            {

                // Calculate the sum of the new pair.
                //
                // nums1[i] + nums2[j+1]
                pq.push({nums1[i] + nums2[j+1],{i,j+1}});


                // Mark this index pair as visited.
                visited.insert({i,j+1});
            }
        }


        // Return the k smallest pairs.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│          K SMALLEST PAIRS — 373              │
├──────────────────────────────────────────────┤
│ Pattern: Min-Heap + Visited                  │
│                                              │
│ Treat pairs as a 2D grid:                    │
│                                              │
│          nums2 →                             │
│        2   4   6                             │
│ nums1 1 | 3   5   7                          │
│       7 | 9  11  13                          │
│      11 |13  15  17                          │
│                                              │
│ Start from (0,0)                             │
│ → smallest possible pair                     │
│                                              │
│ Min-Heap stores:                             │
│ {sum, {i,j}}                                 │
│                                              │
│ pq.top()                                     │
│ → pair with smallest sum                     │
│                                              │
│ From (i,j), generate:                        │
│                                              │
│ 1. DOWN  → (i+1, j)                          │
│    nums1[i+1] + nums2[j]                     │
│                                              │
│ 2. RIGHT → (i, j+1)                          │
│    nums1[i] + nums2[j+1]                     │
│                                              │
│ visited prevents duplicate index pairs.      │
│                                              │
│ Process:                                     │
│ → Pop smallest pair                          │
│ → Add to answer                              │
│ → Push DOWN neighbor                         │
│ → Push RIGHT neighbor                        │
│ → Repeat k times                             │
│                                              │
│ Why Min-Heap?                                │
│ → Always gives smallest available sum        │
│                                              │
│ Why visited?                                 │
│ → Same (i,j) can be reached from 2 paths     │
│                                              │
│ Time  : O(k log k)                           │
│ Space : O(k)                                 │ 
└──────────────────────────────────────────────┘

🎯 Remember
START → (0,0)
          ↓
     MIN HEAP
          ↓
     smallest pair
        ↙     ↘
      DOWN    RIGHT
        ↓       ↓
    visited check
          ↓
       repeat k
       
*/
