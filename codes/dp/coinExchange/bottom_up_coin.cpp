#include <iostream>
#include <vector>
using namespace std;

void coinExchange(int coins[], int numDiffCoins, int change,
                  vector<int>& coinsUsed, vector<int>& lastCoin) {
    for (int cents = 1; cents <= change; cents++) {
        int minCoins = cents;   // worst case: all 1s
        int newCoin = 1;

        for (int j = 0; j < numDiffCoins; j++) {
            if (coins[j] <= cents && coinsUsed[cents - coins[j]] + 1 < minCoins) {
                minCoins = coinsUsed[cents - coins[j]] + 1;
                newCoin = coins[j];
            }
        }
        coinsUsed[cents] = minCoins;
        lastCoin[cents] = newCoin;
    }
}

void reconstruct(int change, const vector<int>& lastCoin) {
    if (change == 0) return;
    reconstruct(change - lastCoin[change], lastCoin);
    cout << lastCoin[change] << " ";
}

int main() {
    int coins[] = {1, 5, 10, 21, 25};
    int n = sizeof(coins) / sizeof(coins[0]);

    int change;
    cout << "Enter change amount: ";
    cin >> change;

    vector<int> coinsUsed(change + 1, 0);
    vector<int> lastCoin(change + 1, 0);

    coinExchange(coins, n, change, coinsUsed, lastCoin);

    cout << "Minimum coins needed: " << coinsUsed[change] << "\n";
    cout << "Coins used: ";
    reconstruct(change, lastCoin);
    cout << "\n";
}
