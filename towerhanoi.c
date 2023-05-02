#include <stdio.h>

 

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from peg %c to peg %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

 

int main() {
    int n = 3; // number of disks
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
