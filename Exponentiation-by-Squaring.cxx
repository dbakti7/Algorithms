/* 
 * Exponentiation-by-Squaring.cxx
 * Implemented by: dbakti7
 * 16 June 2015
 * Reference:
 * https://en.wikipedia.org/wiki/Exponentiation_by_squaring
 * */
#include <cstdio>
long long power(long long a, long long b, long long m) {
	// Returns the result of (a ^ b) modulo m
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	if(b % 2 == 0)
		return power((a * a) % m, b/2, m);
	else
		return (power((a * a) % m, b/2, m) * a) % m;
}
int main()
{
	long long a, b, m;
	printf("Enter 3 numbers, a, b, and m to calculate (a ^ b) mod m:\n");
	while((scanf("%lld %lld %lld", &a, &b, &m)) != EOF) {
		printf("(a ^ b) % m = %lld\n", power(a, b, m));
	}
	return 0;
}
