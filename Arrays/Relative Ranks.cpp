*******************************************APPROACH 1st*******************************************************

class Solution {// TC--->O(NlogN)           SC--->O(N)
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // Copy the original scores vector and sort it in descending order  
        vector<int>sorted(score.begin(),score.end());
        
        sort(sorted.begin(),sorted.end(),greater<int>());
        
        // Define the medals for the top three ranks
        vector<string>medals = {"Gold Medal","Silver Medal","Bronze Medal"};
        
        // Create an unordered map to store the rank for each score
        unordered_map<int,string>ump;
        
        // Assign ranks to scores based on their position in the sorted array
        for(int i=0;i<sorted.size();i++)
        {
            if(i < 3)
            {
                // Assign medals for the top three scores
                ump[sorted[i]] = medals[i];
            }
            else
            {
                // Assign numeric ranks for scores beyond the top three
                ump[sorted[i]] = to_string(i + 1);
            }
        }
        
        // Create a vector to store the relative ranks for each score
        vector<string>ans;
        
        // Fill the ans vector with ranks corresponding to each score
        for(auto x:score)
        {
            ans.push_back(ump[x]);
        }
        
        // Return the vector containing the relative ranks for each score
        return ans;
                
    }
};


********************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(NlogN)                  SC--->O(N)
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Get the size of the score vector
        int n = score.size();
        
        // Create an unordered map to store the original indices of scores
        unordered_map<int,int>ump;
        
        for(int i=0;i<n;i++)
        {
            // Map each score to its index in the score vector
            ump[score[i]] = i;
        }
        
        // Sort the scores in descending order
        sort(score.begin(),score.end(),greater<int>());
        
        // Initialize a vector to store the result
        vector<string>ans(n);
        
        // Assign ranks to scores and medals to top three scores
        for(int i=0;i<n;i++)
        {
            // Get the original index of the score
            int ath = ump[score[i]];
            
            if(i == 0)
            {
                // Assign "Gold Medal" to the top scorer
                ans[ath] = "Gold Medal";
            }
            else if(i == 1)
            {
                // Assign "Silver Medal" to the second top scorer
                ans[ath] = "Silver Medal";
            }
            else if(i == 2)
            {
                // Assign "Bronze Medal" to the third top scorer
                ans[ath] = "Bronze Medal";
            }
            else
            {
                // Assign the rank (as string) to other scorers
                ans[ath] = to_string(i + 1);
            }
        }
        
        // Return the vector containing ranks and medals
        return ans;
        
    }
};

********************************************APPROACH 3rd********************************************************

class Solution {// TC--->O(NlogN)          SC--->O(N)
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // Get the size of the score vector
        int n = score.size();
        
        // Create a max heap (priority queue) of pairs (score, index)
        // The pairs are sorted based on the score in descending order
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            // Push each score along with its index into the priority queue
            pq.push({score[i],i});
        }
        
        // Initialize the rank
        int rank = 1;
        
        // Initialize a vector to store the result
        vector<string>ans(n);
        
        // Process scores in descending order of their value
        while(!pq.empty())
        {
            // Get the index of the current top score
            int index = pq.top().second;
            
            // Remove the current top score from the priority queue
            pq.pop();
            
            // Assign the appropriate medal or rank to the current score based on its rank
            if(rank == 1)
            {
                ans[index] = "Gold Medal";
            }
            else if(rank == 2)
            {
                ans[index] = "Silver Medal";
            }
            else if(rank == 3)
            {
                ans[index] = "Bronze Medal";
            }
            else
            {
                // Assign the rank as a string
                ans[index] = to_string(rank);
            }
            
            // Increment the rank for the next score
            rank++;
        }
        
        // Return the vector containing ranks and medals
        return ans;
    }
};


********************************************APPROACH 4th********************************************************

class Solution {// TC--->O(N)               SC--->O(maxScore ~ N)
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // Get the size of the score vector
        int n = score.size();
        
        // Initialize a vector to store the result
        vector<string>ans(n);
        
        // Find the maximum score in the vector
        int M = *max_element(score.begin(),score.end());
        
        // Create a map 'mp' to store the index of each score
        // Initialize all elements of 'mp' to -1
        // The size of 'mp' is one more than the maximum score to accommodate scores starting from 0
        vector<int>mp(M + 1,-1);
        
        // Store the index of each score in the map 'mp'
        for(int i=0;i<n;i++)
        {
            mp[score[i]] = i;
        }
        
        // Initialize the rank
        int rank = 1;
        
        // Iterate through scores in descending order of their value
        for(int i=M;i>=0;i--)
        {
            // Check if the score exists in 'mp'
            if(mp[i] != -1)
            {
                // Get the index of the current score
                int index = mp[i];
                
                // Assign the appropriate medal or rank to the current score based on its rank
                if(rank == 1)
                {
                    ans[index] = "Gold Medal";
                }
                else if(rank == 2)
                {
                    ans[index] = "Silver Medal";
                }
                else if(rank == 3)
                {
                    ans[index] = "Bronze Medal";
                }
                else
                {
                    ans[index] = to_string(rank);
                }
                
                // Increment the rank for the next score
                rank++;
            }
        }
        
        // Return the vector containing ranks and medals
        return ans;
    }
};
