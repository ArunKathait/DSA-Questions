**************************************************APPROACH 1st(USING DFS)*********************************************

class Solution {// TC ---> O(V + E)                              SC ---> O(V + E)
  public:

    // DFS function to detect cycle
    bool isCycleDFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int node,int parent)
    {
        // Mark current node as visited
        visited[node] = true;
        
        // Traverse all adjacent nodes (neighbors)
        for(auto &neighbor: adj[node])
        {
            // If neighbor is parent, ignore it
            // (because in undirected graph, parent will always be visited)
            if(neighbor == parent)
            {
                continue;
            }
            
            // If neighbor is already visited and NOT parent
            // → cycle detected
            if(visited[neighbor])
            {
                return true;
            }
            
            // If neighbor is not visited, do DFS on it
            // If cycle found in recursion, return true
            if(isCycleDFS(adj, visited, neighbor, node))
            {
                return true;
            }
        }

        // No cycle found from this node
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list
        unordered_map<int,vector<int>> adj;
        
        for(auto x : edges)
        {
            int u = x[0];
            int v = x[1];
            
            // Since graph is undirected → add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Step 2: Visited array to track visited nodes
        vector<bool> visited(V, false);
        
        // Step 3: Traverse all nodes (handles disconnected graph)
        for(int i = 0; i < V; i++)
        {
            // If node is not visited, start DFS
            // parent = -1 (no parent for starting node)
            if(!visited[i] && isCycleDFS(adj, visited, i, -1))
            {
                return true;  // cycle found
            }
        }
        
        // If no cycle found in any component
        return false;
    }
};

**************************************************APPROACH 2nd(USING BFS)**********************************************

class Solution {// TC ---> O(V + E)                               SC ---> O(V + E)
  public:

    // BFS function to detect cycle in an undirected graph
    bool isCycleBFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int node)
    {
        // Queue stores {current_node, parent_node}
        queue<pair<int,int>> q;
        
        // Push starting node with parent = -1 (no parent)
        q.push({node, -1});
        
        // Mark starting node as visited
        visited[node] = true;
        
        // Standard BFS loop
        while(!q.empty())
        {
            // Get front element
            auto frontPair = q.front();
            q.pop();
            
            int curr = frontPair.first;   // current node
            int parent = frontPair.second; // parent of current node
            
            // Traverse all neighbors of current node
            for(auto &neighbor : adj[curr])
            {
                // If neighbor is not visited
                if(!visited[neighbor])
                {
                    // Mark it visited and push into queue
                    visited[neighbor] = true;
                    q.push({neighbor, curr});
                }
                // If neighbor is already visited AND not parent
                // → cycle detected
                else if(neighbor != parent)
                {
                    return true;
                }
            }
        }

        // No cycle found in this component
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list
        unordered_map<int,vector<int>> adj;
        
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            
            // Undirected graph → add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Step 2: Visited array
        vector<bool> visited(V, false);
        
        // Step 3: Handle disconnected graph
        for(int i = 0; i < V; i++)
        {
            // If node not visited, run BFS
            if(!visited[i] && isCycleBFS(adj, visited, i))
            {
                return true; // cycle found
            }
        }
        
        // No cycle found in entire graph
        return false;
    }
};
