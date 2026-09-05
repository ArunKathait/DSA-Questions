********************************************************APPROACH 1st(DFS)**********************************************
class Solution {// Time  : O(E × (V + E))                                    Space : O(V + E)  
public:

    // DFS checks whether there is already a path
    // from node u to node v.
    bool dfs(int u, int v, vector<bool>& visited, unordered_map<int, vector<int>>& ump)
    {
        // Mark current node as visited
        visited[u] = true;

        // If we reached v, then u and v are already connected.
        // Therefore, adding edge (u,v) would create a cycle.
        if(u == v)
        {
            return true;
        }

        // Visit all neighbors of u
        for(auto &neighbor : ump[u])
        {
            // Only visit an unvisited neighbor
            if(!visited[neighbor])
            {
                // Check whether v can be reached from this neighbor
                if(dfs(neighbor, v, visited, ump))
                {
                    return true;
                }
            }
        }

        // No path from u to v exists
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        // Adjacency list using unordered_map.
        //
        // Example:
        // 1 -- 2
        // 1 -- 3
        //
        // ump[1] = {2, 3}
        // ump[2] = {1}
        // ump[3] = {1}
        unordered_map<int, vector<int>> ump;


        // Process every edge one by one
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];

            // Fresh visited array for this DFS.
            // Nodes are numbered from 1 to n.
            vector<bool> visited(n + 1, false);


            // Check whether both nodes already exist
            // in our graph.
            //
            // If both exist, run DFS to see whether
            // u and v are already connected.
            if(ump.find(u) != ump.end() && ump.find(v) != ump.end() && dfs(u, v, visited, ump))
            {
                // u and v are already connected.
                //
                // Adding (u,v) creates a cycle,
                // so this is the redundant edge.
                return x;
            }


            // Edge does not create a cycle,
            // so add it to the graph.
            //
            // Because the graph is undirected,
            // add both directions.
            ump[u].push_back(v);
            ump[v].push_back(u);
        }


        // No redundant edge found
        return {};
    }
};

/*

┌────────────────────────────────────┐
│       REDUNDANT CONNECTION         │
├────────────────────────────────────┤
│ Approach : DFS + HashMap           │
│                                    │
│ For every edge (u,v):              │
│                                    │
│ 1. Check if u and v already exist  │
│ 2. DFS from u → v                  │
│ 3. If path exists → cycle          │
│ 4. Return current edge             │
│ 5. Otherwise add edge              │
│                                    │
│ Undirected graph:                  │
│ u → v AND v → u                    │
│                                    │
│ Time  : O(E × (V + E))             │
│ Space : O(V + E)                   │
└────────────────────────────────────┘

*/

************************************************APPROACH 2nd(BFS)***************************************************

class Solution {// Time  : O(E × (V + E))             Space : O(V + E)   
public:

    // BFS checks whether there is already a path
    // from node u to node v.
    bool bfs(int u, int v, vector<bool>& visited, unordered_map<int, vector<int>>& ump)
    {
        // Queue is used for BFS traversal
        queue<int> q;

        // Start BFS from node u
        q.push(u);
        visited[u] = true;

        // Continue until there are no more nodes to visit
        while(!q.empty())
        {
            // Get the front node
            auto node = q.front();
            q.pop();

            // If we reached v, then u and v are already connected.
            //
            // Therefore, adding edge (u,v) would create a cycle.
            if(node == v)
            {
                return true;
            }

            // Visit all neighbors of the current node
            for(auto &neighbor : ump[node])
            {
                // Only visit nodes that haven't been visited
                if(!visited[neighbor])
                {
                    // Add neighbor to the BFS queue
                    q.push(neighbor);

                    // Mark it immediately as visited
                    // to avoid adding it multiple times.
                    visited[neighbor] = true;
                }
            }
        }

        // v could not be reached from u,
        // so there is currently no path between them.
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        // Adjacency list using unordered_map.
        //
        // Example:
        // 1 -- 2
        // |
        // 3
        //
        // ump[1] = {2, 3}
        // ump[2] = {1}
        // ump[3] = {1}
        unordered_map<int, vector<int>> ump;


        // Process each edge one by one
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];

            // Create a fresh visited array for this BFS.
            vector<bool> visited(n + 1, false);


