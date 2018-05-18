#include <iostream>
#include <math.h>

using namespace std;

/*
Fringe cases:
1) Numbers less than the prime formula (2, 3)
    What if there are no primes less than the square root of the candidate?
    Do we just assume that 2 and 3 are prime?
    
*/
void is_prime(int prime_candidate)
{
    double candidate_sqrt;
    int divisor = 2;

    // 1) Check that the number is greater than 1 (no prime number is less than 2).
    if(prime_candidate <= 1)
    {
        cout << prime_candidate << " is not prime.\n";
        return;
    }

    // 2) Check if number is equal to 2, 3, 5, or 7. 
    if(prime_candidate == 2 || prime_candidate == 3 || prime_candidate == 5 || prime_candidate == 7)
    {
        cout << prime_candidate << " is prime.\n";
        return;
    }
    // 3) Check the number against all primes less than its square root.
    else
    {
        // 3.1) Take candidate's square root.
        candidate_sqrt = sqrt(prime_candidate);

        // 3.2) Check the modulus of the square root and the divisor.
        while(divisor <= candidate_sqrt)
        {
            if(prime_candidate % divisor == 0)
            {
                cout << prime_candidate << " is not prime.\n";
                return;
            }

            divisor++;
            if(prime_candidate % divisor == 0)
            {
                cout << prime_candidate << " is not prime.\n";
                return;
            }

            for(int i = 1; divisor <= candidate_sqrt; i++)
            {
                divisor = (6 * i) - 1;
                if(prime_candidate % divisor == 0)
                {
                    cout << prime_candidate << " is not prime.\n";
                    return;
                }

                if(divisor > candidate_sqrt)
                {
                    cout << prime_candidate << " is prime.\n";
                    return;
                }

                divisor += 2;
                if(prime_candidate % divisor == 0)
                {
                    cout << prime_candidate << " is not prime.\n";
                    return;
                }
            }
        }
    }

    // 4) interpret the result.
    cout << prime_candidate << " is prime.\n";
    return;
}

int main()
{
    int prime_candidate;

    cout << "Prime Checker\n\n";
    cout << "Please input the integer to be checked: ";

    cin >> prime_candidate;
    
    is_prime(prime_candidate);

    return 0;
}