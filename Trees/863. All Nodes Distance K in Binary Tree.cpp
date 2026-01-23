

class Solution {// TC ---> O(N)                                      SC ---> O(N)
public:

    // STEP 1:
    // Build parent mapping so that from any node
    // we can move UP to its parent
    void buildParentMap(TreeNode* currentNode,unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        // Base case
        if(currentNode == NULL)
        {
            return ;
        }

        // If left child exists, map it to its parent
        if(currentNode->left)
        {
            parentMap[currentNode->left] = currentNode;
            buildParentMap(currentNode->left, parentMap);
        }

        // If right child exists, map it to its parent
        if(currentNode->right)
        {
            parentMap[currentNode->right] = currentNode;
            buildParentMap(currentNode->right, parentMap);
        }
    }

    // STEP 2:
    // BFS from target node to find all nodes at distance k
    vector<int> bfsFromTarget(TreeNode* targetNode,int k,unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        vector<int> result;

        // Queue for level-order BFS
        queue<TreeNode*> nodeQueue;

        // To avoid revisiting nodes
        unordered_set<TreeNode*> visited;

        // Start BFS from target node
        nodeQueue.push(targetNode);
        visited.insert(targetNode);

        int currentDistance = 0;

        // Standard BFS traversal
        while(!nodeQueue.empty())
        {
            int levelSize = nodeQueue.size();

            // If we have reached distance k, stop BFS
            if(currentDistance == k)
            {
                break;
            }

            // Process current level
            while(levelSize--)
            {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                // Move to LEFT child
                if(currentNode->left && !visited.count(currentNode->left))
                {
                    nodeQueue.push(currentNode->left);
                    visited.insert(currentNode->left);
                }

                // Move to RIGHT child
                if(currentNode->right && !visited.count(currentNode->right))
                {
                    nodeQueue.push(currentNode->right);
                    visited.insert(currentNode->right);
                }

                // Move to PARENT
                if(parentMap[currentNode] && !visited.count(parentMap[currentNode]))
                {
                    nodeQueue.push(parentMap[currentNode]);
                    visited.insert(parentMap[currentNode]);
                }
            }

            // Increase distance after finishing one level
            currentDistance++;
        }

        // Remaining nodes in queue are exactly at distance k
        while(!nodeQueue.empty())
        {
            result.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
        }

        return result;
    }

    // MAIN FUNCTION
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k)
    {
        if(root == NULL)
            return {};

        // Map to store parent of each node
        unordered_map<TreeNode*, TreeNode*> parentMap;

        // Build parent relationships
        buildParentMap(root, parentMap);

        // Perform BFS starting from target node
        return bfsFromTarget(target, k, parentMap);
    }
};
