#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n;
    vector<int> refs(n);
    for (int &x: refs) cin >> x;
    cin >> f;

    vector<int> fr(f, -1);

    for (int t = 0; t < n; t++) {
        int p = refs[t];
        bool hit = false;

        for (int x : fr) if (x == p) hit = true;

        if (!hit) {
            int pos = -1;
            for (int i = 0; i < f; i++)
                if (fr[i] == -1) { pos = i; break; }

            if (pos == -1) {
                int far = -1;
                for (int i = 0; i < f; i++) {
                    int next = 1e9;
                    for (int j = t + 1; j < n; j++)
                        if (refs[j] == fr[i]) { next = j; break; }
                    if (next > far) far = next, pos = i;
                }
            }
            fr[pos] = p;
        }
        cout << p << " -> " << (hit ? "HIT" : "FAULT") << "\n";
    }
}
