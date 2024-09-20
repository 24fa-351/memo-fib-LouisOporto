#include <stdio.h>
#include <stdlib.h>

//Used as memory to store computed fib()
//Props and credit to Noah for the help 
typedef unsigned long long (*fibFunc)(int);
unsigned long long memoNew[100]; // Limit to hundred since unsigned long long limits to 94
fibFunc ptr;

void initCache(fibFunc chosenFunc);
unsigned long long fibWrapper(int num);

// Unmodified fib() methods
unsigned long long fibRecursive(int num);
unsigned long long fibIterative(int num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    int N = atoi(argv[1]);
    char type = argv[2][0];

    // Resolve the -1 indexing by subtracting value
    if(type == 'r') {
        initCache(fibRecursive);
        printf("%llu\n", fibWrapper(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        initCache(fibIterative);
        printf("%llu\n", fibWrapper(N - 1)); // Iterative call
    }

    return 0;
}

// New fib wrappers
void initCache(fibFunc chosenFunc) {
    ptr = chosenFunc;
    memoNew[2] = 1;
}

unsigned long long fibWrapper(int num) {
    //base case
    if(memoNew[num] != 0) return memoNew[num];

    // recusrive case
    memoNew[num] = ptr(num);

    return memoNew[num];
}

unsigned long long fibRecursive(int num) {
    if(num <= 1) return num;
    return fibWrapper(num - 1) + fibWrapper(num - 2);
}

unsigned long long fibIterative(int num) {
    unsigned long long prevNumber = 1;
    unsigned long long prevPrevNumber = 0;
    unsigned long long summation;
    // base case 0 and 1
    if(num <= 1) return num;

    for(int i = 2; i <= num; i++) {
        summation = prevNumber + prevPrevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = summation;
    }

    return summation;
}
