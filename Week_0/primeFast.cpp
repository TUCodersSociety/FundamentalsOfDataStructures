// O(sqrt(n))
// example 7919

#include <iostream>
using namespace std;

bool isPrime(int num) {
    /*
    it only needs to go up to the square root of num because
    if num is divisible by a number greater than its square root, 
    then it is divisible by something smaller than it 

    e.g. 
    while 33 is divisible by 11(which is greater than its square root),
    the counterpart to 11 is 3 (3*11 = 22), 33 would've been eliminated as 
    prime number by 3

    while 51 is divisible by 17(which is greater than its square root), 
    the counterpart to 17 is 3 (3*17 = 51), 51 would've been eliminated as 
    prime number by 3 too
    */

    for (int x = 2; x*x <= num; x++) {
        if (num % x == 0) {
            return false;
        }
        cout << x << endl;
    }
    
    return true;
}

int main (void) {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = isPrime(n);
    if (result) {
        cout << n << " is a prime number";
    }
    else {
        cout << n << " is not a prime number";
    }
}
