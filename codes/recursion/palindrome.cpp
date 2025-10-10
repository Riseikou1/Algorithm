#include <iostream>
#include <cstring>
using namespace std;

int checkPalindrome(char str[], int first, int last){
    if (last <= first) return 1;
    else if(str[first] != str[last]) return 0;
    else return checkPalindrome(str, first + 1, last - 1);
}

int main(){
    char line[256] = "malayalam";
    printf("%d \n", checkPalindrome(line, 0, strlen(line) - 1));
    return 0;
}