*******************************************APPROACH 1st*******************************************************

class Solution {// TC--->O(NlogN)      SC--->O(N)     
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Get the size of the deck
        int n = deck.size();
        
        // Sort the deck in increasing order
        sort(deck.begin(),deck.end());
        
        // Initialize a boolean variable to control skipping
        bool skip = false;
        
        // Initialize an output vector with size n, filled with zeros
        vector<int>ans(n,0);
        
        // Initialize indices for iterating through deck and ans
        int i = 0;
        int j = 0 ;
        
        // Iterate until all cards are revealed
        while(i<n)
        {
            // Check if the current position in ans is empty
            if(ans[j] == 0)
            {
                // If it's empty, place the next card from the sorted deck
                if(skip == false)
                {
                    ans[j] = deck[i];
                    
                    // Move to the next card in the deck
                    i++;
                }
                
                // Toggle the skip flag
                skip = !skip;
            }
            
            // Move to the next position in ans (circular)
            j = (j + 1) % n;
        }
        
        // Return the revealed deck
        return ans;
    }
};


**********************************************APPROACH 2nd(USING QUEUE)****************************************************

class Solution {// TC--->O(NlogN)          SC--->O(N)
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Get the size of the deck
        int n = deck.size();
        
        // Sort the deck in increasing order
        sort(deck.begin(),deck.end());
        
        // Initialize an output vector with size n
        vector<int>ans(n);
        
        // Initialize a queue to keep track of indices
        queue<int>q;
        
        // Populate the queue with indices from 0 to n-1
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        
        // Iterate through the sorted deck
        for(int i=0;i<n;i++)
        {
            // Get the front index from the queue
            int index = q.front();
            
            // Remove the front index from the queue
            q.pop();
            
            // Place the next card from the sorted deck at the index specified by the front of the queue
            ans[index] = deck[i];
            
            
            // If the queue is not empty, move the front index to the back
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        // Return the revealed deck
        return ans;
    }
};
