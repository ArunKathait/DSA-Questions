
class Solution {// TC ---> O(k)                                                 SC ---> O(1)
public:
    int smallestRepunitDivByK(int k) {
        
        // If k is 1, the smallest repunit ("1") is already divisible by 1.
        if(k == 1)
        {
            return 1;
        }

        // 'num' will store the remainder of the repunit number when divided by k.
        // We never build the full number because it can be extremely large.
        int num = 0;

        // A repunit divisible by k will have at most 'k' digits.
        // If no such repunit exists within k iterations, answer is -1.
        for(int length = 1; length <= k; length++)
        {
            // Update the remainder:
            // Example: If current remainder is R,
            // new number is (R * 10 + 1), so update remainder using mod k.
            num = (num * 10 + 1) % k;

            // If remainder becomes 0, then the repunit of length 'length'
            // is divisible by k.
            if(num == 0)
            {
                return length;
            }
        }

        // If loop ends, no repunit number divisible by k exists.
        return -1;
    }
};

/* 
        NOTE:
        
        ✅ Short Explanation (Easy to Remember)

        1) You want the smallest number made of only 1s that is divisible by k.

        2) Instead of building the full number (like 1, 11, 111… which becomes huge),
           you only track the remainder.

        3) If remainder becomes 0, the number is divisible.

        4) At most k different remainders are possible — if it doesn't become 0 within k steps, it will never become 0 (pigeonhole principle).

    */
