#include <iostream>
#include <cstring>
#include <utility> // For std::swap

// Use the standard C++ library for I/O and utilities
using namespace std;

void generatePermutations(char *str, int begin, int end) {
    // Base Case: If there's only one character left to permute,
    // we have a complete permutation, so print it.
    if (begin == end - 1) {
        cout << str << endl;
        return;
    }

    // Recursive Step
    for (int i = begin; i < end; i++) {
        // 1. SWAP: Choose a character for the 'begin' position.
        swap(str[begin], str[i]);

        // 2. RECURSE: Generate all permutations for the rest of the string.
        //    The key change is here: we always advance 'begin' by just 1.
        generatePermutations(str, begin + 1, end);

        // 3. BACKTRACK: Swap back to restore the original string for
        //    the next iteration of the loop.
        swap(str[begin], str[i]);
    }
}

void permute(char *str) {
    if (str == nullptr) return;
    generatePermutations(str, 0, strlen(str));
}

int main() {
    char str[] = "ABC";
    cout << "Permutations of " << str << " are:" << endl;
    permute(str);
    return 0;
}
