************************************************APPROACH 1st(BRUTE FORCE)*********************************************

class Solution {// Time  : O(N²) worst case                        Space : O(H) 
public:

    // This function calculates:
    // 1. Sum of all nodes in the current subtree
    // 2. Number of nodes in the current subtree
    //
    // 'count' is passed by reference (&), so all recursive calls
    // update the same count variable.
    int findSum(TreeNode* root, int& count) {

        // If there is no node, there is nothing to add.
        if(root == NULL) 
        {
            return 0;
        }

        // Count the current node.
        count++;

        // Find the sum of the left subtree.
        int ls = findSum(root->left, count);

        // Find the sum of the right subtree.
        int rs = findSum(root->right, count);

        // Total sum of current subtree =
        // current node + left subtree sum + right subtree sum.
        return root->val + ls + rs;
    }


    int averageOfSubtree(TreeNode* root) {

        // If tree/subtree is empty, it contributes 0
        // valid nodes to the answer.
        if(root == NULL) 
        {
            return 0;
        }

        // 'count' will store the number of nodes
        // in the current subtree.
        int count = 0;

        // 'ans' stores how many nodes satisfy:
        // node value == average of its subtree.
        int ans = 0;

        // findSum() gives us the sum of the current subtree.
        // At the same time, it updates 'count'.
        int sum = findSum(root, count);

        // Calculate the integer average of the subtree.
        //
        // Example:
        // sum = 7, count = 3
        // average = 7 / 3 = 2
        //
        // The problem uses integer division.
        if(root->val == sum / count) 
        {
            // Current node satisfies the condition,
            // so increase the answer.
            ans++;
        }

        // Recursively check the left subtree.
        //
        // The returned value tells us how many valid
        // nodes exist in the left subtree.
        ans += averageOfSubtree(root->left);

        // Recursively check the right subtree.
        //
        // Add the number of valid nodes from the
        // right subtree to our answer.
        ans += averageOfSubtree(root->right);

        // Return the total number of valid nodes
        // from current node + left subtree + right subtree.
        return ans;
    }
};

/*

╔════════════════════════════════════════════════════╗
║              AVERAGE OF SUBTREE                    ║
╠════════════════════════════════════════════════════╣
║ 🎯 IDEA                                            ║
║ For every node:                                    ║
║ average = subtreeSum / subtreeCount                ║
║                                                    ║
║ If average == node->val → count++                  ║
║                                                    ║
║ 🔑 YOUR APPROACH                                   ║
║ findSum(root, count)                               ║
║ → returns subtree sum                              ║
║ → count passed by reference                        ║
║                                                    ║                                                                                  ║
║ Time: O(N²) worst case                             ║
║ Space: O(H)                                        ║
║                                                    ║
╚════════════════════════════════════════════════════╝

*/

*********************************************APPROACH 2nd(OPTIMAL)*****************************************************
class Solution {// Time: O(N)                     Space: O(H) where H is the tree height.
public:

    // solve() returns two values for the current subtree:
    //
    // first  -> sum of all nodes in the subtree
    // second -> number of nodes in the subtree
    //
    // 'ans' is passed by reference so that every recursive call
    // can update the same answer variable.
    pair<int, int> solve(TreeNode* root, int& ans) {

        // If there is no node, then:
        // sum = 0
        // count = 0
        if(root == NULL) 
        {
            return {0, 0};
        }

        // First solve the left subtree.
        //
        // p1.first  = sum of left subtree
        // p1.second = number of nodes in left subtree
        pair<int, int> p1 = solve(root->left, ans);

        // Then solve the right subtree.
        //
        // p2.first  = sum of right subtree
        // p2.second = number of nodes in right subtree
        pair<int, int> p2 = solve(root->right, ans);

        // Calculate the total sum of the current subtree.
        //
        // Current node value
        //      +
        // Left subtree sum
        //      +
        // Right subtree sum
        int totalSum = root->val + p1.first + p2.first;

        // Calculate the total number of nodes in the current subtree.
        //
        // 1 represents the current node.
        int totalCount = 1 + p1.second + p2.second;

        // Calculate the average of the current subtree.
        //
        // Integer division is used, as required by the problem.
        int avg = totalSum / totalCount;

        // Check whether the current node's value
        // is equal to the average of its entire subtree.
        if(avg == root->val) 
        {
            ans++;
        }

        // Return the sum and count of the current subtree
        // to its parent node.
        return {totalSum, totalCount};
    }


    int averageOfSubtree(TreeNode* root) {

        // Empty tree has no valid nodes.
        if(root == NULL) 
        {
            return 0;
        }

        // Stores the number of nodes whose value equals
        // the average of their subtree.
        int ans = 0;

        // Start the Postorder DFS.
        //
        // solve() will calculate sum/count for every subtree
        // and update 'ans'.
        solve(root, ans);

        // Return the final number of valid nodes.
        return ans;
    }
};
    
/*

╔══════════════════════════════════════════════════════════╗
║          🌳 AVERAGE OF SUBTREE — OPTIMAL                ║
╠══════════════════════════════════════════════════════════╣
║ 🎯 CORE IDEA                                             ║
║ Use Postorder DFS: Left → Right → Current                ║
║                                                          ║
║ Each node returns:                                       ║
║   pair {sum, count}                                      ║
║                                                          ║
║ 🔄 FLOW                                                  ║
║   Left  → {leftSum, leftCount}                           ║
║   Right → {rightSum, rightCount}                         ║
║              ↓                                           ║
║   totalSum   = root->val + leftSum + rightSum            ║
║   totalCount = 1 + leftCount + rightCount                ║
║              ↓                                           ║
║   average = totalSum / totalCount                        ║
║              ↓                                           ║
║   if average == root->val → ans++                        ║
║              ↓                                           ║
║   return {totalSum, totalCount}                          ║
║                                                          ║
║ 🚀 WHY?                                                  ║
║ Each node is processed exactly once.                     ║
║ No repeated subtree traversal.                           ║
║                                                          ║
║ ⏱️ Time  : O(N)                                          ║
║ 💾 Space : O(H)                                          ║
║                                                          ║
║ 🧠 PATTERN                                               ║
║ Tree + Subtree Information → Postorder / Tree DP         ║
╚══════════════════════════════════════════════════════════╝

*/
