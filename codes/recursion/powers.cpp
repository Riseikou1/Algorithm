#include <iostream>
using namespace std;

double power(double x, int n){
    if(n == 0) {
        return 1.0;
    }
    else {
        return x * power(x, n - 1);
    }
}

int main(){ 
    double x;
    int p;
    cout << "Enter number : ";
    cin >> x ;
    cout << "Enter power : ";
    cin >> p;

    cout << "The answer is : " << power(x ,p) << endl;

    return 0;
}