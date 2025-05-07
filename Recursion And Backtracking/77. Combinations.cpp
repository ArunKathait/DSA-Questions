*******************************************APPROACH 1st(BRUTE FORCE)**********************************************

class Solution {
public:
    // Helper function to generate all combinations
    void solve(int index, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int k) {
        // If we've picked exactly k elements, add the current combination to the result
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // If we've reached the end of the nums array, return
        if (index == n) return;

        // ------------------- Include nums[index] -------------------

        temp.push_back(nums[index]);         // Choose the current element
        solve(index + 1, n, nums, temp, ans, k); // Recurse to the next index
        temp.pop_back();                     // Backtrack: remove the last added element

        // ------------------- Exclude nums[index] -------------------

        solve(index + 1, n, nums, temp, ans, k); // Recurse without including the current element
    }

    // Main function to initialize variables and call the solver
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;

        // Fill nums with values from 1 to n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> ans; // To store all valid combinations
        vector<int> temp;        // Temporary list to build each combination

        // Start recursive combination generation from index 0
        solve(0, n, nums, temp, ans, k);

        return ans; // Return the final list of combinations
    }
};

*******************************************APPROACH 2nd(BETTER APPROACH)*****************************************

class Solution {
public:
    // Recursive function to generate combinations
    void solve(int start, int &n, vector<int>& temp, vector<vector<int>>& ans, int k) {
        // Base case: if we have selected k numbers, add the combination to result
        if (k == 0) 
        {
            ans.push_back(temp);
            return;
        }

        // Base case: if 'start' exceeds 'n', no more numbers to choose from
        if (start > n) 
        {
            return;
        }

        // ----------- CHOICE 1: Include the current number 'start' ------------

        // Add the current number to the current combination
        temp.push_back(start);

        // Recur for the next number, reduce 'k' since we've picked one element
        solve(start + 1, n, temp, ans, k - 1);

        // Backtrack: remove the last added number to explore the other possibility
        temp.pop_back();

        // ----------- CHOICE 2: Exclude the current number 'start' ------------

        // Recur without including the current number, 'k' remains same
        solve(start + 1, n, temp, ans, k);
    }

    // Main function to start the combination generation
    vector<vector<int>> combine(int n, int k) {
        // stores all valid combinations
        vector<vector<int>> ans;   

        // temporary vector to store current combination
        vector<int> temp;          

        // Start generating combinations from number 1 to n
        solve(1, n, temp, ans, k);
        return ans;
    }
};

*******************************************APPROACH 3rd***************************************************

class Solution {
public:
    // Recursive function to generate all combinations
    void solve(int start, int &n, vector<int>& temp, vector<vector<int>>& ans, int k) {
        // Base case: if k elements are selected, add the current combination to the answer
        if (k == 0) 
        {
            // add valid combination
            ans.push_back(temp); 
            return;
        }

        // If 'start' exceeds 'n', there are no more elements to pick from
        if (start > n) 
        {
            return;
        }

        // Try every number from 'start' to 'n'
        for (int i = start; i <= n; i++) 
        {
            // Choose current number
            temp.push_back(i);

            // Recur with remaining k - 1 and next number                    
            solve(i + 1, n, temp, ans, k - 1); 

            // Backtrack to try next number   
            temp.pop_back();                      
        }
    }

    // Main function to be called with n and k
    vector<vector<int>> combine(int n, int k) {
        // To store the final combinations
        vector<vector<int>> ans;

        // Temporary list to store current combination  
        vector<int> temp;         

        // Start generating combinations from number 1
        solve(1, n, temp, ans, k);
        return ans;
    }
};

