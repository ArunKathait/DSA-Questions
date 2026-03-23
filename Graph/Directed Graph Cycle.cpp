***************************************************APPROACH 1st(USING DFS)***********************************************

class Solution {// TC ---> O(V + E)                              SC ---> O(V + E)
  public:
    
    // DFS function to detect cycle in a directed graph
    bool isCycleDFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>&inRecursion,int node)
    {
        // Mark node as visited
        visited[node] = true;
        
        // Mark node as part of current DFS recursion path
        inRecursion[node] = true;
        
        // Traverse all neighbors
        for(auto &neighbor : adj[node])
        {
            // Case 1: If neighbor is not visited → go deeper (DFS)
            if(visited[neighbor] == false &&
               isCycleDFS(adj, visited, inRecursion, neighbor))
            {
                return true;
            }
            
            // Case 2: If neighbor is already in recursion stack
            // → back edge → cycle detected
            else if(inRecursion[neighbor] == true)
            {
                return true;
            }
        }
        
        // Backtracking step:
        // Remove current node from recursion stack
        inRecursion[node] = false;
        
        // No cycle found from this node
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // Step 1: Create adjacency list (DIRECTED graph)
        unordered_map<int,vector<int>> adj;
        
        for(auto x : edges)
        {
            int u = x[0];
            int v = x[1];
            
            // Directed edge → only one direction
            adj[u].push_back(v);
        }
        
        // Step 2: Visited array → tracks processed nodes
        vector<bool> visited(V, false);
        
        // Step 3: Recursion stack → tracks current DFS path
        vector<bool> inRecursion(V, false);
        
        // Step 4: Traverse all nodes (handles disconnected graph)
        for(int i = 0; i < V; i++)
        {
            // If node not visited, start DFS
            if(!visited[i] && isCycleDFS(adj, visited, inRecursion, i))
            {
                return true; // cycle found
            }
        }
        
        // No cycle found in entire graph
        return false;
    }
};

**************************************************APPROACH 2nd(USING BFS)************************************************
// KAHN'S Algorithm is used to check cycle detection in directed graph(i.e Topological sorting)

class Solution {// Tc ---> O(V + E)                                 SC ---> O(V + E)
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // Step 1: Build adjacency list (DIRECTED graph)
        unordered_map<int, vector<int>> adj;
        
        for(auto edge : edges)
        {
            int u = edge[0]; // source
            int v = edge[1]; // destination
            
            adj[u].push_back(v); // u → v
        }
        
        // Step 2: Create indegree array
        // indegree[i] = number of incoming edges to node i
        vector<int> indegree(V, 0);
        
        // Calculate indegree for each node
        for(int node = 0; node < V; node++)
        {
            for(auto neighbor : adj[node])
            {
                indegree[neighbor]++;
            }
        }
        
        // Step 3: Push all nodes with indegree = 0 into queue
        queue<int> q;
        
        int processedNodes = 0; // counts nodes processed in BFS
        
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                
                // NOTE: In your code you incremented here,
                // but better practice is to increment when popping
            }
        }
        
        // Step 4: BFS traversal (Topological Sort)
        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            
            // Increase count when node is processed
            processedNodes++;
            
            // Traverse all neighbors
            for(auto neighbor : adj[currentNode])
            {
                // Reduce indegree (edge removal)
                indegree[neighbor]--;
                
                // If indegree becomes 0, push to queue
                if(indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 5: Check for cycle
        // If all nodes are processed → NO cycle
        // If some nodes are left → cycle exists
        if(processedNodes != V)
        {
            return true;  // cycle exists
        }
        
        return false; // no cycle
    }
};
