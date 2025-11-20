#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n;

    vector<int> refs(n);
    for (int &x : refs) cin >> x;
    cin >> f;

    vector<int> fr(f, -1), last(f, -1);
    int hits = 0, faults = 0;

    for (int t = 0; t < n; t++) {
        int p = refs[t];
        bool hit = false;

        // check hit
        for (int i = 0; i < f; i++)
            if (fr[i] == p) hit = true, last[i] = t;

        if (hit) hits++;
        else {
            faults++;
            int pos = -1;

            // empty frame
            for (int i = 0; i < f; i++)
                if (fr[i] == -1) { pos = i; break; }

            // if no empty, choose LRU page
            if (pos == -1)
                pos = min_element(last.begin(), last.end()) - last.begin();

            fr[pos] = p;
            last[pos] = t;
        }

        // print frames
        for (int x : fr)
            if (x == -1) cout << "- ";
            else cout << x << " ";
        cout << "\n";
    }

    cout << "\nTotal Hits: " << hits << "\n";
    cout << "Total Faults: " << faults << "\n";
    cout << "Hit Ratio: " << fixed << setprecision(2)
         << (double)hits / n << "\n";
}
