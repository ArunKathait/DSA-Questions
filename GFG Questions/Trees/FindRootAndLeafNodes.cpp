**************************************************APPROACH 1st**********************************************************

#include <bits/stdc++.h>
using namespace std;

void findRootAndLeaves(vector<int>& start, vector<int>& end) {
    
    // Stores nodes that have outgoing edges (parents)
    unordered_set<int> startSet;
    
    // Stores nodes that have incoming edges (children)
    unordered_set<int> endSet;
    
    // Stores all unique nodes in the graph
    unordered_set<int> allNodes;

    // Populate startSet and allNodes
    for (int s : start) {
        startSet.insert(s);
        allNodes.insert(s);
    }

    // Populate endSet and allNodes
    for (int e : end) {
        endSet.insert(e);
        allNodes.insert(e);
    }

    // -----------------------------
    // Find Root Nodes
    // A root node has no incoming edges
    // i.e., it is not present in endSet
    // -----------------------------
    cout << "Root Nodes: ";
    for (int node : allNodes) {
        if (endSet.find(node) == endSet.end()) {
            cout << node << " ";
        }
    }
    cout << endl;

    // -----------------------------
    // Find Leaf Nodes
    // A leaf node has no outgoing edges
    // i.e., it is not present in startSet
    // -----------------------------
    cout << "Leaf Nodes: ";
    for (int node : allNodes) {
        if (startSet.find(node) == startSet.end()) {
            cout << node << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> start = {1, 1, 2, 3};
    vector<int> end   = {2, 3, 4, 5};

    findRootAndLeaves(start, end);

    return 0;
}


*****************************************************APPROACH 2nd*********************************************************

#include <bits/stdc++.h>
using namespace std;

void findRootAndLeaves(vector<int>& start, vector<int>& end) {
    
    // Set to store nodes that appear as "start" (i.e., nodes with outgoing edges)
    unordered_set<int> startSet;

    // Set to store nodes that appear as "end" (i.e., nodes with incoming edges)
    unordered_set<int> endSet;

    // Step 1: Insert all start nodes into startSet
    for (int s : start) {
        startSet.insert(s);  // storing parent nodes
    }

    // Step 2: Insert all end nodes into endSet
    for (int e : end) {
        endSet.insert(e);    // storing child nodes
    }

    // ---------------------------------------------------
    // Step 3: Find Root Nodes
    // Root = node that has NO incoming edge
    // i.e., node present in startSet but NOT in endSet
    // ---------------------------------------------------
    for (int node : startSet) {
        
        // If node is not found in endSet → no incoming edge → root
        if (endSet.find(node) == endSet.end()) {
            cout << "Root: " << node << endl;
        }
    }

    // ---------------------------------------------------
    // Step 4: Find Leaf Nodes
    // Leaf = node that has NO outgoing edge
    // i.e., node present in endSet but NOT in startSet
    // ---------------------------------------------------
    for (int node : endSet) {
        
        // If node is not found in startSet → no outgoing edge → leaf
        if (startSet.find(node) == startSet.end()) {
            cout << "Leaf: " << node << endl;
        }
    }
}

int main() {
    // Example input:
    // start[i] -> end[i] represents a directed edge
    // Example: 1 -> 2, 1 -> 3, 2 -> 4, 3 -> 5

    vector<int> start = {1, 1, 2, 3};
    vector<int> end   = {2, 3, 4, 5};

    // Function call to find root and leaf nodes
    findRootAndLeaves(start, end);

    return 0;
}
