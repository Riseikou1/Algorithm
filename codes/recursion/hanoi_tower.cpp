#include <iostream>
void move(int from, int to) {
    printf("%d --> %d\n", from, to);
}
void Hanoi(int n, int from, int using_peg, int to) {
    if (n == 1) {
        move(from, to);
        return;
    }
    // Move n-1 disks from 'from' to 'using_peg', using 'to' as the auxiliary.
    Hanoi(n - 1, from, to, using_peg);
    
    // Move the largest disk from 'from' to 'to'.
    move(from, to);
    
    Hanoi(n - 1, using_peg, from, to);
}
int main() {
    int numDisks = 3; // Using 3 for a clearer example
    printf("Number of disks to move: %d\n", numDisks);
    Hanoi(numDisks, 1, 2, 3);
    return 0;
}
