#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int w;
    cin >> w;
    while(w--){
        int n;
        int tmp;
        cin >> n;
        unordered_map<int, int> nuts_idx;
        vector<int>bolts(n, 0);

        for(int i = 0; i < n; i++){
            cin >> bolts[i];
        }
        for(int i = 0; i < n; i++){
            cin >> tmp;
            nuts_idx[tmp] = i + 1;
        }
        for(int i = 0; i < n; i++){
            cout << nuts_idx[bolts[i]] << " ";
        }
        cout << "\n";
    }
}
