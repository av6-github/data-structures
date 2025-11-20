#include <bits/stdc++.h>
using namespace std;

// convert unsigned number to binary of n bits
string bin(unsigned long long x, int n) {
    string s = "";
    for (int i = n-1; i >= 0; --i)
        s += ((x >> i) & 1) ? '1' : '0';
    return s;
}

// arithmetic right shift on (A,Q,Q1)
void ars(unsigned long long &A, unsigned long long &Q, int &Q1, int n) {
    int newQ1 = Q & 1;                 // old Q0 becomes new Q1
    Q >>= 1;                           // shift Q right
    Q |= (A & 1) << (n-1);             // bring A0 into Q[n-1]
    A >>= 1;                           // shift A right
    Q1 = newQ1;
}

int main() {
    unsigned long long M, Q;
    cout << "Enter M and Q: ";
    cin >> M >> Q;

    // compute required bits (unsigned)
    int bits = max(1, (int)max( log2(max(M, Q)+1), 1.0 ));

    unsigned long long A = 0;
    int Q1 = 0;

    cout << "\nInitial State:\n";
    cout << "A=" << bin(A, bits)
         << "  Q=" << bin(Q, bits)
         << "  Q-1=" << Q1 << "\n\n";

    for (int step = 1; step <= bits; ++step) {
        int Q0 = Q & 1;

        cout << "Step " << step << ":\n";

        if (Q0 == 0 && Q1 == 1) {
            A += M;
            cout << "A = A + M\n";
        }
        else if (Q0 == 1 && Q1 == 0) {
            A -= M;
            cout << "A = A - M\n";
        }
        else {
            cout << "No operation\n";
        }

        cout << "Before shift:  A=" << bin(A,bits)
             << "  Q=" << bin(Q,bits)
             << "  Q-1=" << Q1 << "\n";

        ars(A, Q, Q1, bits);

        cout << "After shift:   A=" << bin(A,bits)
             << "  Q=" << bin(Q,bits)
             << "  Q-1=" << Q1 << "\n\n";
    }

    unsigned long long product = (A << bits) | Q;

    cout << "Final product = " << product << "\n";
}
