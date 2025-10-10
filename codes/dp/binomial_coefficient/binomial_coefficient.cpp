#include <iostream>
#define MAX 30
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int binCoeff(int n, int k){
    int i, j;
    int B[MAX][MAX];  // Table to store coefficients

    for(i = 0; i <= n; i++){
        for(j = 0; j <= MIN(i, k); j++){
            if (j == 0 || j == i){
                B[i][j] = 1;  // Base cases: C(i,0) = C(i,i) = 1
            }
            else{
                B[i][j] = B[i - 1][j] + B[i - 1][j - 1];  // Pascal relation
            }
        }
    }
    return B[n][k]; 
}

int main(){
    int n, k; 
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter k : ";
    cin >> k;

    cout << "The answer is : " << binCoeff(n, k) << endl;
}
