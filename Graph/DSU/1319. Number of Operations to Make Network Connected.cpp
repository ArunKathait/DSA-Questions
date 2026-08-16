***************************************************APPROACH 1st(DFS)**************************************************

class Solution { // Time  → O(n + E)       Space → O(n + E)
public:

    // DFS function to visit all nodes belonging
    // to the same connected component.
    void dfs(int node, vector<bool>& visited,
             unordered_map<int, vector<int>>& adj)
    {
        // Mark the current node as visited.
        visited[node] = true;

        // Traverse all neighbors of the current node.
        for(auto &neighbor : adj[node])
        {
            // If this neighbor has not been visited,
            // recursively visit it.
            if(!visited[neighbor])
            {
                dfs(neighbor, visited, adj);
            }
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections)
    {
        // To connect n computers into one network,
        // we need at least n - 1 connections.
        //
        // Example:
        // 4 computers need at least 3 connections.
        //
        // If we don't have n - 1 connections,
        // it is impossible to connect all computers.
        if(connections.size() < n - 1)
        {
            return -1;
        }


        // visited[i] tells whether computer i
        // has already been visited by DFS.
        vector<bool> visited(n, false);


        // Adjacency list representation of the graph.
        //
        // Example connection:
        // [0, 1]
        //
        // means:
        // 0 → 1
        // 1 → 0
        //
        // because the graph is undirected.
        unordered_map<int, vector<int>> adj;


        // Build the adjacency list.
        for(auto &x : connections)
        {
            int u = x[0];
            int v = x[1];

            // Add v as a neighbor of u.
            adj[u].push_back(v);

            // Add u as a neighbor of v.
            adj[v].push_back(u);
        }


        // Number of connected components.
        int components = 0;


        // Check every computer.
        for(int i = 0; i < n; i++)
        {
            // If this computer has not been visited,
            // it represents a new connected component.
            if(!visited[i])
            {
                components++;

                // Visit every computer connected
                // to this computer.
                dfs(i, visited, adj);
            }
        }


        // Suppose there are k connected components.
        //
        // To connect:
        //
        // Component 1
        // Component 2
        // Component 3
        //
        // We need:
        //
        // Component 1 -- Component 2 -- Component 3
        //
        // Number of operations = k - 1.
        return components - 1;
    }
};

/* 

┌─────────────────────────────────────────┐
│     NUMBER OF OPERATIONS — CHEAT SHEET  │
├─────────────────────────────────────────┤
│                                         │
│ Step 1: Need at least n - 1 edges       │
│                                         │
│ Step 2: Build adjacency list            │
│                                         │
│ Step 3: DFS/BFS to count components     │
│                                         │
│ Step 4: Answer = components - 1         │
│                                         │
│ KEYWORD:                                │
│ "k components → k - 1 operations"       │
│                                         │
│ Time  → O(n + E)                        │
│ Space → O(n + E)                        │
└─────────────────────────────────────────┘

*/

*************************************************APPROACH 2nd(BFS)***************************************************

class Solution {// Time  → O(n + E)                        Space → O(n + E)
public:

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        // ---------------------------------------------------------
        // STEP 1: Check whether we have enough cables.
        // ---------------------------------------------------------
        //
        // To connect n computers into ONE connected network,
        // we need at least n - 1 edges.
        //
        // Example:
        //
        // 4 computers:
        //
        // 0 ---- 1 ---- 2 ---- 3
        //
        // We need 3 edges = 4 - 1.
        //
        // If connections < n - 1, there are simply not enough
        // cables to connect all computers.
        if(connections.size() < n - 1)
        {
            return -1;
        }


        // ---------------------------------------------------------
        // STEP 2: Build the adjacency list.
        // ---------------------------------------------------------
        //
        // The graph is UNDIRECTED.
        //
        // If we have:
        //
        // [0, 1]
        //
        // It means:
        //
        // 0 ---- 1
        //
        // So we store both:
        //
        // 0 -> 1
        // 1 -> 0
        unordered_map<int, vector<int>> adj;


        for(auto &x : connections)
        {
            int u = x[0];
            int v = x[1];

            // Add v as a neighbor of u.
            adj[u].push_back(v);

            // Add u as a neighbor of v.
            adj[v].push_back(u);
        }


        // ---------------------------------------------------------
        // STEP 3: Keep track of visited computers.
        // ---------------------------------------------------------
        //
        // visited[i] = true
        // means computer i has already been explored.
        //
        // Initially, no computer has been visited.
        vector<bool> visited(n, false);


        // ---------------------------------------------------------
        // STEP 4: Count connected components.
        // ---------------------------------------------------------
        //
        // A connected component is simply a GROUP of computers
        // where every computer is reachable from the others.
        //
        // Example:
        //
        // 0 ---- 1 ---- 2       3 ---- 4       5
        //
        // Component 1 = {0,1,2}
        // Component 2 = {3,4}
        // Component 3 = {5}
        //
        // components = 3
        int components = 0;


