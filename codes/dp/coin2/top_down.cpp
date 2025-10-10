#include <iostream>
#define MAX_COINS 101
#define MAX_CHANGE 1001
using namespace std;

int countCoinExchange(int coins[], int numDiffCoins, int change) {
    int N[MAX_COINS][MAX_CHANGE] = {0};

    // Base case: 1 way to make change = 0 (choose nothing)
    for (int i = 0; i <= numDiffCoins; i++) {
        N[i][0] = 1;
    }

    for (int i = 1; i <= numDiffCoins; i++) {
        for (int j = 1; j <= change; j++) {
            if (coins[i-1] <= j) {
                // include coin i-1 + exclude coin i-1
                N[i][j] = N[i-1][j] + N[i][j - coins[i-1]];
            } else {
                // can’t use this coin
                N[i][j] = N[i-1][j];
            }
        }
    }

    return N[numDiffCoins][change];
}

int main() {
    int coins[] = {1, 2, 3, 5};
    int numDiffCoins = 4;
    int change = 7;

    cout << "Number of ways: "  // stupid asshole shit.
         << countCoinExchange(coins, numDiffCoins, change) << endl;

    return 0;
}
