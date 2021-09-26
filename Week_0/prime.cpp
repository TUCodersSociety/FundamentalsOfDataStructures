// O(n)
// example 7919

#include <iostream>

using namespace std;

bool isPrime(int num) {
    for (int x = 2; x < num; x++) {
        if (num % x== 0) {
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
