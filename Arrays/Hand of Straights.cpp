
class Solution {// TC--->O(NlogN)               SC--->O(N)     
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Get the size of the input hand
        int n = hand.size();
        
        // If the total number of cards is not divisible by groupSize, return false
        if(n%groupSize != 0)
        {
            return false;
        }
        
        // Create a map to store the frequency of each card
        map<int,int>mp;
        
        // Increment the count of the card in the map
        for(auto x:hand)
        {
            mp[x]++;
        }
        
        // Loop while there are elements in the map
        while(!mp.empty())
        {
            // Get the smallest element in the map(i.e first element)
            int firstElement = mp.begin()->first;
            
            // Try to form a group starting from the smallest element
            for(int i=0;i<groupSize;i++)
            {
                // If the current card needed for the group is not present, return false
                if(mp[firstElement + i] == 0)
                {
                    return false;
                }
                
                // Decrement the count of the current card in the map
                mp[firstElement + i]--;
                
                // If the count of the current card becomes zero, remove it from the map
                if(mp[firstElement + i] == 0)
                {
                    mp.erase(firstElement + i);
                }
            }
        }
        
        // If all groups are successfully formed, return true
        return true;
    }
};