        // Try starting BFS from every computer.
        for(int i = 0; i < n; i++)
        {
            // If computer i is not visited,
            // it means we have found a NEW connected component.
            if(!visited[i])
            {
                // Count this new component.
                components++;


                // -------------------------------------------------
                // STEP 5: BFS to explore this complete component.
                // -------------------------------------------------
                //
                // Starting from i, BFS will visit every computer
                // that is connected to i.
                queue<int> q;

                // Put the starting computer into the queue.
                q.push(i);

                // Mark it visited immediately.
                //
                // This prevents the same computer from being
                // inserted into the queue multiple times.
                visited[i] = true;


                // Continue until there are no more computers
                // left to explore in this component.
                while(!q.empty())
                {
                    // Get the front computer.
                    int node = q.front();

                    // Remove it from the queue.
                    q.pop();


                    // Check all computers directly connected
                    // to the current computer.
                    for(auto &neighbor : adj[node])
                    {
                        // If this neighbor has not been visited,
                        // we have discovered a new computer.
                        if(!visited[neighbor])
                        {
                            // Mark it visited.
                            visited[neighbor] = true;

                            // Add it to the queue so that
                            // its neighbors can also be explored.
                            q.push(neighbor);
                        }
                    }
                }

                // When BFS finishes:
                //
                // Every computer belonging to this component
                // has been visited.
                //
                // So the next unvisited computer will belong
                // to another component.
            }
        }


        // ---------------------------------------------------------
        // STEP 6: Connect all components.
        // ---------------------------------------------------------
        //
        // Suppose BFS found:
        //
        // components = 4
        //
        // We have:
        //
        // [Component 1] [Component 2] [Component 3] [Component 4]
        //
        // To connect them:
        //
        // C1 ---- C2 ---- C3 ---- C4
        //
        // We need:
        //
        // 4 - 1 = 3 operations.
        //
        // In general:
        //
        // k components → k - 1 operations.
        return components - 1;
    }
};

/* 

┌──────────────────────────────────────────┐
│        MAKE CONNECTED — INTUITION        │
├──────────────────────────────────────────┤
│                                          │
│ 1. Check cables                          │
│    connections < n - 1 → return -1       │
│                                          │
│ 2. Build graph                           │
│                                          │
│ 3. BFS from every unvisited computer     │
│                                          │
│ 4. Every new BFS = one component         │
│                                          │
│ 5. k components → k - 1 operations       │
│                                          │
│              ANSWER                      │
│        components - 1                    │
└──────────────────────────────────────────┘

*/

********************************************APPROACH 3rd(DSU)*********************************************************

class Solution { // Time  → O(n + E α(n)) ≈ O(n + E)                     Space → O(n)
public:

    // parent[i] = parent of node i
    vector<int> parent;

    // rank[i] = approximate height of the tree
    // Used to keep DSU trees balanced.
    vector<int> rank;


    // ---------------------------------------------------------
    // FIND
    // ---------------------------------------------------------
    // Finds the ultimate/representative parent of a node.
    int find(int node)
    {
        // If node is its own parent,
        // then node is the root of its component.
        if(parent[node] == node)
        {
            return node;
        }

        // Path Compression:
        //
        // Instead of keeping a long chain:
        //
        // 3 -> 2 -> 1 -> 0
        //
        // we directly connect 3 to 0:
        //
        // 3 ----> 0
        //
        // This makes future find() operations faster.
        return parent[node] = find(parent[node]);
    }


    // ---------------------------------------------------------
    // UNION
    // ---------------------------------------------------------
    // Merges the components containing u and v.
    void Union(int u, int v)
    {
        // Find the root of u's component.
        int parentU = find(u);

        // Find the root of v's component.
        int parentV = find(v);


        // If both have the same root,
        // they already belong to the same component.
        if(parentU == parentV)
        {
            return;
        }


        // -----------------------------------------------------
        // UNION BY RANK
        // -----------------------------------------------------
        //
        // Attach the smaller tree under the larger tree.
        if(rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }

        else if(rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }

        else
        {
            // Both trees have the same rank.
            //
            // Make parentV the parent of parentU.
            parent[parentU] = parentV;

            // Since two trees of the same height were merged,
            // the height/rank of the new root increases.
            rank[parentV]++;
        }
    }


    // ---------------------------------------------------------
    // MAIN FUNCTION
    // ---------------------------------------------------------
    int makeConnected(int n, vector<vector<int>>& connections)
    {

        // -----------------------------------------------------
        // STEP 1: Check whether enough cables exist.
        // -----------------------------------------------------
        //
        // To connect n computers, we need at least n - 1
        // cables.
        //
        // Example:
        //
        // 4 computers need at least 3 cables.
        //
        // If we have fewer than n - 1 cables,
        // connecting all computers is impossible.
        if(connections.size() < n - 1)
        {
            return -1;
        }


        // -----------------------------------------------------
        // STEP 2: Initialize DSU.
        // -----------------------------------------------------

        parent.resize(n);

        // Initially rank of every node is 0.
        rank.resize(n, 0);


        // Initially every computer is its own component.
        //
        // Example for n = 5:
        //
        // parent:
        // 0 1 2 3 4
        //
        // Components:
        // {0} {1} {2} {3} {4}
        //
        // Therefore initially:
        //
        // components = n
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }


