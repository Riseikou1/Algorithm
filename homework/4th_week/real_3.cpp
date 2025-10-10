#include <iostream>
#include <vector>
using namespace std;

int CmpBoltNut(int i, int j){
    if (Bolts[i] < Nuts[j]) return -1;
    if (Bolts[i] > Nuts[j]) return +1;
    return 0;
}

int main(){
    int w;
    cin >> w;
    while(w--){
        int n;
        cin >> n;
        vector<int>bolts(n, 0);
        vector<int>nuts(n, 0);
        for(int i = 0; i < n; i++) cin >> bolts[i];
        for(int i = 0; i < n; i++) cin >> nuts[i];
        
 
    }
    return 0;
}