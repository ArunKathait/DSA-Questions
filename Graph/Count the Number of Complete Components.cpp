*****************************************APPROACH 1st(USING DFS)**********************************************

class Solution {// TC--->O(V + E)                           SC--->O(V + E)
public:
    
    // Depth First Search (DFS) function to explore the connected component
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj,
    int &v,int &e)
    {
        // Mark the current node as visited
        visited[node] = true;
        
        // Increase the count of nodes in the current component
        v++;

        // Add the number of edges connected to this node
        e += adj[node].size();

        // Traverse all adjacent nodes
        for(auto &neighbour:adj[node])
        {
            // If the neighbor is not visited, perform DFS
            if(!visited[neighbour])
            {
                dfs(neighbour,visited,adj,v,e);
            }
        }
    }

    // Function to count the number of complete components in the graph
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Adjacency list to represent the graph
        unordered_map<int,vector<int>>adj;

        // Building the adjacency list from the given edges
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];

            
            adj[u].push_back(v);

            // Since it's an undirected graph
            adj[v].push_back(u);
        }

        // To count the number of complete components
        int ans= 0;

        // To keep track of visited nodes
        vector<bool>visited(n,false);

        // Loop through each node in the graph
        for(int i=0;i<n;i++)
        {
            // Variables to count nodes and edges in this component
            int v = 0;
            int e = 0 ;

             // If the node is not visited, start a new DFS
            if(visited[i] == false)
            {
                dfs(i,visited,adj,v,e);

                // A complete graph with v nodes should have exactly (v * (v - 1)) / 2 edges
                // Since edges are counted twice in an undirected graph, we check e / 2
                if((v*(v-1))/2 == e/2)
                {
                    // Increment the count of complete components
                    ans++;
                }
            }
        }

        // Increment the count of complete components
        return ans;
    }
};


**********************************************APPROACH 2ND(BFS)**************************************************

class Solution {// TC--->O(V + E)                          SC--->O(V + E)
public:
    // Breadth-First Search (BFS) function to explore a connected component
    void bfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj,
    int &v,int &e)
    {
       // Queue for BFS traversal
       queue<int>q;

       // Start BFS from the given node
       q.push(node);

       // Mark the node as visited
       visited[node] = true;

       // Continue BFS until all reachable nodes are visited
       while(!q.empty())
       {
           // Get the front node in the queue
           auto current = q.front();
           
           // Remove it from the queue
           q.pop();

           // Increment the vertex count
           v++;

           // Add the number of edges from this node
           e += adj[current].size();

           // Explore all neighbors of the current node
           for(auto &neighbour:adj[current])
           {
                // If the neighbor is not visited
                if(!visited[neighbour])
                {
                    // Mark it as visited
                    visited[neighbour] = true;

                    // Add it to the queue for further exploration
                    q.push(neighbour);
                }
           }
       }    
    }

    // Function to count complete components in the graph
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        // Adjacency list to store the graph
        unordered_map<int,vector<int>>adj;

        // Construct the adjacency list from the given edge list
        for(auto &edge:edges)
        {
            // First node of the edge
            int u = edge[0];

            // Second node of the edge
            int v = edge[1];

            // Add v to u's adjacency list
            adj[u].push_back(v);

            // Add u to v's adjacency list (since the graph is undirected)
            adj[v].push_back(u);
        }
        
        // Visited array to track visited nodes
        vector<bool>visited(n,false);

        // Count of complete components
        int ans = 0;

         // Traverse all nodes to find connected components
        for(int i=0;i<n;i++)
        {
            // Number of vertices in the component
            int v = 0;

            // Number of edges in the component
            int e = 0;

            // If the node is unvisited, it's a new component
            if(visited[i] == false)
            {
                // Perform BFS to explore this component
                bfs(i,visited,adj,v,e);

                // Check if the component is complete
                // A complete graph with 'v' nodes must have exactly (v*(v-1))/2 edges
                // Since edges are counted twice in 'e', we divide by 2
                if((v*(v-1))/2 == e/2)
                {
                    // If it's a complete component, increment the count

                    ans++; 
                }
            }
        }
 
        // Return the total count of complete components
        return ans;
    }
};
