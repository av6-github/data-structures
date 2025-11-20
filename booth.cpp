#include <bits/stdc++.h>
using namespace std;

// print signed binary with fixed bits
string bin(long long x, int n) {
    string s = "";
    for (int i = n - 1; i >= 0; --i)
        s += ((x >> i) & 1) ? '1' : '0';
    return s;
}

// arithmetic right shift on (A,Q,Q1)
void ars(long long &A, long long &Q, int &Q1, int n) {
    int newQ1 = Q & 1;
    Q >>= 1;
    Q |= (A & 1) << (n - 1);
    A >>= 1;
    Q1 = newQ1;
}

int main() {
    long long M, Q;
    cout << "Enter M and Q: ";
    cin >> M >> Q;

    int n = 8;                 // 8-bit operations for easy demo
    long long A = 0;           // accumulator
    int Q1 = 0;                // Q-1

    cout << "Initial:\nA=" << bin(A,n)
         << "  Q=" << bin(Q,n) << "  Q-1=" << Q1 << "\n\n";

    for (int step = 1; step <= n; step++) {
        int Q0 = Q & 1;

        cout << "Step " << step << ":\n";

        if (Q0 == 0 && Q1 == 1) { A = A + M; cout << "A = A + M\n"; }
        else if (Q0 == 1 && Q1 == 0) { A = A - M; cout << "A = A - M\n"; }
        else cout << "No operation\n";

        cout << "Before shift: A=" << bin(A,n)
             << "  Q=" << bin(Q,n) << "  Q-1=" << Q1 << "\n";

        ars(A, Q, Q1, n);

        cout << "After shift : A=" << bin(A,n)
             << "  Q=" << bin(Q,n) << "  Q-1=" << Q1 << "\n\n";
    }

    long long product = (A << n) | (Q & ((1<<n)-1));

    cout << "Final product = " << product << "\n";
}
