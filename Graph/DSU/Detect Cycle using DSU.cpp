
class Solution { // Time: O(V + E α(V)) ≈ O(V + E)            Space: O(V)
public:

    // parent[i] = parent of node i
    // Initially, every node is its own parent.
    vector<int> parent;

    // rank[i] = approximate height/size information of the tree
    // Used to keep the DSU tree balanced.
    vector<int> rank;


    // find(node) returns the ultimate parent/representative
    // of the component to which 'node' belongs.
    int find(int node)
    {
        // If node is its own parent,
        // then it is the representative of its component.
        if(parent[node] == node)
        {
            return node;
        }

        // Path Compression:
        // Directly connect 'node' to its ultimate parent.
        //
        // This makes future find() operations much faster.
        return parent[node] = find(parent[node]);
    }


    // Union two nodes/components.
    // Union by Rank keeps the DSU tree balanced.
    void Union(int u, int v)
    {
        // Find the ultimate parents of u and v.
        int parentU = find(u);
        int parentV = find(v);

        // If both have the same parent,
        // they are already in the same component.
        if(parentU == parentV)
        {
            return;
        }

        // Attach the smaller-rank tree under
        // the larger-rank tree.
        if(rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }

        // Attach parentV under parentU.
        else if(rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }

        // Both trees have the same rank.
        else
        {
            // Make parentV the parent of parentU.
            parent[parentU] = parentV;

            // Since the height of the tree may increase,
            // increase the rank of parentV.
            rank[parentV]++;
        }
    }


    // Detect cycle in an undirected graph using DSU.
    bool detectCycle(int V, vector<int> adj[])
    {
        // Create space for V vertices.
        parent.resize(V);

        // Initialize rank of every vertex to 0.
        rank.assign(V, 0);


        // Initially, every vertex is an independent component.
        //
        // Example:
        // 0 → 0
        // 1 → 1
        // 2 → 2
        // 3 → 3
        //
        // No nodes are connected initially.
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }


        // Traverse every vertex.
        for(int u = 0; u < V; u++)
        {
            // Traverse all neighbours of u.
            for(auto &v : adj[u])
            {
                // Since the graph is undirected,
                // edge (u,v) appears twice:
                //
                // u → v
                // v → u
                //
                // Process the edge only once.
                if(u < v)
                {
                    // Find the ultimate parent of u.
                    int parentU = find(u);

                    // Find the ultimate parent of v.
                    int parentV = find(v);


                    // If both nodes already belong
                    // to the same component,
                    // adding this edge creates a cycle.
                    if(parentU == parentV)
                    {
                        return true;
                    }


                    // u and v belong to different components.
                    // Merge those two components.
                    Union(u, v);
                }
            }
        }

        // If no edge created a cycle,
        // the graph is cycle-free.
        return false;
    }
};

/*   

┌────────────────────────────────────────────┐
│              DSU CYCLE LOGIC               │
├────────────────────────────────────────────┤
│                                            │
│       Edge (u, v)                          │
│            ↓                               │
│      find(u), find(v)                      │
│            ↓                               │
│     Same parent?                           │
│       /       \                            │
│     YES        NO                          │
│      ↓          ↓                          │
│   CYCLE       UNION                        │
│                                            │
└────────────────────────────────────────────┘

*/
