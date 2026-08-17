**********************************************APPROACH 1st(DFS)***********************************************************

class Solution {// Time Complexity  : O(N + E)              Space Complexity : O(N + E)
public:

    // DFS to find the size of the connected component
    // containing 'node'
    void dfs(int node, vector<vector<int>>& graph,
             vector<bool>& visited, long long& size) {

        // Mark current node as visited
        visited[node] = true;

        // Count current node in this component
        size++;

        // Visit all neighbours of current node
        for(int neighbour : graph[node]) {

            // If neighbour is not visited,
            // continue DFS from that neighbour
            if(!visited[neighbour]) 
            {
                dfs(neighbour, graph, visited, size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        // Adjacency list representation of the graph
        vector<vector<int>> graph(n);

        // Build the undirected graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // u and v are connected to each other
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Keep track of which nodes have already
        // been included in a connected component
        vector<bool> visited(n, false);

        // Stores the total number of unreachable pairs
        long long ans = 0;

        // Number of nodes that have not been processed
        // yet
        long long remaining = n;

        // Find every connected component
        for(int i = 0; i < n; i++) {

            // If this node has not been visited,
            // it represents a new connected component
            if(!visited[i]) 
            {
                // Stores the size of the current component
                long long size = 0;

                // Find the number of nodes in this component
                dfs(i, graph, visited, size);

                /*
                    Nodes inside the same component are reachable.

                    Therefore, a node from the current component
                    can form an unreachable pair only with a node
                    outside the current component.

                    Current component has 'size' nodes.

                    'remaining - size' nodes are outside
                    the current component.

                    Therefore:

                    unreachable pairs =
                    size * (remaining - size)
                */
                ans += size * (remaining - size);

                // Remove the current component from the
                // remaining nodes.

                // This ensures that we don't count the same
                // pair again.
                remaining -= size;
            }
        }

        // Return total number of unreachable pairs
        return ans;
    }
};

**************************************************APPROACH 2nd(BFS)***************************************************

class Solution {// Time  : O(N + E)                                              Space : O(N + E)
public:

    // BFS returns the size of the connected component
    // starting from the given node.
    long long bfs(int node, vector<vector<int>>& graph,
                  vector<bool>& visited) {

        // Queue is used for BFS traversal.
        queue<int> q;

        // Mark the starting node as visited
        // so that we don't visit it again.
        visited[node] = true;

        // Put the starting node into the queue.
        q.push(node);

        // Stores the number of nodes
        // present in this connected component.
        long long size = 0;

        // Continue BFS until there are no more
        // nodes to process.
        while(!q.empty()) {

            // Get the front node from the queue.
            int current = q.front();
            q.pop();

            // We have visited one more node
            // in the current component.
            size++;

            // Visit all neighbours of the current node.
            for(int neighbour : graph[current]) {

                // If this neighbour has not been visited,
                // add it to the BFS queue.
                if(!visited[neighbour]) {

                    // Mark it immediately as visited.
                    // This prevents adding the same node
                    // multiple times to the queue.
                    visited[neighbour] = true;

                    q.push(neighbour);
                }
            }
        }

        // Return the total number of nodes
        // in this connected component.
        return size;
    }


    long long countPairs(int n, vector<vector<int>>& edges) {

        // Create an adjacency list.
        //
        // graph[u] contains all nodes directly connected
        // to node u.
        vector<vector<int>> graph(n);


        // Build the undirected graph.
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Since the graph is undirected:
            // u is connected to v
            // and v is connected to u.
            graph[u].push_back(v);
            graph[v].push_back(u);
        }


        // Keeps track of nodes that have already
        // been included in a connected component.
        vector<bool> visited(n, false);


        // Stores the total number of unreachable pairs.
        long long ans = 0;


        // Number of nodes that are still remaining
        // to be processed.
        //
        // Initially all n nodes are remaining.
        long long remaining = n;


        // Find all connected components.
        for(int i = 0; i < n; i++) {

            // If this node is not visited,
            // it belongs to a new connected component.
            if(!visited[i]) {

                // Find the number of nodes
                // in the current connected component.
                long long size = bfs(i, graph, visited);


                /*
                    Nodes inside the same component
                    ARE reachable from each other.

                    Therefore, nodes from the current
                    component can form unreachable pairs
                    only with nodes OUTSIDE this component.

                    Current component:
                        size nodes

                    Nodes outside current component:
                        remaining - size

                    Therefore:

                    unreachable pairs =
                    size * (remaining - size)
                */
                ans += size * (remaining - size);


                /*
                    The current component is now processed.

                    Remove its nodes from 'remaining'
                    so that we don't count the same pair
                    again.
                */
                remaining -= size;
            }
        }


        // Return the total number of unreachable pairs.
        return ans;
    }
};

********************************************APPROACH 3rd(DSU)*********************************************************

class Solution {// Time: O((N + E) α(N)) ≈ O(N + E)               Space: O(N)
public:

    // parent[i] stores the parent of node i.
    //
    // Initially:
    // parent[i] = i
    //
    // This means every node is initially
    // its own connected component.
    vector<int> parent;

    // rank[i] stores the approximate height
    // of the tree whose root is i.
    //
    // We use rank to keep the DSU tree shallow.
    vector<int> rank;


    // ---------------------------------------------------
    // FIND
    // ---------------------------------------------------
    // Finds the ultimate/root parent of a node.
    //
    // Example:
    //
    // 0 -> 1 -> 2
    //
    // find(0) = 2
    //
    // Path compression makes it:
    //
    // 0 -> 2
    // 1 -> 2
    //
    // This makes future find operations faster.
    int find(int node)
    {
        // If node is its own parent,
        // then node is the root of its component.
        if(parent[node] == node)
        {
            return node;
        }

        // Find the ultimate parent and directly
        // connect the current node to that root.
        //
        // This is called PATH COMPRESSION.
        return parent[node] = find(parent[node]);
    }


    // ---------------------------------------------------
    // UNION
    // ---------------------------------------------------
    // Connects the components containing u and v.
    void Union(int u, int v)
    {
        // Find the root of u's component.
        int parentU = find(u);

        // Find the root of v's component.
        int parentV = find(v);


        // If both nodes already have the same root,
        // they already belong to the same component.
        //
        // Nothing needs to be done.
        if(parentU == parentV)
        {
            return;
        }


        // ------------------------------------------------
        // UNION BY RANK
        // ------------------------------------------------
        // Attach the smaller-rank tree below
        // the larger-rank tree.
        //
        // This keeps the DSU tree shallow.

        if(rank[parentU] < rank[parentV])
        {
            // u's tree is smaller,
            // so attach it under v's root.
            parent[parentU] = parentV;
        }

        else if(rank[parentU] > rank[parentV])
        {
            // v's tree is smaller,
            // so attach it under u's root.
            parent[parentV] = parentU;
        }

        else
        {
            // Both trees have the same rank.
            //
            // We can attach either one under the other.
            // Here, we attach parentU under parentV.
            parent[parentU] = parentV;

            // Since two trees of the same rank are
            // combined, the height can increase by 1.
            rank[parentV]++;
        }
    }


    // ---------------------------------------------------
    // COUNT PAIRS
    // ---------------------------------------------------
    long long countPairs(int n, vector<vector<int>>& edges)
    {

        // Create space for n nodes.
        parent.resize(n);

        // Initially rank of every node is 0.
        rank.resize(n, 0);


        // ------------------------------------------------
        // INITIALIZATION
        // ------------------------------------------------
        // Initially every node is a separate component.
        //
        // Example for n = 5:
        //
        // parent = [0, 1, 2, 3, 4]
        //
        // 0 is its own parent
        // 1 is its own parent
        // 2 is its own parent
        // 3 is its own parent
        // 4 is its own parent

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }


        // ------------------------------------------------
        // BUILD CONNECTED COMPONENTS
        // ------------------------------------------------
        // Every edge tells us that two nodes are connected.
        //
        // So we merge their components using Union().
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];

            Union(u, v);
        }


