// C++ program To count the number of even substrings in a string of digits.

#include <iostream>
#include <string>
using namespace std;

int countEvenSubstrings(const string& digits) {
    int count = 0;

    // Traverse each character in the string
    for (size_t i = 0; i < digits.size(); ++i) {
        int digit = digits[i] - '0'; // Convert char to int

        // Check if the digit is even
        if (digit % 2 == 0) {
            // Add (i + 1) to the count because all substrings ending at this position are even
            count += (i + 1);
        }
    }

    return count;
}

int main() {
    string digits;
    cout << "Enter a string of digits: ";
    cin >> digits;

    int result = countEvenSubstrings(digits);
    cout << "Number of even substrings: " << result << endl;

    return 0;
}
