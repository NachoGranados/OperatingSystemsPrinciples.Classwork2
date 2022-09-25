import sys
import time

# set recursion limit
sys.setrecursionlimit(10**5)

# recursive factorial definition
def factorial(number):

    print("Factorial")

    # end condition
    if (number == 0 or number == 1):

        return 1

    else: 

        # recursive call
        return number * factorial(number - 1)  


number = 10000

start = time.time()

result = factorial(number)

end = time.time()

timeConsumed = str( (end - start) )

print("The factorial of the number:", number, "is:", result)

print("Time consumed:", timeConsumed, "s")

# infinite loop
while True:

    time.sleep(1)
