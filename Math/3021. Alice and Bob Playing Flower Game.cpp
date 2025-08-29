
class Solution {// Time Complexity ---> O(1)                         Space Complexity ---> O(1)
public:
    long long flowerGame(int n, int m) {
        // Idea:
        // Alice chooses a number i (1 <= i <= n)
        // Bob chooses a number j (1 <= j <= m)
        // Alice wins if (i + j) is ODD.
        //
        // Case when sum is odd:
        // -> One must be even, and the other must be odd.
        //
        // So total winning pairs = (#odd_i * #even_j) + (#even_i * #odd_j)

        // Count of odd numbers between 1..n = (n + 1) / 2
        // Example: n=5 → odds=3 (1,3,5); evens=2 (2,4)
        long long oddN = (n + 1) / 2;

        // Count of even numbers between 1..n = n/2
        long long evenN = n / 2;

        // Similarly, count odds in 1..m
        long long oddM = (m + 1) / 2;

        // And evens in 1..m
        long long evenM = m / 2;

        // Winning pairs = (oddN * evenM) + (evenN * oddM)
        // Because:
        //   i odd + j even  -> odd sum ✅
        //   i even + j odd  -> odd sum ✅
        return 1LL * (oddN * evenM + evenN * oddM);
    }
};
