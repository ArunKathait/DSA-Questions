
class Solution {// Time  → O(n)                             Space → O(n)
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int n = seq.length();

        // depth = current nesting depth of parentheses
        int depth = 0;

        // ans[i] tells which group the ith parenthesis belongs to
        // 0 -> group A
        // 1 -> group B
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            if(seq[i] == '(')
            {
                // We are entering a new level of nesting
                depth++;

                // If current depth is odd → put '(' in group 1
                // If current depth is even → put '(' in group 0
                //
                // This alternates parentheses between the two groups
                // so that neither group gets unnecessarily deep.
                ans[i] = (depth % 2 == 0) ? 0 : 1;
            }
            else
            {
                // For ')', use the current depth BEFORE decreasing it.
                // This matches the '(' that opened this nesting level.
                ans[i] = (depth % 2 == 0) ? 0 : 1;

                // We are leaving the current nesting level
                depth--;
            }
        }

        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│   MAX DEPTH AFTER SPLIT (LC 1111)   │
├─────────────────────────────────────┤
│ IDEA: Split parentheses based on    │
│       ODD / EVEN depth              │
│                                     │
│ '(' : depth++ first                 │
│ ')' : assign first, depth-- later   │
│                                     │
│ depth is ODD  → Group 1             │
│ depth is EVEN → Group 0             │
│                                     │
│ This balances nesting depth between │
│ the two groups.                     │
│                                     │
│ Example:                            │
│ seq = "((()))"                      │
│ Depth: 1 2 3 3 2 1                  │
│ Group: 1 0 1 1 0 1                  │
│                                     │
│ KEY:                                │
│ '(' → increase depth first          │
│ ')' → use depth first, then --      │
│                                     │
│ TC: O(n)                            │
│ SC: O(n) (answer array)             │
│ Aux Space: O(1)                     │
└─────────────────────────────────────┘

*/
