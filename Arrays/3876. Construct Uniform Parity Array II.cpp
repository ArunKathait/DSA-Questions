
class Solution {// TC ---> O(N)                               SC ---> O(1)
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        // Find the smallest element in the array.
        // We use the smallest element because:
        // If the smallest element is odd, we can make
        // every other element odd using subtraction.
        int minElement = *min_element(nums1.begin(), nums1.end());

        // If the minimum element is odd,
        // then there is at least one odd number in the array.
        //
        // We can use this odd number as the value to subtract
        // from every even number:
        //
        // Even - Odd = Odd
        //
        // Odd numbers can simply remain unchanged.
        // Therefore, we can make the whole array odd.
        if(minElement % 2 == 1)
        {
            return true;
        }

        // If the minimum element is even, we need to check
        // whether ALL elements are even.
        //
        // If we find even one odd element, then:
        // minimum is even AND there is an odd element.
        //
        // In this case, the required uniform parity cannot be achieved.
        for(int i = 0; i < n; i++)
        {
            if(nums1[i] % 2 == 1)
            {
                return false;
            }
        }

        // If we reach here, there was no odd element.
        // Therefore, every element is even.
        //
        // So the array is already uniform (all even).
        return true;
    }
};

/* 

┌──────────────────────────────────────────┐
│          UNIFORM ARRAY — CHEAT BOX       │
├──────────────────────────────────────────┤
│                                          │
│ PATTERN: PARITY / ODD-EVEN               │
│                                          │
│ Key facts:                               │
│                                          │
│ Even - Odd = Odd                         │
│ Odd  - Odd = Even                        │
│                                          │
│ If ANY odd element exists:               │
│   → Keep odd elements                    │
│   → Subtract odd element from evens      │
│   → Even - Odd = Odd                     │
│   → ALL can become odd                   │
│   → TRUE                                 │
│                                          │
│ If NO odd element exists:                │
│   → ALL elements are even                │
│   → Already uniform                      │
│   → TRUE                                 │
│                                          │
│ CODE IDEA:                               │
│ minElement = min(nums)                   │
│                                          │
│ if(minElement is odd)                    │
│     return true;                         │
│                                          │
│ Check whether any odd exists             │
│ if odd found                             │
│     return false;                        │
│                                          │
│ Otherwise → all even → true              │
│                                          │
│ COMPLEXITY:                              │
│ Time  → O(n)                             │
│ Space → O(1)                             │
│                                          │
│ INTERVIEW KEY:                           │
│ Think about PARITY, not actual values.   │
└──────────────────────────────────────────┘

  */
