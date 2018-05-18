#include <iostream>
#include <math.h>

using namespace std;

void is_prime(int prime_candidate)
{
    bool prime_status;
    double candidate_sqrt;
    int divisor = 5;

    // 1) Check is the candidate is divisble by two and three.
    if(prime_candidate % 2 == 0 || prime_candidate % 3 == 0)
    {
        cout << prime_candidate << " is not prime.\n";
        return;
    }

    // 2) Check if the candidate is divisble by all other primes less than its square root.
    else{
        // 2.1) Take the candidate's square root.
        candidate_sqrt = sqrt(prime_candidate);

        // 2.2) Calculate the divisor.

        // 2.3) While divisor <= candidate_sqrt, modulus the prime_candidate against the increasing primes (divisor).

        // 2.4) interpret the result.
        cout << prime_candidate << " is prime.\n";
        return;
    }
}

int main()
{
    int prime_candidate;

    cout << "Prime Checker\n\n";
    cout << "Please input the integer to be checked: ";

    cin >> prime_candidate;
    
    is_prime(prime_candidate);

    system("pause");
    return 0;
}