            // Check whether u and v already exist
            // and whether there is already a path
            // from u to v.
            //
            // If a path exists, adding (u,v) creates a cycle.
            if(ump.find(u) != ump.end() && ump.find(v) != ump.end() && bfs(u, v, visited, ump))
            {
                // Current edge is redundant
                return x;
            }


            // No existing path between u and v,
            // so safely add this edge to the graph.
            //
            // Since this is an undirected graph,
            // add both directions.
            ump[u].push_back(v);
            ump[v].push_back(u);
        }

        // No redundant edge found
        return {};
    }
};

/*   

🧠 How to remember the logic
For every edge (u, v):

        Are u and v already connected?
                    │
              ┌─────┴─────┐
             YES          NO
              │            │
          Cycle          Add edge
              │
        Return (u, v)

┌────────────────────────────────────┐
│       REDUNDANT CONNECTION         │
├────────────────────────────────────┤
│ Approach : BFS + HashMap           │
│                                    │
│ For every edge (u,v):              │
│                                    │
│ 1. BFS from u → v                  │
│ 2. If path exists → cycle          │
│ 3. Return current edge             │
│ 4. Otherwise add edge              │
│                                    │
│ BFS       → Queue                  │
│ Graph     → Adjacency List         │
│                                    │
│ Time  : O(E × (V + E))             │
│ Space : O(V + E)                   │
│                                    │
│ KEY: "Already connected?"          │
│       YES → Redundant edge         │
└────────────────────────────────────┘

*/

**************************************************APPROACH 3rd(DSU)**************************************************

class DSU             // Time  : O(E × α(V)) ≈ O(E)                      Space : O(V)  
{
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor
    DSU(int n)
    {
        // Create space for nodes 0 to n
        parent.resize(n + 1);

        // Initially rank of every node is 0
        rank.resize(n + 1);

        // Initially, every node is its own parent.
        //
        // Example:
        // parent[1] = 1
        // parent[2] = 2
        // parent[3] = 3
        //
        // This means every node is initially
        // in its own separate set.
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }


    // Find the ultimate/root parent of a node
    int find(int u)
    {
        // If u is its own parent,
        // then u is the root of this set.
        if(parent[u] == u)
        {
            return u;
        }

        // Path Compression
        //
        // Find the ultimate parent and directly
        // connect u to that parent.
        return parent[u] = find(parent[u]);
    }


    // Combine the sets containing u and v
    void Union(int u, int v)
    {
        // Find the ultimate parents of u and v
        int uParent = find(u);
        int vParent = find(v);

        // If both have the same parent,
        // they are already connected.
        //
        // We don't need to merge them again.
        if(uParent == vParent)
        {
            return;
        }


        // Union by Rank
        //
        // Attach the smaller tree under
        // the larger tree.
        if(rank[uParent] < rank[vParent])
        {
            parent[uParent] = vParent;
        }
        else if(rank[uParent] > rank[vParent])
        {
            parent[vParent] = uParent;
        }
        else
        {
            // Both trees have the same rank.
            //
            // Make vParent a child of uParent.
            parent[vParent] = uParent;

            // Since the two trees have the same height,
            // the resulting tree's rank increases.
            rank[uParent]++;
        }
    }
};


class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        // Create DSU for nodes 1 to n
        DSU dsu(n);

        // Process every edge
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];

            // Check whether u and v already belong
            // to the same connected component.
            //
            // If they have the same ultimate parent,
            // there is already a path between u and v.
            //
            // Therefore, adding this edge creates a cycle.
            if(dsu.find(u) == dsu.find(v))
            {
                return x;
            }

            // u and v belong to different components,
            // so safely merge their components.
            dsu.Union(u, v);
        }

        // No redundant edge found
        return {};
    }
};

/*

┌────────────────────────────────────┐
│       REDUNDANT CONNECTION         │
├────────────────────────────────────┤
│ Approach : DSU / Union-Find        │
│                                    │
│ For every edge (u,v):              │
│                                    │
│ 1. Find parent of u                │
│ 2. Find parent of v                │
│ 3. Same parent → cycle             │
│ 4. Different → Union them          │
│                                    │
│ Optimizations:                     │
│ • Path Compression                 │
│ • Union by Rank                    │
│                                    │
│ Time  : O(E × α(V)) ≈ O(E)         │
│ Space : O(V)                       │
│                                    │
│ KEY: Same parent → Redundant       │
└────────────────────────────────────┘

*/
