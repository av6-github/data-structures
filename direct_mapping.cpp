#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, lines;
    cin >> n;
    vector<int> refs(n);
    for (int &x: refs) cin >> x;
    cin >> lines;

    vector<int> cache(lines, -1);

    for (int b : refs) {
        int line = b % lines;
        bool hit = (cache[line] == b);
        if (!hit) cache[line] = b;
        cout << b << " -> " << (hit ? "HIT " : "MISS ")
             << " line " << line << "\n";
    }
}
