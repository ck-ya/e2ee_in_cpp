#include <iostream>
#include <cmath>

using namespace std;

//lets try making encryption!!! yay

int makeEncKey(int phi) {
    for (int e = 3; e < phi; e += 2) {   // try odd num starting from 3
        int a = e, b = phi;
        // gcd loop
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        if (a == 1) {
            return e;  // coprime key
        }
    }
    return -1; // no key found
}

int makeDecKey(int e,int phi) {
    int d = 2; // 1 dosent make sense in this math stuff so use 2

    while ((e*d)%phi != 1) {
        d++;
    }
    return d;
}

int modExp(int base, int exp, int mod) {
    long long result = 1;       //using long coz int cant handel the resultant value
    long long b = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }

    return (int)result;
}


int main() {
    // let p and q be two random co-prime numbers for,
    int p = 809; //first number
    int q = 911; //second number
    int n = p*q; //n is product of p and q, we will use this value as modulo
    int phi = (p-1)*(q-1); //this is the greatest possible value

    int e = makeEncKey(phi); // get the public key with function
    int d = makeDecKey(e, phi); //get private key

    int msg = 90;

    int enc = modExp(msg, e, n);// this will give encrypted value witht the public key

    int dec = modExp(enc, d, n);//this will give decrypted value with the private key

    cout << dec << endl;

}