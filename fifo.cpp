#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n;
    vector<int> refs(n);
    for (int &x: refs) cin >> x;
    cin >> f;

    vector<int> fr(f, -1);
    int p = 0;

    for (int page : refs) {
        bool hit = find(fr.begin(), fr.end(), page) != fr.end();
        if (!hit) { fr[p] = page; p = (p + 1) % f; }
        cout << page << " -> " << (hit ? "HIT" : "FAULT") << "\n";
    }
}
