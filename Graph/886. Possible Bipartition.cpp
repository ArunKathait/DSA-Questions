***********************************************APPROACH 1st(DFS)*****************************************************

class Solution {// TIME: O(n + m)                          SPACE: O(n + m)
public:
    bool dfs(int node, unordered_map<int,vector<int>>& adj, vector<int>& color)
    {
        // Traverse all adjacent nodes of the current node.
        for(auto &neighbor : adj[node])
        {
            // If the neighbor is not visited yet.
            if(color[neighbor] == -1)
            {
                // Assign the opposite color to the neighbor.
                // If current node has color 0, neighbor gets 1.
                // If current node has color 1, neighbor gets 0.
                color[neighbor] = 1 - color[node];

                // Recursively visit the neighbor and check
                // whether its connected component is bipartite.
                if(dfs(neighbor, adj, color) == false)
                {
                    return false;
                }
            }

            // If the neighbor is already visited,
            // check whether both adjacent nodes have the same color.
            // If yes, they belong to the same group,
            // which violates the problem condition.
            else if(color[node] == color[neighbor])
            {
                return false;
            }
        }

        // All adjacent nodes satisfy the two-color condition.
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        // Step 1: Build an undirected adjacency list.
        // Each dislike relationship connects two people.
        unordered_map<int,vector<int>> adj;

        for(auto &x : dislikes)
        {
            int u = x[0];
            int v = x[1];

            // Add an edge in both directions.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Maintain the color of every person.
        // -1 = Unvisited
        //  0 = Group 1
        //  1 = Group 2
        vector<int> color(n + 1, -1);

        // Step 3: Traverse every node.
        // This handles disconnected components as well.
        for(int i = 1; i <= n; i++)
        {
            // If the person is not visited,
            // start a new DFS traversal.
            if(color[i] == -1)
            {
                // Assign the starting person to Group 2.
                color[i] = 1;

                // If DFS finds a conflict, splitting is impossible.
                if(dfs(i, adj, color) == false)
                {
                    return false;
                }
            }
        }

        // Every connected component is successfully 2-colored.
        // Therefore, splitting everyone into two groups is possible.
        return true;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│           POSSIBLE BIPARTITION (LC 886)              │
├──────────────────────────────────────────────────────┤
│ APPROACH: DFS + Graph Coloring                       │
│                                                      │
│ KEY IDEA:                                            │
│ • Build an undirected graph.                         │
│ • Use 0 and 1 to represent two groups.               │
│ • Assign opposite colors to adjacent nodes.          │
│ • Recursively explore unvisited neighbors.           │
│ • Same-colored adjacent nodes → return false.        │
│ • Check all disconnected components.                 │
│                                                      │
│ TIME COMPLEXITY:  O(n + m)                           │
│ SPACE COMPLEXITY: O(n + m)                           │
│ EXTRA SPACE:      O(n)                               │
└──────────────────────────────────────────────────────┘

*/

**************************************************APPROACH 2nd(BFS)****************************************************

class Solution {// TIME COMPLEXITY:  O(n + m)                  SPACE COMPLEXITY: O(n + m)
public:

    bool bfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&color)
    {
        queue<int>q;

        q.push(node);
        color[node] = 1;

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            for(auto &neighbor:adj[node])
            {
                if(color[node] == color[neighbor])
                {
                    return false;
                }
                else if(color[neighbor] == -1)
                {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;

        for(auto &x:dislikes)
        {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++)
        {
            if(color[i] == -1)
            {
                if(bfs(i,adj,color) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│           POSSIBLE BIPARTITION (LC 886)              │
├──────────────────────────────────────────────────────┤
│ APPROACH: BFS + Graph Coloring                       │
│                                                      │
│ KEY IDEA:                                            │
│ • Build an undirected adjacency list.                │
│ • Use 0 and 1 to represent two groups.               │
│ • Start BFS and assign the starting node a color.    │
│ • Assign opposite colors to unvisited neighbors.     │
│ • Same-colored adjacent nodes → return false.        │
│ • Check all disconnected components.                 │
│                                                      │
│ TIME COMPLEXITY:  O(n + m)                           │
│ SPACE COMPLEXITY: O(n + m)                           │
│ EXTRA SPACE:      O(n)                               │
└──────────────────────────────────────────────────────┘

*/
