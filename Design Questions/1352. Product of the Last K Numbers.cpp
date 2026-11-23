***********************************************APPROACH 1st(BRUTE FORCE)***********************************************

class ProductOfNumbers {
public:
    // Stores all the numbers added to the stream
    vector<int> nums;

    // Constructor: Initializes an empty stream
    ProductOfNumbers() {

    }

    // Adds a new number to the stream
    void add(int num) {
        nums.push_back(num);
    }

    // Returns the product of the last k numbers
    int getProduct(int k) {

        // Get the total number of elements in the stream
        int n = nums.size();

        // Initialize product to 1 because 1 is the
        // multiplicative identity
        int product = 1;

        // Start from index (n-k) because we need
        // only the last k elements.
        //
        // Continue until the last index (n-1).
        for(int i = n-k; i < n; i++)
        {
            // Multiply each of the last k elements
            product *= nums[i];
        }

        // Return the product of the last k numbers
        return product;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Product of the Last K Numbers                │
├──────────────────────────────────────────────┤
│ Approach: Brute Force + Array                │
│                                              │
│ Key Idea:                                    │
│ Store all stream elements in a vector and    │
│ multiply the last k elements when queried.   │
│                                              │
│ 1. Store incoming numbers using push_back(). │
│ 2. Calculate starting index = n - k.         │
│ 3. Traverse from index n-k to n-1.           │
│ 4. Multiply all elements in the range.       │
│ 5. Return the calculated product.            │
│                                              │
│ Time Complexity:  add()       O(1)           │
│                   getProduct() O(k)          │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(1)                       │
└──────────────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(OPTIMAL)***************************************************

class ProductOfNumbers {
public:
    // Stores prefix products instead of storing original numbers
    vector<int> nums;

    // Tracks the number of elements since the last zero
    int n = 0;

    // Constructor: Initializes an empty prefix product array
    ProductOfNumbers() {

    }

    // Adds a new number to the stream
    void add(int num) {

        // If the incoming number is zero,
        // all products containing this zero will be zero.
        // Therefore, reset the prefix product array.
        if(num == 0)
        {
            nums.clear();
            n = 0;
        }
        else
        {
            // If this is the first element after initialization
            // or the last zero, store the number directly.
            if(nums.empty())
            {
                nums.push_back(num);
            }
            else
            {
                // Calculate the prefix product:
                // Current prefix product = Previous prefix product * num
                nums.push_back(num * nums[n - 1]);
            }

            // Increase the count of elements since the last zero
            n++;
        }
    }

    // Returns the product of the last k numbers
    int getProduct(int k) {

        // Get the current size of the prefix product array
        int n = nums.size();

        // If k is greater than the number of elements
        // since the last zero, the requested range contains zero.
        // Therefore, the product is zero.
        if(k > n)
        {
            return 0;
        }

        // If k equals n, we need the product of all elements
        // in the current prefix array.
        else if(k == n)
        {
            return nums[n - 1];
        }
        else
        {
            // Prefix product formula:
            //
            // Product of last k elements =
            // Total prefix product / Prefix product before last k elements
            //
            // nums[n-1]     = Product of all current elements
            // nums[n-k-1]   = Product before the last k elements

            return nums[n - 1] / nums[n - k - 1];
        }
    }
};

/*

┌──────────────────────────────────────────────┐
│ Product of the Last K Numbers                │
├──────────────────────────────────────────────┤
│ Approach: Prefix Product + Zero Handling     │
│                                              │
│ Key Idea:                                    │
│ Maintain cumulative products to retrieve     │
│ the product of the last k elements using     │
│ division.                                    │
│                                              │
│ 1. Store cumulative products in nums.        │
│ 2. If zero appears, clear nums and reset n.  │
│ 3. If k > n, return 0 (range contains zero). │
│ 4. If k == n, return nums[n-1].              │
│ 5. Otherwise, calculate:                     │
│    nums[n-1] / nums[n-k-1].                  │
│                                              │
│ Time Complexity:  add()        O(1)          │
│                   getProduct() O(1)          │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(1)                       │
└──────────────────────────────────────────────┘

*/
