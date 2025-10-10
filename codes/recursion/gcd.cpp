#include <iostream>
using namespace std;

int iterative_gcd(int a, int b){
    int r;
    do{
        r = a % b;
        a = b;
        b = r;
    }while(r != 0);
    return a;
}

int recursive_gcd(int a, int b){
    if(b == 0) return a;
    else  return recursive_gcd(b, a % b);
}

int main(){ 
    int x;
    int p;
    cout << "Enter the first number : ";
    cin >> x ;
    cout << "Enter the second number : ";
    cin >> p;

    cout << "The answer for the iterative version is : " << iterative_gcd(x, p) << endl;
    cout << "The answer for the recursive version is : " << recursive_gcd(x, p) << endl;

    return 0;
}