#include <stdio.h>
#include <stdlib.h>

//Used as memory to store computed fib()
unsigned long long* memo;

unsigned long long fibRecursive(int num);
unsigned long long fibRecursiveWrapper(int num);

unsigned long long fibIterative(int num);
unsigned long long fibIterativeWrapper(int num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    int N = atoi(argv[1]);
    char type = argv[2][0];

    // Resolve the -1 indexing by subtracting value
    if(type == 'r') {
        printf("%llu\n", fibRecursiveWrapper(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        printf("%llu\n", fibIterativeWrapper(N - 1)); // Iterative call
    }
    return 0;
}

unsigned long long fibRecursive(int num) {
    if(num <= 1) return num;

    // Check if result is already computed
    if(memo[num] != 0) return memo[num];

    // Compute fib value and store in memo
    memo[num] = fibRecursive(num - 1) + fibRecursive(num - 2);

    return memo[num];
}

unsigned long long fibRecursiveWrapper(int num) {
    // Allocate memory for memoization
    memo = (unsigned long long*)malloc((num + 1) * sizeof(unsigned long long));

    for(int i = 0; i <= num; i++) {
        memo[i] = 0;
    }

    unsigned long long result = fibRecursive(num);

    free(memo);

    return result;
}

unsigned long long fibIterative(int num) {
    unsigned long long prevPrevNumber;
    unsigned long long prevNumber;
    memo[0] = 0, memo[1] = 1;

    for(int iter = 2; iter <= num; iter++) {
        prevPrevNumber = memo[iter - 2];
        prevNumber = memo[iter - 1];
        memo[iter] = prevNumber + prevPrevNumber;
    }
    return memo[num];
}

unsigned long long fibIterativeWrapper(int num) {
    memo = (unsigned long long*)malloc((num + 1) * sizeof(unsigned long long));

    for(int i = 0; i <= num; i++) {
        memo[i] = 0;
    }

    unsigned long long result = fibIterative(num);

    free(memo);

    return result;
}
