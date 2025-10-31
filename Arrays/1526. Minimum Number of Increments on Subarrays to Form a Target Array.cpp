
class Solution {// TC ---> O(N)                            SC ---> O(1)
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        // Start with the first number in target.
        // Because to make the first element 'target[0]' from 0,
        // we need at least 'target[0]' operations.
        int operations = target[0];

        // Traverse the array from the second element onwards.
        for (int i = 1; i < n; i++) 
        {
            // If the current height is greater than the previous one,
            // it means we need extra operations to increase
            // from target[i-1] → target[i].
            if (target[i - 1] < target[i]) 
            {
                // Add only the difference (increase amount).
                operations += (target[i] - target[i - 1]);
            }
            // If target[i] <= target[i-1], 
            // we don't need extra operations because
            // we can "reduce" height freely without extra cost.
        }

        // Return the total number of operations needed
        // to form the entire 'target' array.
        return operations;
    }
};

/* 
 NOTE :
         🧠 Logic Explanation

             Think of the array as a series of bars (like a histogram).
             You start from an empty array of 0s and want to build target.

             Each time the height increases, you must perform extra operations.

             When height decreases, no new operations are needed (you can just stop increasing).

             So you just count all the positive increases in height.
  */
