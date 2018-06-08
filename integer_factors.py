import math

def lowest_prime_factor(prime_candidate):
	#Primes are greater than 1
	if prime_candidate <= 1:
		return False
		
	#2 and 3 are prime
	if prime_candidate == 2 or prime_candidate == 3:
		return prime_candidate
		
	#Primes are not divisibile by 2 or 3
	if prime_candidate % 2 == 0:
		return 2
	if prime_candidate % 3 == 0:
		return 3
		
	#While divisor is less than or equal to sqrt of prime_candidate, divide prime_candidate by lesser primes
	candidate_sqrt = math.sqrt(prime_candidate)
	i = 1
	divisor = 5
	while divisor <= candidate_sqrt:
		if prime_candidate % divisor == 0:
			return divisor
		divisor += 2
		if divisor > candidate_sqrt:
			return prime_candidate
		if prime_candidate % divisor == 0:
			return divisor
		i += 1
		
		#formula approximates the next prime in the sequence. Many of the numbers it finds are not prime.
		#grows less efficient as i increases.
		divisor = (6 * i) - 1
	return prime_candidate
	
def factor_finder(int_factor):
	prime = int(lowest_prime_factor(int_factor))
	
	if prime == int_factor:
		prime_factors.append(prime)
		print("Prime factors:", prime_factors, "\n")
	elif prime != False:
		prime_factors.append(prime)
		factor_finder(int_factor/prime)

while True:
	try:
		int_factor = int(input("Enter integer to check: "))
		prime_factors = []
		factor_finder(int_factor)
	except ValueError:
		print("Value must be an integer.\n")