/*
 * PrimalityTesting.cpp
 * Written by: dbakti7
 * 14 June 2015
 * */
 
#include <cstdio>

bool isPrime(int n);

int main()
{
	int n;
	printf("Enter a number (Enter a negative number to end the program):\n");
	while(true) {
		scanf("%d", &n);
		if(n < 0)
			break;
		if(isPrime(n))
			printf("%d is a prime number.\n", n);
		else
			printf("%d is not a prime number.\n", n);
	}
	return 0;
}

bool isPrime(int n) {
	/*
	 * This function returns true if n is a prime number, 
	 * false otherwise.
	 * */
	
	if(n <= 1)
		return false;
	
	if(n <= 3)
		return true;
		
	// Check divisibility by 2 or 3
	if((n % 2 == 0) || (n % 3 == 0))
		return false;
	
	// Check divisibility by prime bigger than 3
	// Every prime number bigger than 3 can be written as 6k-1 or 6k+1,
	// for integer k >= 1.
	int i = 5;
	while(i*i <= n) { // prime divisor is not bigger than square root of n
		if((n % i == 0) || (n % (i + 2) == 0))
			return false;
		i += 6;
	}
	return true;
}
