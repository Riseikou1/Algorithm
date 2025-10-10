#include <iostream>
using namespace std;

void countUp(int nCount) {
    if (nCount > 0){
        countUp(nCount - 1);
    }
    printf("%d \n", nCount);
}
void countDown(int nCount) {
    printf("%d \n", nCount);
    if (nCount > 0){
        countDown(nCount - 1);
    }
}

int main(){
    cout << "counting up " << endl;
    countUp(4);
    cout << "counting down" << endl;
    countDown(4);
    return 0;
}
// this shit is simple yet soo useful for understanding
// how recursion bubbles up.
// when place ur shit etc.