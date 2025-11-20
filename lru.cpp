#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n;
    vector<int> refs(n);
    for (int &x: refs) cin >> x;
    cin >> f;

    vector<int> fr(f, -1), last(f, -1);

    for (int t = 0; t < n; t++) {
        int p = refs[t];
        bool hit = false;

        for (int i = 0; i < f; i++)
            if (fr[i] == p) hit = true, last[i] = t;

        if (!hit) {
            int pos = -1;
            for (int i = 0; i < f; i++)
                if (fr[i] == -1) { pos = i; break; }
            if (pos == -1)
                pos = min_element(last.begin(), last.end()) - last.begin();
            fr[pos] = p;
            last[pos] = t;
        }
        cout << p << " -> " << (hit ? "HIT" : "FAULT") << "\n";
    }
}
