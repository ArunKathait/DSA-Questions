
class Solution {// Time Complexity: O(n × m)                  Space Complexity: O(n + m)
public:
    string multiply(string num1, string num2) {

        // If either number is 0, the multiplication result is 0.
        // This also avoids unnecessary processing.
        if(num1 == "0" || num2 == "0")
        {
            return "0";
        }

        // Length of both input strings
        int n = num1.size();
        int m = num2.size();

        // When multiplying an n-digit number with an m-digit number,
        // the result can have at most n + m digits.
        //
        // Example:
        // 99 × 99 = 9801
        // n = 2, m = 2
        // Maximum result size = 4 = n + m
        //
        // Initially, all positions contain 0.
        vector<int> ans(n + m, 0);

        // Start from the LAST digit of num1.
        //
        // We start from right to left because multiplication
        // works from the units place.
        for(int i = n - 1; i >= 0; i--)
        {
            // Start from the LAST digit of num2.
            for(int j = m - 1; j >= 0; j--)
            {
                // Convert character digit into integer digit.
                //
                // Example:
                // '7' - '0' = 7
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                // Multiply the two individual digits.
                int product = digit1 * digit2;

                // The multiplication of digits at positions i and j
                // contributes to position i + j + 1.
                //
                // Example:
                //
                //       1 2
                //     × 3 4
                //
                // 2 × 4 contributes to the units position.
                //
                // Therefore:
                // pos1 = i + j + 1
                int pos1 = i + j + 1;

                // The carry goes to the position immediately
                // before pos1.
                int pos2 = i + j;

                // Add the product to the current position.
                //
                // We use += because multiple digit multiplications
                // can contribute to the same position.
                ans[pos1] += product;

                // If ans[pos1] becomes greater than 9,
                // take its carry and add it to the previous position.
                //
                // Example:
                // ans[pos1] = 17
                //
                // 17 / 10 = 1 → carry
                // So add 1 to ans[pos2].
                ans[pos2] += ans[pos1] / 10;

                // Keep only the last digit at pos1.
                //
                // Example:
                // 17 % 10 = 7
                //
                // So:
                // ans[pos1] = 7
                ans[pos1] %= 10;
            }
        }

        // Now ans contains the digits of the answer,
        // but it may contain leading zeroes.
        //
        // Example:
        // ans = [0, 0, 5, 6, 0]
        //
        // We need to start from 5.
        int i = 0;

        // Skip all leading zeroes.
        while(i < ans.size() && ans[i] == 0)
        {
            i++;
        }

        // Safety check.
        //
        // If every element was 0, the answer is "0".
        if(i == ans.size())
        {
            return "0";
        }

        // Convert the integer digits stored in ans
        // into a string.
        string res;

        while(i < ans.size())
        {
            // Convert the integer digit into a string
            // and append it to the result.
            //
            // Example:
            // ans[i] = 5
            // res = "5"
            //
            // ans[i] = 6
            // res = "56"
            res += to_string(ans[i]);

            // Move to the next digit.
            i++;
        }

        // Return the final multiplication result.
        return res;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│                 MULTIPLY STRINGS                     │
├──────────────────────────────────────────────────────┤
│                                                      │
│ Problem:                                             │
│ Multiply two BIG numbers given as strings.           │
│ Cannot convert them to int/long long.                │
│                                                      │
├──────────────────────────────────────────────────────┤
│ INTUITION                                            │
│                                                      │
│ Simulate multiplication like we do on paper.         │
│                                                      │
│     1 2 3                                            │
│   ×   4 5                                            │
│   -------                                            │
│                                                      │
│ Multiply EVERY digit pair.                           │
│ Store each product in the correct position.          │
│ Handle carry.                                        │
│                                                      │
├──────────────────────────────────────────────────────┤
│ KEY IDEA                                             │
│                                                      │
│ Create:                                              │
│   vector<int> ans(n + m, 0)                          │
│                                                      │
│ For digits num1[i] and num2[j]:                      │
│                                                      │
│   product = digit1 × digit2                          │
│                                                      │
│   pos1 = i + j + 1   → current digit                 │
│   pos2 = i + j       → carry                         │
│                                                      │
├──────────────────────────────────────────────────────┤
│ MOST IMPORTANT CODE                                  │
│                                                      │
│   ans[pos1] += product;                              │
│   ans[pos2] += ans[pos1] / 10;                       │
│   ans[pos1] %= 10;                                   │
│                                                      │
├──────────────────────────────────────────────────────┤
│ WHY i + j + 1 ?                                      │
│                                                      │
│ Digits at positions i and j contribute to:           │
│                                                      │
│       i + j       → carry                            │
│       i + j + 1   → digit                            │
│                                                      │
│ Example:                                             │
│   2 × 4 = 8                                          │
│   8 goes to the units position.                      │
│                                                      │
├──────────────────────────────────────────────────────┤
│ ALGORITHM                                            │
│                                                      │
│ 1. If either number is "0", return "0".              │
│                                                      │
│ 2. Create ans of size n + m.                         │
│                                                      │
│ 3. Traverse num1 from RIGHT → LEFT.                  │
│                                                      │
│ 4. Traverse num2 from RIGHT → LEFT.                  │
│                                                      │
│ 5. Convert characters to digits:                     │
│      digit = ch - '0'                                │
│                                                      │
│ 6. Multiply the two digits.                          │
│                                                      │
│ 7. Put product at i + j + 1.                         │
│                                                      │
│ 8. Put carry at i + j.                               │
│                                                      │
│ 9. Remove leading zeroes.                            │
│                                                      │
│ 10. Convert ans → string.                            │
│                                                      │
├──────────────────────────────────────────────────────┤
│ COMPLEXITY                                           │
│                                                      │
│ Time:  O(n × m)                                      │
│                                                      │
│ Space: O(n + m)                                      │
│                                                      │
├──────────────────────────────────────────────────────┤
│ INTERVIEW ONE-LINER                                  │
│                                                      │
│ "I simulate schoolbook multiplication using an       │
│  array of size n+m, where each digit pair contributes│
│  to index i+j+1 and its carry goes to i+j."          │
│                                                      │
└──────────────────────────────────────────────────────┘


                MULTIPLY STRINGS
                       │
                       ↓
          Cannot convert strings to int
                       │
                       ↓
             Create ans[n + m]
                       │
                       ↓
        Multiply every pair of digits
                       │
                       ↓
        digit1 = num1[i] - '0'
        digit2 = num2[j] - '0'
                       │
                       ↓
             product = digit1 × digit2
                       │
                       ↓
          pos1 = i + j + 1
          pos2 = i + j
                       │
                       ↓
       ans[pos1] += product
                       │
                       ↓
       ans[pos2] += ans[pos1] / 10
                       │
                       ↓
       ans[pos1] %= 10
                       │
                       ↓
          Remove leading zeroes
                       │
                       ↓
             vector → string
             
  */
