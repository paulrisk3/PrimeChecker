import math

def is_prime(prime_candidate):

	#Primes are greater than 1
	if prime_candidate <= 1:
		print(prime_candidate, "is not prime.\n")
		return
		
	#2 and 3 are prime
	if prime_candidate == 2 or prime_candidate == 3:
		print(prime_candidate, "is prime!\n")
		return
		
	#Primes are not divisibile by 2 or 3
	if prime_candidate % 2 == 0:
		print(prime_candidate, "is not prime.\n")
		return
	if prime_candidate % 3 == 0:
		print(prime_candidate, "is not prime.\n")
		return
		
	#While divisor is less than or equal to sqrt of prime_candidate, divide prime_candidate by lesser primes
	candidate_sqrt = math.sqrt(prime_candidate)
	i = 1
	divisor = 5
	while divisor <= candidate_sqrt:
		if prime_candidate % divisor == 0:
			print(prime_candidate, "is not prime.\n")
			return
		divisor += 2
		if divisor > candidate_sqrt:
			print(prime_candidate, "is prime!\n")
			return
		if prime_candidate % divisor == 0:
			print(prime_candidate, "is not prime.\n")
			return
		i += 1
		divisor = (6 * i) - 1
	print(prime_candidate, "is prime!\n")
	return
	
while True:
	try:
		prime_candidate = int(input("Enter integer to check: "))
		is_prime(prime_candidate)
	except ValueError:
		print("Value must be an integer.\n")