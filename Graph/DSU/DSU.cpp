
class DSU
{
public:

    // parent[i] tells us the immediate parent of node i
    // Initially, every node is its own parent.
    vector<int> parent;

    // rank[i] represents the approximate height of the tree
    // rooted at i.
    vector<int> rank;


    // Constructor
    // Creates n separate components.
    DSU(int n)
    {
        // Create space for n nodes
        parent.resize(n);

        // Initially rank of every node is 0
        rank.resize(n, 0);

        // Initially every node is its own parent
        //
        // Example for n = 5:
        //
        // parent = [0, 1, 2, 3, 4]
        //
        // This means:
        // 0 → 0
        // 1 → 1
        // 2 → 2
        // 3 → 3
        // 4 → 4
        //
        // Therefore, initially there are 5 components.
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }


    // find(node) returns the ROOT / ULTIMATE PARENT
    // of the given node.
    //
    // The root is the node whose parent is itself.
    int find(int node)
    {
        // If node is its own parent,
        // then node is the root of this component.
        if(parent[node] == node)
        {
            return node;
        }

        // Otherwise, move towards the parent.
        //
        // IMPORTANT:
        // We also perform PATH COMPRESSION here.
        //
        // Suppose:
        //
        // 4 → 3 → 2 → 1
        //
        // find(4) will eventually find root = 1.
        //
        // Then:
        // parent[4] = 1
        //
        // So next time find(4) becomes much faster.
        return parent[node] = find(parent[node]);
    }


    // unionSet(u, v) combines the components
    // containing u and v.
    void unionSet(int u, int v)
    {
        // Find the root of u
        int rootU = find(u);

        // Find the root of v
        int rootV = find(v);


        // If both nodes already have the same root,
        // they already belong to the same component.
        //
        // Therefore, there is nothing to merge.
        if(rootU == rootV)
        {
            return;
        }


        // UNION BY RANK
        //
        // We attach the tree with smaller rank
        // below the tree with larger rank.
        //
        // This keeps the tree relatively short.


        // If rootU has smaller rank,
        // attach rootU under rootV.
        if(rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }


        // If rootV has smaller rank,
        // attach rootV under rootU.
        else if(rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }


        // If both ranks are equal,
        // we can choose either root.
        //
        // Here we choose rootU as the parent.
        //
        // Since both trees have the same height,
        // attaching one below the other increases
        // the height by 1.
        else
        {
            parent[rootV] = rootU;

            // Increase the rank of the new root.
            rank[rootU]++;
        }
    }
};

/* 

┌─────────────────────────────────────────────────────────────────────┐
│                         DSU / UNION-FIND                            │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│ WHAT IS DSU?                                                        │
│ DSU = Disjoint Set Union                                            │
│ Also called: Union-Find                                             │
│                                                                     │
│ Main purpose:                                                       │
│ Track and merge connected/disjoint groups (components).             │
│                                                                     │
│ KEYWORD TO REMEMBER                                                 │
│                                                                     │
│              DSU = FIND + UNION                                     │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ 1. parent[]                                                         │
│                                                                     │
│ parent[i] = immediate parent of node i                              │
│                                                                     │
│ Initially:                                                          │
│ parent[i] = i                                                       │
│                                                                     │
│ Meaning: every node starts as a separate component.                 │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ 2. find(node)                                                       │
│                                                                     │
│ Purpose: Find the ROOT / ULTIMATE PARENT of a node.                  │
│                                                                     │
│ Root condition:                                                     │
│ parent[node] == node                                                │
│                                                                     │
│ Example:                                                            │
│     3 → 2 → 1                                                       │
│                                                                     │
│ find(3) = 1                                                         │
│                                                                     │
│ KEYWORD: "Who is my ultimate parent?"                               │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ 3. PATH COMPRESSION                                                 │
│                                                                     │
│ Code:                                                               │
│ parent[node] = find(parent[node])                                   │
│                                                                     │
│ Purpose: Make the tree flatter.                                     │
│                                                                     │
│ Before:                                                             │
│     5 → 4 → 3 → 2 → 1                                               │
│                                                                     │
│ After find(5):                                                      │
│     5 ─┐                                                             │
│     4 ─┤                                                             │
│     3 ─┤ → 1                                                        │
│     2 ─┘                                                             │
│                                                                     │
│ KEYWORD: "Flatten the tree"                                         │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ 4. unionSet(u, v)                                                   │
│                                                                     │
│ Purpose: Merge the components containing u and v.                   │
│                                                                     │
│ First:                                                               │
│ rootU = find(u)                                                     │
│ rootV = find(v)                                                     │
│                                                                     │
│ If: rootU == rootV                                                  │
│ → Already connected                                                 │
│ → Do nothing                                                        │
│                                                                     │
│ Otherwise:                                                          │
│ → Merge the two roots                                               │
│                                                                     │
│ KEYWORD: "Merge two components"                                     │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ 5. UNION BY RANK                                                    │
│                                                                     │
│ rank[root] = approximate height of the tree                         │
│                                                                     │
│ Rule:                                                               │
│                                                                     │
│ Smaller rank → attach under larger rank                             │
│                                                                     │
│ Same rank → attach one under another + increase rank                │
│                                                                     │
│ KEYWORD: "Keep tree short"                                          │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ WHY TWO OPTIMIZATIONS?                                               │
│                                                                     │
│ Path Compression                                                    │
│        ↓                                                            │
│ Flattens the tree                                                   │
│                                                                     │
│ Union by Rank                                                        │
│        ↓                                                            │
│ Prevents tall trees                                                  │
│                                                                     │
│ Together                                                             │
│        ↓                                                            │
│ Very fast DSU                                                        │
│                                                                     │
│ Time: O(α(n)) amortized per operation                               │
│ Space: O(n)                                                          │
│                                                                     │
│ α(n) = inverse Ackermann function                                   │
│ Practically almost O(1).                                            │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ MOST IMPORTANT MENTAL MODEL                                          │
│                                                                     │
│       union(u, v)                                                    │
│            ↓                                                         │
│       find(u) → rootU                                                │
│       find(v) → rootV                                                │
│            ↓                                                         │
│       rootU == rootV ?                                               │
│        /          \                                                  │
│      YES           NO                                                 │
│       ↓             ↓                                                │
│ Already          Merge roots                                         │
│ connected            ↓                                               │
│                  Use rank                                             │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ WHEN SHOULD I THINK OF DSU?                                          │
│                                                                     │
│ Look for keywords such as:                                           │
│                                                                     │
│ • Connected components                                               │
│ • Merge groups                                                       │
│ • Dynamic connectivity                                               │
│ • Are two nodes connected?                                           │
│ • Redundant edge                                                     │
│ • Detect cycle in an undirected graph                                │
│ • Number of components                                               │
│ • Network connections                                                │
│ • Accounts/people belonging to same group                            │
│ • Connecting islands/nodes                                           │
│                                                                     │
│ ─────────────────────────────────────────────────────────────────── │
│                                                                     │
│ MUST REMEMBER                                                        │
│                                                                     │
│ parent[]  → Who is my parent?                                       │
│ find()    → Who is my root?                                         │
│ union()   → Merge two groups                                        │
│ rank[]    → Which tree should become parent?                        │
│ compression → Flatten the tree                                      │
│                                                                     │
│              DSU = FIND + UNION                                     │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘

🧠 One-line memory trick

Find = find the leader. Union = merge the groups. Rank = keep the tree short. Path Compression = flatten the tree.

*/
