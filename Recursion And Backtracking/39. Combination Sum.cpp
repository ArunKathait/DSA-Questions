class Solution {
public:

    // index  -> current candidate we are considering
    // n      -> total number of candidates
    // target -> remaining sum that we need to make
    // temp   -> current combination
    // ans    -> stores all valid combinations
    void solve(int index,
               int n,
               vector<int>& candidates,
               int target,
               vector<int>& temp,
               vector<vector<int>>& ans)
    {
        // If target becomes 0, we have found
        // a valid combination.
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // If we have checked all candidates
        // OR target becomes negative,
        // this path cannot give us an answer.
        if(index >= n || target < 0)
        {
            return;
        }


        // ---------------- TAKE ----------------
        // Choose the current candidate.
        temp.push_back(candidates[index]);

        // We pass 'index' again, NOT index + 1.
        //
        // Why?
        // Because in Combination Sum,
        // we are allowed to use the same number
        // multiple times.
        //
        // Example:
        // candidates = [2,3,6,7]
        // We can have [2,2,3].
        solve(index,
              n,
              candidates,
              target - candidates[index],
              temp,
              ans);

        // Undo the choice.
        // This is called BACKTRACKING.
        temp.pop_back();


        // ---------------- NOT TAKE ----------------
        // Don't choose the current candidate.
        //
        // Therefore, move to the next candidate.
        solve(index + 1,
              n,
              candidates,
              target,
              temp,
              ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target)
    {
        int n = candidates.size();

        vector<vector<int>> ans;

        vector<int> temp;

        // Start from the first candidate (index 0).
        solve(0,
              n,
              candidates,
              target,
              temp,
              ans);

        return ans;
    }
};

/* NOTE:  

                 candidate[index]
                       |
                ┌──────┴──────┐
                |             |
              TAKE          NOT TAKE
                |             |
          same index       index + 1
                |             |
          target - value    same target

*/
