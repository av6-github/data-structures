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
    int hits = 0, faults = 0;

    for (int page : refs) {
        bool hit = (find(fr.begin(), fr.end(), page) != fr.end());

        if (hit) hits++;
        else {
            faults++;
            fr[p] = page;
            p = (p + 1) % f;
        }

        // print frames at this step
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
