
class Solution {// TC ---> O(n log n)                                  SC ---> O(log n)
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        // Lambda comparator function
        // This function tells sort() how to compare two numbers
        auto myComp = [](int a, int b)
        {
            // Count number of set bits (1s) in binary representation of a
            int aCount = __builtin_popcount(a);

            // Count number of set bits (1s) in binary representation of b
            int bCount = __builtin_popcount(b);

            // If both numbers have same number of set bits
            if(aCount == bCount)
            {
                // Sort based on actual number (ascending order)
                return a < b;
            }

            // Otherwise sort based on number of set bits (ascending order)
            return aCount < bCount;
        };

        // sort() uses the comparator to arrange elements
        // It repeatedly compares elements using myComp
        sort(arr.begin(), arr.end(), myComp);

        // Return the sorted array
        return arr;
    }
};
