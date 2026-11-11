
class Solution {// TIME COMPLEXITY:  O(1)                       SPACE COMPLEXITY: O(1)
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        // CASE 1:
        // If buying one item of type 1 and one item of type 2 separately
        // is cheaper than or equal to buying one combined item,
        // then there is no benefit in purchasing the combined item.
        if(cost1 + cost2 <= costBoth)
        {
            // Fulfill need1 using cost1 and need2 using cost2.
            // Use 1LL to prevent integer overflow during multiplication.
            return (1LL * cost1 * need1) + (1LL * cost2 * need2);
        }

        // CASE 2:
        // Buying both items together is cheaper.
        // Purchase the combined item for the maximum possible common need.
        // We can fulfill both requirements simultaneously.
        int both = min(need1, need2);

        // Calculate the cost of purchasing 'both' combined items.
        long long total = 1LL * costBoth * both;

        // Reduce both requirements because they are already fulfilled
        // by purchasing the combined items.
        need1 -= both;
        need2 -= both;

        // If some requirement of type 1 is still remaining,
        // fulfill it using the cheaper option:
        // Either buy type 1 separately or buy another combined item.
        if(need1 > 0)
        {
            total += 1LL * need1 * min(cost1, costBoth);
        }

        // Otherwise, if some requirement of type 2 is remaining,
        // fulfill it using the cheaper option:
        // Either buy type 2 separately or buy another combined item.
        else if(need2 > 0)
        {
            total += 1LL * need2 * min(cost2, costBoth);
        }

        // Return the minimum total cost required
        // to fulfill both requirements.
        return total;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│              MINIMUM COST (GREEDY)                   │
├──────────────────────────────────────────────────────┤
│ APPROACH: Greedy                                     │
│                                                      │
│ KEY IDEA:                                            │
│ • Compare cost1 + cost2 with costBoth.               │
│ • If buying separately is cheaper, fulfill both      │
│   requirements individually.                         │
│ • Otherwise, buy combined items for min(need1,need2).│
│ • Reduce both requirements accordingly.              │
│ • Fulfill the remaining requirement using the        │
│   cheaper option between individual and combined.    │
│ • Return the minimum total cost.                     │
│                                                      │
│ TIME COMPLEXITY:  O(1)                               │
│ SPACE COMPLEXITY: O(1)                               │
│ TOTAL SPACE:      O(1)                               │
└──────────────────────────────────────────────────────┘

*/
