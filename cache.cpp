#include <bits/stdc++.h>
using namespace std;

void show(const vector<int>& c) {
    for (int x : c) cout << (x == -1 ? "-" : to_string(x)) << " ";
    cout << "\n";
}

void directMap(vector<int> refs, int lines) {
    vector<int> cache(lines, -1);
    cout << "\n--- Direct Mapping ---\n";
    for (int b : refs) {
        int i = b % lines;
        bool hit = (cache[i] == b);
        if (!hit) cache[i] = b;
        cout << b << ": " << (hit?"HIT ":"MISS") << " -> ";
        show(cache);
    }
}

void fullyAssoc(vector<int> refs, int lines) {
    vector<int> c(lines, -1);
    int ptr = 0;
    cout << "\n--- Fully Associative (FIFO) ---\n";
    for (int b : refs) {
        bool hit = find(c.begin(), c.end(), b) != c.end();
        if (!hit) { c[ptr] = b; ptr = (ptr + 1) % lines; }
        cout << b << ": " << (hit?"HIT ":"MISS") << " -> ";
        show(c);
    }
}

void setAssoc(vector<int> refs, int lines, int ways) {
    int sets = lines / ways;
    vector<vector<int>> c(sets, vector<int>(ways, -1));
    vector<int> ptr(sets,0);

    cout << "\n--- Set Associative (" << ways << "-way) ---\n";
    for (int b : refs) {
        int s = b % sets;
        bool hit = find(c[s].begin(), c[s].end(), b) != c[s].end();
        if (!hit) {
            c[s][ptr[s]] = b;
            ptr[s] = (ptr[s] + 1) % ways;
        }
        cout << b << ": " << (hit?"HIT ":"MISS") << " -> ";
        for (int i=0;i<sets;i++) { cout<<"{"; show(c[i]); cout<<"} "; }
        cout << "\n";
    }
}

int main() {
    int n; 
    cout << "Enter number of references: ";
    cin >> n;

    vector<int> refs(n);
    cout << "Enter block numbers: ";
    for (int &x: refs) cin >> x;

    int lines; 
    cout << "Enter number of cache lines: ";
    cin >> lines;

    directMap(refs, lines);
    fullyAssoc(refs, lines);

    int ways;
    cout << "Enter associativity (ways): ";
    cin >> ways;

    setAssoc(refs, lines, ways);
}
