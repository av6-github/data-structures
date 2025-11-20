#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, lines, ways;
    cin >> n;
    vector<int> refs(n);
    for (int &x: refs) cin >> x;
    cin >> lines >> ways;

    int sets = lines / ways;
    vector<vector<int>> cache(sets, vector<int>(ways, -1));
    vector<int> ptr(sets, 0);

    for (int b : refs) {
        int s = b % sets;
        bool hit = find(cache[s].begin(), cache[s].end(), b) != cache[s].end();
        if (!hit) {
            cache[s][ptr[s]] = b;
            ptr[s] = (ptr[s] + 1) % ways;
        }
        cout << b << " -> " << (hit ? "HIT " : "MISS ") 
             << "set " << s << "\n";
    }
}
