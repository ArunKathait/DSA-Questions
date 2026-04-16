
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
