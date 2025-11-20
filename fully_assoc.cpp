#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, lines;
    cin >> n;
    vector<int> refs(n);
    for (auto &x: refs) cin >> x;
    cin >> lines;

    vector<int> cache(lines, -1);
    int p = 0;

    for (int b : refs) {
        bool hit = find(cache.begin(), cache.end(), b) != cache.end();
        if (!hit) { cache[p] = b; p = (p + 1) % lines; }
        cout << b << " -> " << (hit ? "HIT " : "MISS ") << "\n";
    }
}
