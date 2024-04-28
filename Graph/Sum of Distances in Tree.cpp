class Solution {// TC--->O(N)         SC--->O(N)
public:
    // Number of nodes in the tree
    int N;
    
    // Vector to store the count of nodes in each subtree
    vector<int>count;
    
    // Variable to store the sum of distances from the root node
    long result_base_node = 0;
    
    // Function to perform DFS to calculate the count of nodes in each subtree
    int dfsBase(unordered_map<int,vector<int>>&adj,int currentNode,int previousNode,int currentPathDepth)
    {
        // Initialize the count of nodes in the current subtree to 1
        int total_node = 1;
        
        // Accumulate the sum of distances from the root node
        result_base_node += currentPathDepth;
        
        // Traverse through the children of the current node
        for(auto child:adj[currentNode])
        {
            // Skip the child if it's the previous node to avoid going back to the parent node
            if(child == previousNode)
            {
                continue;
            }
            
            // Recursively calculate the count of nodes in the child subtree
            total_node += dfsBase(adj,child,currentNode,currentPathDepth + 1);
        }
        
        // Store the count of nodes in the current subtree
        count[currentNode] = total_node;
        
        // Return the count of nodes in the current subtree
        return total_node;
    }
    
    // Function to perform DFS to update the distances of all nodes from the root node
    void DFS(unordered_map<int,vector<int>>&adj,int parentNode,int previousNode,vector<int>&ans)
    {
        // Traverse through the children of the parent node
        for(auto child:adj[parentNode])
        {
            // Skip the child if it's the previous node to avoid going back to the parent node
            if(child == previousNode)
            {
                continue;
            }
            
            // Update the distance of the child node from the root node
            ans[child] = ans[parentNode] - count[child] + (N - count[child]);
            
            // Recursively perform DFS on the child node
            DFS(adj,child,parentNode,ans);
        }
    }
    
    // Main function to calculate the sum of distances in the tree
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        // Adjacency list representation of the tree
        unordered_map<int,vector<int>>adj;
        
        // Assign the number of nodes
        N = n;
        
        // Resize the count vector to store counts for each node
        count.resize(n,0);
        
        // Populate the adjacency list with edges
        for(auto x:edges)
        {
            int u = x[0];
            int v = x[1];
            
            // Add edges between nodes u and v
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Reset the sum of distances
        result_base_node = 0;
        
        // Perform DFS to calculate the count of nodes in each subtree
        dfsBase(adj,0,-1,0);
        
        // Vector to store distances from the root node
        vector<int>ans(n,0);
        
        // Assign the sum of distances from the root node
        ans[0] = result_base_node;
        
        // Perform DFS to update the distances of all nodes from the root node
        DFS(adj,0,-1,ans);
        
        // Return the vector containing distances of all nodes from the root node
        return ans;
    }
};
