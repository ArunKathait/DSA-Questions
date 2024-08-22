
class Solution {
    
    private:
    // Function to perform topological sort using Kahn's algorithm
    vector<int>topoSort(int V,unordered_map<int,vector<int>>&adj)
    {
        // Array to keep track of indegree of each node
        int indegree[V] = {0};

        // Calculate the indegree of each node
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                // Increment indegree for each adjacent node
                indegree[it]++;
            }
        }
        
        // Queue to store nodes with indegree 0
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            // If indegree is 0, push it into the queue
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        // Vector to store the topological order
        vector<int>topo;
        
        // Process nodes in queue
        while(!q.empty())
        {
            // Get the front node
            auto node = q.front();
            
            // Remove it from the queue
            q.pop();
            
            // Add it to the topological order
            topo.push_back(node);
            
            // Reduce the indegree of all its adjacent nodes
            for(auto it:adj[node])
            {
                indegree[it]--;
                
                // If indegree of an adjacent node becomes 0, push it into the queue
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        // Return the topological order
        return topo;
    }
  public:
  // Function to find the order of characters in the alien language
    string findOrder(string dict[], int n, int k) {
        // Adjacency list using unordered_map
        unordered_map<int,vector<int>>adj;
        
        // Build the graph by comparing adjacent words in the dictionary
        for(int i=0;i<n-1;i++)
        {
            // Current word
            string s1 = dict[i];
            
            // Next word
            string s2 = dict[i+1];
            
            // Compare up to the length of the shorter word
            int length = min(s1.length(),s2.length());
            
            // Find the first differing character
            for(int k=0;k<length;k++)
            {
                // Create an edge from character s1[j] to s2[j]
                if(s1[k] != s2[k])
                {
                    adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                    
                    // Only the first different character determines the order
                    break;
                }
            }
        }
        
        // Perform topological sort to determine character order
        vector<int>topo = topoSort(k,adj);
        
        string ans;
        for(auto it:topo)
        {
            // Convert the node number back to character
            ans += (it + 'a');
        }
        
        // Return the final order of characters as a string
        return ans;
    }
};
