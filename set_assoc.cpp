#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NUM_SETS 3
#define WAYS 2          // 2-way set associative

int main() {
    vector<int> mainMemory = {1,2,3,4,5,6,7,8,9};

    // cache[set] = vector of pages in that set
    vector<vector<int>> cache(NUM_SETS);

    int input;

    while (true) {
        cout << "\nEnter number to find: ";
        cin >> input;

        int setIndex = input % NUM_SETS;
        auto &set = cache[setIndex];

        auto it = find(set.begin(), set.end(), input);

        if (it != set.end()) {
            cout << "Cache HIT for " << input 
                 << " in set " << setIndex << "\n";
            set.erase(it);
            set.insert(set.begin(), input); // LRU: move to front
        }
        else {
            cout << "Cache MISS for " << input 
                 << " in set " << setIndex << "\n";

            if (set.size() == WAYS)
                set.pop_back();             // evict LRU from that set

            set.insert(set.begin(), input);
        }

        cout << "Cache Content:\n";
        for (int s = 0; s < NUM_SETS; s++) {
            cout << "Set " << s << ": ";
            for (int x : cache[s]) cout << x << " ";
            cout << "\n";
        }
    }
}
