
class Solution {// Time: O(n log n)                                  Space: O(n)
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        // Initially every day is considered a dry day.
        // Rainy days will become -1.
        // Used dry days will contain the lake number.
        vector<int> ans(n, 1);

        // lake -> last day on which this lake received rain
        unordered_map<int, int> ump;

        // Stores indices of unused dry days in sorted order.
        set<int> st;

        for (int i = 0; i < n; i++) 
        {
            int lake = rains[i];

            // ------------------------------------------------
            // Case 1: Today is a dry day
            // ------------------------------------------------
            if (lake == 0) 
            {
                // Save this day so that we can use it later
                // to dry a lake.
                st.insert(i);
            }

            // ------------------------------------------------
            // Case 2: Today it rains on a lake
            // ------------------------------------------------
            else 
            {
                // We cannot dry a lake on a rainy day.
                ans[i] = -1;

                // If this lake has rained before,
                // it is currently full.
                if (ump.count(lake)) 
                {
                    // Previous day when this lake received rain.
                    int previousDay = ump[lake];

                    // Find the earliest unused dry day
                    // strictly AFTER previousDay.
                    auto it = st.upper_bound(previousDay);

                    // No suitable dry day exists.
                    // Therefore, the lake will flood.
                    if (it == st.end()) 
                    {
                        return {};
                    }

                    // Select this dry day.
                    int dryDay = *it;

                    // Dry this particular lake on dryDay.
                    ans[dryDay] = lake;

                    // This dry day is now used.
                    st.erase(it);
                }

                // Update the latest rainy day of this lake.
                ump[lake] = i;
            }
        }

        return ans;
    }
};

/*

╔════════════════════════════════════════════════════╗
║              🌧️ AVOID FLOOD — CHEAT BOX           ║
╠════════════════════════════════════════════════════╣
║ 🎯 CORE IDEA                                       ║
║ Track the last rain day of every lake.             ║
║ For a repeated lake, find the earliest unused      ║
║ dry day AFTER its previous rain.                   ║
║                                                    ║
║ 🧠 DATA STRUCTURES                                 ║
║ unordered_map → lake → last rainy day              ║
║ set           → unused dry-day indices             ║
║                                                    ║
║ 🔑 KEY OPERATION                                   ║
║ it = st.upper_bound(previousRainDay);              ║
║                                                    ║
║ Why upper_bound?                                   ║
║ → Need dryDay > previousRainDay                    ║
║ → Choose earliest possible dry day                 ║
║                                                    ║
║ ⚙️ ALGORITHM                                      ║
║ 1. rains[i] == 0 → insert i into set               ║
║ 2. Rain on lake → ans[i] = -1                      ║
║ 3. If lake already appeared:                       ║
║    → find upper_bound(lastRainDay)                 ║
║    → if none → return {} (flood)                   ║
║    → ans[dryDay] = lake                            ║
║    → erase dryDay                                  ║
║ 4. Update ump[lake] = i                            ║
║                                                    ║
║ ⏱️ TIME                                            ║
║ O(n log n)                                         ║
║                                                    ║
║ 💾 SPACE                                           ║
║ O(n)                                               ║
╚════════════════════════════════════════════════════╝

*/
