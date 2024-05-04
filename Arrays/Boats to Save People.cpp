class Solution {// TC--->O(NlogN)             SC--->O(1)
public:
    // Function to calculate the minimum number of boats needed to rescue people.
    int numRescueBoats(vector<int>& people, int limit) {
        
        // Sort the 'people' array in non-decreasing order to facilitate efficient pairing.
        sort(people.begin(),people.end());
        
        // Get the number of people in the array.
        int n = people.size();
        
        // Initialize two pointers: 'i' pointing to the lightest person and 'j' to the heaviest.
        int i = 0;
        int j = n - 1;
        
        // Initialize the boat count.
        int boat = 0;
        
        // Iterate through the array until the pointers meet.
        while(i <= j)
        {
            // If the sum of weights of people at both pointers is less than or equal to the limit,
            // move both pointers towards each other and increment the boat count.
            if(people[i] + people[j] <= limit)
            {
                i++;
                j--;
                boat++;
            }
            else 
            {
                // If the sum exceeds the limit, move only the 'j' pointer towards the lighter side
                // and increment the boat count since a boat is needed for the heavier person.
                j--;
                boat++;
            }
        }
        
        // Return the total number of boats needed.
        return boat;
    }
};
