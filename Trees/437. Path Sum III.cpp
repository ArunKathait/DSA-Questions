
class Solution {// TC ---> O(n)                                  SC ---> O(n)
public:

    // DFS function to find number of paths having sum = targetSum
    //
    // root        -> current node we are visiting
    // currentSum  -> prefix sum from root to current node
    // targetSum   -> required path sum
    // prefixCount -> stores frequency of prefix sums
    // pathCount   -> stores total number of valid paths
    void dfs(TreeNode* root,long long &currentSum,int targetSum,unordered_map<long long,int>& prefixCount,
             int& pathCount)
    {
        // Base case:
        // If node is NULL, there is nothing to process
        if(root == NULL)
        {
            return;
        }


        // Add current node value to the running prefix sum
        //
        // Example:
        // Path: 10 -> 5 -> 3
        // currentSum = 10 + 5 + 3 = 18
        currentSum += root->val;



        // Check if there exists a previous prefix sum such that:
        //
        // currentSum - previousSum = targetSum
        //
        // Therefore:
        //
        // previousSum = currentSum - targetSum
        //
        // If this previousSum exists in the map,
        // then the nodes between that previous prefix
        // and current node form a valid path.
        if(prefixCount.find(currentSum - targetSum) != prefixCount.end())
        {
            // Add the number of times this prefix sum occurred
            //
            // because there can be multiple paths ending here
            pathCount += prefixCount[currentSum - targetSum];
        }

        // Store the current prefix sum in the map
        //
        // This helps future nodes check whether
        // they can form a path with targetSum
        prefixCount[currentSum]++;

        // Explore left subtree
        dfs(root->left,currentSum,targetSum,prefixCount,pathCount);

        // Explore right subtree
        dfs(root->right,currentSum,targetSum,prefixCount,pathCount);

        // Backtracking step
        //
        // Remove current prefix sum because after returning
        // to parent, this node should not affect another branch.
        //
        // Example:
        //
        //        10
        //       /  \
        //      5    3
        //
        // Prefix sums from left side should not be considered
        // while exploring right side.
        prefixCount[currentSum]--;

        // Backtrack currentSum
        //
        // Since currentSum is passed by reference,
        // we must restore its previous value.
        currentSum -= root->val;
    }



    int pathSum(TreeNode* root, int targetSum)
    {
        // HashMap to store:
        //
        // prefix sum -> number of occurrences
        //
        unordered_map<long long,int> prefixCount;

        // Initially we have an empty path with sum = 0
        //
        // This handles paths that start from the root.
        //
        // Example:
        //
        // Tree:
        //     5
        //    /
        //   3
        //
        // targetSum = 8
        //
        // currentSum at node 3 = 8
        //
        // 8 - 8 = 0
        //
        // Because prefixCount[0] exists,
        // path 5 -> 3 gets counted.
        prefixCount[0] = 1;

        // Stores final answer
        int pathCount = 0;
        long long currentSum = 0;

        // Start DFS traversal
        //
        // Initial prefix sum is 0
        dfs(root,currentSum,targetSum,prefixCount,pathCount);

        return pathCount;
    }
};
