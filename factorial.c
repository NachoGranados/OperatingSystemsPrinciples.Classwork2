#include <stdio.h>
#include <unistd.h>
#include <time.h>

clock_t start;
clock_t end;

float timeConsumed;

// recursive factorial definition
long factorial(int number) {

    printf("Factorial\n");

    // end condition
    if (number == 0 || number == 1) {

        return 1;

    } else {

        // recursive call
        return number * factorial(number - 1);

    }

}

int main() {

    int number = 100000;

    long result;

    start = clock();

    result = factorial(number);   
   
    end = clock();
    
    timeConsumed = (float)(end - start) / CLOCKS_PER_SEC;

    printf("The factorial of the number %d is: %ld \n", number, result);

    printf("Time consumed: %10.6f s\n", timeConsumed);

    // infinite loop
    while (1) {

        sleep(1);

    }

    return 0;

}
