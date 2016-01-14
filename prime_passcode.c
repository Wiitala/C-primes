/*
 *	Title:	 Prime Passcode
 *	Purpose: Generate two large primes, multiply them together, output result to text file
 *	Author:	 Devan Wiitala
 *	Date:	 12-25-15
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int isprime(unsigned long long num)
{
	unsigned long long i = 0;
	for (i = 2; i < num; (i < 3) ? i++ : (i += 2))
	{
		if ((num % i == 0) && (i < num)) {
			return 0;
		} else if (i >= ceil(sqrt((double) num))) {
			return 1;
		}
	}
	return -1;
}

unsigned long long *n_primes_after_m(int n, unsigned long long m, unsigned long long *address)	//returns address of array of largest n primes
{
	//unsigned long long *array = malloc(n * sizeof(unsigned long long));	
	unsigned long long i = 0;
	int num_primes = 0;

	for (i = m; num_primes < n; (i % 2 == 0) ? i++ : (i += 2))
	{
		if (isprime(i) == 1) {
			*(address + num_primes) = i;
			num_primes++;
		}
	}
	return address;
}

unsigned long long prime_passcode(int n, unsigned long long *address) // takes array address and multiplies them together into a pass. returns value
{
	int i = 0;
	unsigned long long passcode = 1;

	for (i = 0; i < n; i++)
	{
		passcode *= *(address + i);
	}
	return passcode;
}

int main(int argc, char *argv[])
{
	//// I/O ////
	FILE *prime_passcode_file = fopen("passcode.txt", "w"); // opens passcode.txt in "write" mode (seems like an ancient function)
	if (!prime_passcode_file)
		return 1;
	
	//// vars ////
	int num_primes = 3;	// errors at 4 digits past 1000000
	unsigned long long lower_bound = 1000000;
	int i = 0;
	unsigned long long *prime_array = malloc(num_primes * sizeof(unsigned long long));
	unsigned long long passcode = 0;
	
	//// execution ////
	n_primes_after_m(num_primes, lower_bound, prime_array);
	passcode = prime_passcode(num_primes, prime_array);
	printf("\nThe passcode is: %llu, which is the product of the %d prime numbers: ", passcode, num_primes);
	for (i = 0; i < num_primes - 1; i++)
		printf("%llu, ", *(prime_array + i));
	printf("and %llu, respectively.\n", *(prime_array + i));
	fprintf(prime_passcode_file, "%llu", passcode);
	for (i = 0; i < num_primes; i++)
		fprintf(prime_passcode_file, "\n%llu", *(prime_array + i));
	fprintf(prime_passcode_file, "\nMax value: %llu", ULLONG_MAX);
	fclose(prime_passcode_file);
	free(prime_array);

	return 0;
}
