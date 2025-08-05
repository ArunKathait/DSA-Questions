*********************************************APPROACH 1st(BRUTE FORCE)*******************************************

class Solution {// TC--->O(N^2)                      SC--->O(N)
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // Total number of fruits (and baskets, assuming same size)
        int n = fruits.size();

        // Create a vector to track whether each basket is already used (0 = unused, 1 = used)
        vector<int> check(n, 0);
        
        // To count how many fruits couldn't be placed
        int unplaced = 0;  

        // Loop through each fruit one by one
        for (int i = 0; i < n; i++) 
        {
            // Flag to check if current fruit has been placed
            bool placed = false;  

            // Try to place the current fruit into a suitable basket
            for (int j = 0; j < n; j++) 
            {
                // If basket is big enough for the fruit and hasn't been used yet
                if (fruits[i] <= baskets[j] && !check[j]) 
                {
                    check[j] = 1;     // Mark this basket as used
                    placed = true;    // Mark that this fruit has been placed
                    break;            // No need to check other baskets for this fruit
                }
            }

            // After checking all baskets, if the fruit couldn't be placed
            if (!placed) 
            {
                // Increase count of unplaced fruits
                unplaced++;  
            }
        }

        // Return the total number of fruits that couldn't be placed
        return unplaced;
    }
};

**********************************************APPROACH 2nd(BETTER APPROACH)****************************************

class Solution {// TC--->O(N^2)                               SC--->O(1)  
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         // Total number of fruits (assuming baskets also of size n)
        int n = fruits.size(); 
        
        // Counter to track how many fruits couldn't be placed
        int unplaced = 0;       

        // Loop through each fruit
        for (auto &fruit : fruits) 
        {
            // Flag to check if fruit was placed (1 = not placed yet)
            int unset = 1;      

            // Try placing the current fruit in one of the baskets
            for (int i = 0; i < n; i++) 
            {
                // If basket is large enough for the fruit
                if (fruit <= baskets[i]) 
                {
                    baskets[i] = 0;   // Mark basket as used by setting size to 0
                    unset = 0;        // Mark fruit as placed
                    break;            // Move to next fruit
                }
            }

            // If no suitable basket was found (fruit not placed), increment unplaced counter
            unplaced += unset;
        }

        // Return the total number of unplaced fruits
        return unplaced;
    }
};
