/*
 *	Title: 	 First N Primes
 *	Purpose: Find the first N prime numbers as set by a calling argument. 
 *	Author:	 Devan Wiitala
 *	Date:	 12-05-15
 */

/*
 *	Thoughts for optimization:
 *		-Going to hard code the input argument first. Then going to parse from string.
 */

#include <stdio.h>
#include <math.h>

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

int first_n_primes(int n, unsigned long long *array_address)	// generates first n prime numbers and outputs to array address.
{
	int num_primes = 2; //counting 1 and 2 as first prime numbers
	unsigned long long *address;
	address = array_address;
	*address = 1;				//going to be managing arrays with pointers
	*(address + 1) = 2;	
	unsigned long long i = 0;
	
	while (num_primes < n)
	{
		if (isprime(i) == 1) {
			*(address + num_primes) = i;
			num_primes++;
			i++;
		} else {
		i++;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n = 1010000;	// so far, 1010000 is the largest successful n
	unsigned long long array[n];
	unsigned long long *address;
	address = &array[0];
	first_n_primes(n, address);
	int i = 0;
	int display = 0;
	int display_width = 0;
	for (i = 0; i < n; i++)
	{
		if (*(address + i) <= 9999991) {	//inclusion of this loop adds ~0.5s to the execution at 1 million primes, but preserves formatting. 
			display_width = 20;	
		} else {
			display_width = 10; //tab size doubles past the 10,000,000 threshold.
		}
		if ((display % display_width == 0) && (display >= display_width)) {
			printf("\n");
		}
		
		printf("%llu\t", *(address + i));
		display++;
	}
	printf("\n");
	return 0;
}

/*
int main(int argc, char *argv[])
{
	if (argc == 2) {
		//int n = (int) *argv[1];
		printf("The value of n is %d.\n", n);
		int array[n];
		int *address;
		address = &array[0];
		first_n_primes(n, address);
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int display = 0;
			if (display %5 == 1)
				printf("\n");
			printf("%d\t",array[n]);
			display++;
		}
	} else if (argc > 2) {
		printf("ERROR: Too many arguments. Please try again with 1 int as the argument.\n");
		return -1;
	} else {
		printf("ERROR: Argument required. Please try again with 1 int as the argument.\n");
		return -2;
	}

	return 0;
}
*/
