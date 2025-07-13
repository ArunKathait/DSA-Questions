
class Solution {// TC--->O(n log n + m log m)                 SC--->O(1)
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        // Get number of players
        int n = players.size(); 

        // Get number of trainers
        int m = trainers.size(); 

        // Sort both players and trainers in ascending order
        // This helps in greedy matching: smallest capable trainer with smallest demanding player
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        // Pointers for players and trainers
        int i = 0, j = 0; 

        // To count the number of successful matches
        int ans = 0; 

        // Loop until we reach the end of either list
        while (i < n && j < m) 
        {
            if (players[i] <= trainers[j]) 
            {
                // If current trainer can handle current player
                // Successful match
                ans++; 

                // Move to next player
                i++; 

                // Move to next trainer  
                j++;   
            } 
            else 
            {
                // Current trainer is too weak, try next trainer
                j++;
            }
        }
        // Return the total number of successful matches
        return ans; 
    }
};
