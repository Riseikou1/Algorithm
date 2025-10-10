#include <iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int P_PR_100_IOD = 1500;

    int t;
    std::cin >> t;
    while(t--){
        long long n;
        std::cin >> n;
        n %= P_PR_100_IOD;

        if(n <= 1) {
            std::cout << n << std::endl;
        }
        else {
            int a = 0;
            int b = 1;
            for(int i = 0; i < n - 1; ++i){
                int temp = b;
                b = (a + b) % 1000;
                a = temp;
            }
            std::cout << b << "\n";
        }
    }
    return 0;
}