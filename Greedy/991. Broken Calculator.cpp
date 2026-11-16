**********************************************APPROACH 1st(RECURSION)*************************************************

class Solution {
public:
    int brokenCalc(int startValue, int target) {

        // Base Case:
        // If startValue is greater than or equal to target,
        // we can reach startValue by subtracting 1 (target - startValue)
        // times in the reverse direction.
        // Equivalently, in the original direction, increment? 
        // The required original operations are startValue - target
        // only when target <= startValue.
        if(startValue >= target)
        {
            return startValue - target;
        }

        // If target is even:
        // Reverse the original multiplication by 2
        // by dividing target by 2.
        // +1 represents the operation performed.
        if(target % 2 == 0)
        {
            return 1 + brokenCalc(startValue, target / 2);
        }

        // If target is odd:
        // We cannot divide it by 2 directly.
        // Increment target by 1 to make it even,
        // then the next recursive call can divide it by 2.
        // +1 represents this reverse operation.
        return 1 + brokenCalc(startValue, target + 1);
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Broken Calculator (LC 991)          │
├──────────────────────────────────────────────┤
│ • Approach: Recursion + Greedy               │
│ • Key Idea: Work backwards from target.      │
│   Even → Divide by 2                         │
│   Odd  → Add 1                               │
│ • Base Case: startValue >= target            │
│ • Pattern: Greedy + Reverse Operations       │
├──────────────────────────────────────────────┤
│ • Time Complexity:       O(log target)       │
│ • Auxiliary Space:       O(log target)       │
│ • Output Space:          O(1)                │
└──────────────────────────────────────────────┘

*/

**********************************************APPROACH 2nd**************************************************************

class Solution {
public:
    int brokenCalc(int startValue, int target) {

        // If both values are equal, no operation is required
        if(startValue == target)
        {
            return 0;
        }

        int ans = 0; // Counts the number of reverse operations

        // Work backwards while target is greater than startValue
        while(startValue < target)
        {
            // If target is even, reverse multiplication by 2
            // by dividing target by 2
            if(target % 2 == 0)
            {
                target /= 2;
            }
            // If target is odd, increment it by 1
            // to make it even so that we can divide it by 2
            else
            {
                target++;
            }

            // Count each reverse operation
            ans++;
        }

        // If target becomes smaller than startValue,
        // the remaining difference can be covered using
        // (startValue - target) decrement operations
        // in the original direction.
        return ans + (startValue - target);
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Broken Calculator (LC 991)          │
├──────────────────────────────────────────────┤
│ • Approach: Iterative Greedy                 │
│ • Key Idea: Work backwards from target.      │
│   Even → Divide by 2                         │
│   Odd  → Add 1                               │
│ • Base Case: startValue == target            │
│ • Remaining: startValue - target             │
│ • Pattern: Greedy + Reverse Operations       │
├──────────────────────────────────────────────┤
│ • Time Complexity:       O(log target)       │
│ • Auxiliary Space:       O(1)                │
│ • Output Space:          O(1)                │
└──────────────────────────────────────────────┘

*/
