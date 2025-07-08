
class FindSumPairs {
public:
    // Stores the first input array (nums1)
    vector<int> vec1; 

    // Stores the second input array (nums2)
    vector<int> vec2;

    // Hashmap to store frequency of each element in vec2
    unordered_map<int, int> ump; 

    // Constructor: Initializes the object with two integer arrays nums1 and nums2
    // TC--->O(m + n)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1; // Assign nums1 to vec1--->O(n)
        vec2 = nums2; // Assign nums2 to vec2--->O(m)

        // Count the frequency of each element in vec2 and store in map
        for (auto x : vec2) 
        {
            ump[x]++;
        }
    }
    
    // Function to add a value to an element in vec2 at a given index
    // O(1)
    void add(int index, int val) {
        // Decrease the frequency of the old value at that index
        ump[vec2[index]]--;

        // Update the value at the specified index
        vec2[index] += val;

        // Increase the frequency of the new value
        ump[vec2[index]]++;
    }
    
    // Function to count the number of pairs (i, j) such that:
    // vec1[i] + vec2[j] == tot
    // O(n)
    int count(int tot) {
        // Counter to store total number of valid pairs
        int c = 0;

        // Iterate through each element in vec1
        for (auto val : vec1) 
        {
            // The value we want to find in vec2
            int findPair = tot - val; 

            // If that value exists in vec2 (tracked by hashmap), add its frequency
            if (ump.find(findPair) != ump.end()) 
            {
                c += ump[findPair];
            }
        }
        
        // Return total count of such pairs
        return c; 
    }
};