        // ------------------------------------------------
        // COUNT SIZE OF EACH COMPONENT
        // ------------------------------------------------
        //
        // ump[root] = number of nodes in that component.
        //
        // Example:
        //
        // Components:
        //
        // {0,1}
        // {2,3,4}
        //
        // Then:
        //
        // ump[root_of_{0,1}] = 2
        // ump[root_of_{2,3,4}] = 3

        unordered_map<int, int> ump;


        for(int i = 0; i < n; i++)
        {
            // Find the ultimate root of node i.
            int root = find(i);

            // Increase the size of that component.
            ump[root]++;
        }


        // ------------------------------------------------
        // COUNT UNREACHABLE PAIRS
        // ------------------------------------------------
        //
        // Nodes inside the SAME component are reachable.
        //
        // Nodes belonging to DIFFERENT components
        // are unreachable.
        //
        // Therefore, we need to count pairs between
        // different connected components.

        long long ans = 0;


        // Initially all n nodes are still available
        // to form pairs with the current component.
        long long remainingNodes = n;


        // Process each connected component.
        for(auto &it : ump)
        {
            // Size of the current component.
            long long size = it.second;


            /*
                Current component has:

                size

                nodes.

                Nodes outside the current component:

                remainingNodes - size


                Every node in the current component can
                pair with every node outside it.

                Therefore:

                    pairs =
                    size * (remainingNodes - size)
            */

            ans += size * (remainingNodes - size);


            /*
                The current component has now been processed.

                Remove its nodes from remainingNodes.

                This prevents counting the same pair twice.
            */

            remainingNodes -= size;
        }


        // Return total number of unreachable pairs.
        return ans;
    }
};
