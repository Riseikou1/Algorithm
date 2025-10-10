#include <iostream>
using namespace std;

double power(double x, int n){
    double y;
    if (n == 0){
        return 1.0;
    }
    else if (n % 2 == 1){
        y = power(x, (n - 1)/2);
        return y * y * x;

    }else{
        y = power(x, n/2);
        return y * y;
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