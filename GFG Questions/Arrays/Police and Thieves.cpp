
class Solution {// TC ---> O(N)                     SC ---> O(N)
  public:
    int catchThieves(vector<char> &arr, int k) {

        int n = arr.size();   // Size of the array

        // Store indices of thieves and policemen separately
        vector<int> theif;
        vector<int> police;

        // Traverse the array and collect positions
        for(int i = 0; i < n; i++) 
        {
            if(arr[i] == 'T') 
            {
                theif.push_back(i);    // Store index of thief
            } 
            else 
            {
                police.push_back(i);  // Store index of policeman
            }
        }

        int i = 0;    // Pointer for thief array
        int j = 0;    // Pointer for police array
        int ans = 0;  // Count of caught thieves

        // Greedy matching using two pointers
        while(i < theif.size() && j < police.size()) 
        {
            // If current policeman can catch current thief
            if(abs(theif[i] - police[j]) <= k) 
            {
                ans++;   // One thief caught
                i++;     // Move to next thief
                j++;     // Move to next policeman
            }

            // If thief is too far left of policeman
            // This thief cannot be caught by this or any next policeman
            else if(theif[i] < police[j]) 
            {
                i++;     // Skip this thief
            }

            // If policeman is too far left of thief
            // This policeman cannot catch this or any next thief
            else 
            {
                j++;     // Skip this policeman
            }
        }

        return ans;   // Maximum number of thieves caught
    }
};
