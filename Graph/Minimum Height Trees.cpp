class Solution {// TC--->O(N + E)            SC--->O(N + E)            
public:
    // Function to find the roots of the minimum height trees
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // If there is only one node in the graph
        if(n == 1)
        {
            // Return a vector containing the single node (node 0)
            return {0};
        }
        
        // Create an adjacency list to store neighbors of each node
        unordered_map<int,vector<int>>adj;
        
        // Create a vector to store the degree of each node
        vector<int>degree(n);
         
        // Populate adjacency list and calculate degrees of nodes
        for(auto x :edges)
        {
            // First node of edge
            int u = x[0];
            
            // Second node of edge
            int v = x[1];
            
            // Increment degree for both nodes
            degree[u]++;
            degree[v]++;
            
            // Add each node to the adjacency list of the other
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Create a queue for BFS traversal
        queue<int>q;
        
        // Add all leaf nodes (nodes with degree 1) to the queue
        for(int i=0;i<n;i++)
        {
            if(degree[i] == 1)
            {
                q.push(i);
            }
        }
        
        // Variable to keep track of remaining nodes
        int remainingNodes = n;
        
        // Continue until there are only two or fewer nodes left
        while(remainingNodes > 2)
        {
            // Get the number of nodes at this level
            int size = q.size();
            
            // Subtract the number of nodes at this level from remainingNodes
            remainingNodes -= size;
            
            // Process nodes at this level
            while(size--)
            {
                auto leaf = q.front();
                q.pop();
                
                // Update degrees of neighbors and add leaf's neighbors with degree 1 to the queue
                for(auto neighbour:adj[leaf])
                {
                    degree[neighbour]--;
                    
                    if(degree[neighbour] == 1)
                    {
                        q.push(neighbour);
                    }
                    
                }
                
            }
        }
        
        // Initialize vector to store roots of the minimum height trees
        vector<int>ans;
        
        // Add remaining nodes in the queue to the answer vector
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            ans.push_back(front);
        }
        
        // Return the roots of the minimum height trees
        return ans;
    }
};

/*
NOTE:
        vector<vector<int>>graph(n) ---->This can also be used for making graph(i.e adjacency list) with the help of edges.
        Here we are using unordered map for making graph(i.e adjacency list).
*/