        // -----------------------------------------------------
        // STEP 3: Initially there are n components.
        // -----------------------------------------------------
        //
        // Example:
        //
        // n = 5
        //
        // {0} {1} {2} {3} {4}
        //
        // components = 5
        int components = n;


        // -----------------------------------------------------
        // STEP 4: Process every cable.
        // -----------------------------------------------------
        for(auto &x : connections)
        {
            int u = x[0];
            int v = x[1];


            // Find the root of u.
            int parent_u = find(u);

            // Find the root of v.
            int parent_v = find(v);


            // -------------------------------------------------
            // CASE 1: Different components
            // -------------------------------------------------
            //
            // Example:
            //
            // {0}   {1}
            //
            // Edge = (0,1)
            //
            // They are different components.
            //
            // Union them:
            //
            // {0,1}
            //
            // Number of components decreases by 1.
            if(parent_u != parent_v)
            {
                Union(u, v);

                components--;
            }


            // -------------------------------------------------
            // CASE 2: Same component
            // -------------------------------------------------
            //
            // Example:
            //
            // {0,1,2}
            //
            // Edge = (0,2)
            //
            // 0 and 2 are already connected.
            //
            // This cable is redundant.
            //
            // We DON'T decrease components.
        }


        // -----------------------------------------------------
        // STEP 5: Calculate required operations.
        // -----------------------------------------------------
        //
        // Suppose after processing all cables:
        //
        // components = 3
        //
        // We have:
        //
        // {0,1}   {2,3}   {4}
        //
        // To connect 3 components:
        //
        // Component 1 ---- Component 2 ---- Component 3
        //
        // We need:
        //
        // 3 - 1 = 2 operations.
        //
        // Therefore:
        return components - 1;
    }
};

/*

┌──────────────────────────────────────────────────────────────┐
│          🔗 LEETCODE 1319 — DSU INTUITION                    │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│ 🎯 GOAL:                                                     │
│ Connect all computers using the given cables.                │
│                                                              │
│ 1️⃣ INITIAL STATE                                             │
│                                                              │
│ n computers = n separate components                          │ 
│                                                              │
│ {0}  {1}  {2}  {3}  {4}                                      │
│                                                              │
│ components = n                                               │
│                                                              │
│                                                              │
│ 2️⃣ PROCESS EACH CABLE                                        │
│                                                              │
│ For edge (u, v):                                             │
│                                                              │
│       find(u) == find(v) ?                                   │
│                                                              │
│       ┌──────────────┬────────────────┐                      │
│       │ YES          │ NO             │                      │
│       │              │                │                      │
│       │ Already      │ Different      │                      │
│       │ connected    │ components     │                      │
│       │              │                │                      │
│       │ ↓            │ ↓              │                      │
│       │ Redundant    │ UNION          │                      │
│       │ cable        │ components--   │                      │
│       └──────────────┴────────────────┘                      │
│                                                              │
│                                                              │
│ 3️⃣ WHY components-- ?                                       │
│                                                              │
│ If we have:                                                  │
│                                                              │
│ {0,1}   {2,3}                                                │
│                                                              │
│ and edge (1,2) comes:                                        │
│                                                              │
│ {0,1} ─── {2,3}                                              │
│                                                              │
│ Two groups become ONE group.                                 │
│                                                              │
│ Therefore:                                                   │
│       components = components - 1                            │
│                                                              │
│                                                              │
│ 4️⃣ REDUNDANT CABLE                                           │
│                                                              │
│ If:                                                           │
│                                                              │
│ {0,1,2}                                                       │
│                                                              │
│ and edge (0,2) comes:                                        │
│                                                              │
│ find(0) == find(2)                                           │
│                                                              │
│ They are already connected.                                  │
│                                                              │
│ → Cable is redundant                                         │
│ → components does NOT decrease                               │
│                                                              │
│                                                              │
│ 5️⃣ WHY CHECK n - 1 ?                                         │
│                                                              │
│ A connected graph with n nodes needs at least n - 1 edges.   │
│                                                              │
│ connections.size() < n - 1                                   │
│                 ↓                                            │
│          Impossible → -1                                     │
│                                                              │
│                                                              │
│ 6️⃣ FINAL ANSWER                                              │
│                                                              │
│ If there are k components:                                   │
│                                                              │
│ {A}   {B}   {C}   {D}                                        │
│                                                              │
│ Need:                                                        │
│                                                              │
│ A ─ B ─ C ─ D                                                │
│                                                              │
│ Operations = k - 1                                           │
│                                                              │
│ return components - 1                                        │
│                                                              │
├──────────────────────────────────────────────────────────────┤
│ 🧠 CHIT WORD:                                                │
│                                                              │
│ Different Parent → UNION → components--                      │
│ Same Parent      → Redundant Cable                           │
│ Final Answer     → components - 1                            │
└──────────────────────────────────────────────────────────────┘

*/

