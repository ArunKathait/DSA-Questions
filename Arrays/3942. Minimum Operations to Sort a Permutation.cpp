class Solution {// TC ---> O(N)                                 SC ---> O(1)
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ascCount = 0;
        int descCount = 0;

        // Count consecutive elements following ascending cyclic order:
        // nums[i] should be (nums[i - 1] + 1) % n.
        // Example: 0, 1, 2, 3, 4, 0, ...
        for (int i = 1; i < n; i++) 
        {
            ascCount += (nums[i] == (nums[i - 1] + 1) % n);

            // Count consecutive elements following descending cyclic order:
            // nums[i - 1] should be (nums[i] + 1) % n.
            // Example: 4, 3, 2, 1, 0, 4, ...
            descCount += (nums[i - 1] == (nums[i] + 1) % n);
        }

        // If the entire array follows ascending cyclic order
        // and starts with 0, it is already in the desired state.
        if (ascCount == n - 1 && nums[0] == 0) 
        {
            return 0;
        }

        // If the array follows ascending cyclic order,
        // calculate the cost of correcting it from either side.
        if (ascCount == n - 1) 
        {
            // Operations required to move the first element to 0.
            int leftOperation = n - nums[0];

            // Operations required to correct the array from the right.
            int rightOperation = 1 + (nums.back() + 1) + 1;

            // Return the smaller number of operations.
            return min(leftOperation, rightOperation);
        }

        // If the array follows descending cyclic order,
        // calculate the cost of correcting it from either side.
        if (descCount == n - 1) 
        {
            // Operations required to correct the array from the left.
            int leftOperation = n - nums.back() + 1;

            // Operations required to correct the array from the right.
            int rightOperation = (nums[0] + 1) % n + 1;

            // Return the smaller number of operations.
            return min(leftOperation, rightOperation);
        }

        // If neither ascending nor descending cyclic order holds,
        // the required transformation is considered impossible.
        return -1;
    }
};
