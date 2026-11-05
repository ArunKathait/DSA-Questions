****************************************************APPROACH 1st(BRUTE FORCE)********************************************

class Solution {// Time:  O(N * M)                         Space: O(1) 
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int n = arr1.size();
        int m = arr2.size();

        int ans = 0;  // Counts valid elements from arr1

        // Traverse each element of arr1
        for(int i = 0; i < n; i++)
        {
            // Assume the current arr1[i] is valid
            bool isValid = true;

            // Compare arr1[i] with every element of arr2
            for(int j = 0; j < m; j++)
            {
                // Calculate the absolute difference
                int res = abs(arr1[i] - arr2[j]);

                // If difference is <= d, current element is invalid
                if(res <= d)
                {
                    isValid = false;

                    // No need to check remaining elements of arr2
                    break;
                }
            }

            // If no element in arr2 violates the condition,
            // count the current arr1[i] as valid
            if(isValid)
            {
                ans++;
            }
        }

        // Return the total number of valid elements
        return ans;
    }
};

************************************************APPROACH 2nd(BETTER)**************************************************

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int n = arr1.size();
        int m = arr2.size();

        // Sort arr2 so we can apply binary search
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        // Check every element of arr1
        for(int i = 0; i < n; i++)
        {
            // Find the first index in arr2 where element >= arr1[i]
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();

            // Case 1: arr1[i] is smaller than or equal to every element in arr2
            // Only the first element of sorted arr2 can be the closest candidate
            if(j == 0)
            {
                // Count arr1[i] only if its distance from arr2[0] is greater than d
                ans += (arr2[0] - arr1[i]) > d;
            }

            // Case 2: arr1[i] is greater than every element in arr2
            else if(j >= m)
            {
                // Only the last element of sorted arr2 can be the closest candidate
                ans += (arr1[i] - arr2[m - 1]) > d;
            }

            // Case 3: arr1[i] lies between two elements of arr2
            else
            {
                // Check the distance from both neighbouring elements
                // Both distances must be greater than d
                ans += (arr2[j] - arr1[i] > d) &&
                       (arr1[i] - arr2[j - 1] > d);
            }
        }

        return ans;
    }
};
