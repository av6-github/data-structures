#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define CACHE_LINES 5

int main() {
    vector<int> mainMemory = {1,2,3,4,5,6,7,8,9,10};
    vector<int> cache(CACHE_LINES, -1);

    int HIT_COUNT = 0, TOTAL_COUNT = 0;

    while (true) {
        cout << "\nWhich block to fetch? (0 to exit): ";
        int value;
        cin >> value;
        if (value == 0) break;

        if (find(mainMemory.begin(), mainMemory.end(), value) == mainMemory.end()) {
            cout << "Number is not in Main Memory!\n";
            continue;
        }

        TOTAL_COUNT++;

        int line = value % CACHE_LINES;

        if (cache[line] == value) {
            cout << "Cache HIT at line " << line << "\n";
            HIT_COUNT++;
        } else {
            cout << "Cache MISS\n";
            cache[line] = value;
        }

        cout << "Current Cache: ";
        for (int x : cache) cout << x << " ";
        cout << "\nTotal Requests: " << TOTAL_COUNT;
        cout << "\nHit Count: " << HIT_COUNT;
        cout << "\nHit Ratio: " << (double)HIT_COUNT / TOTAL_COUNT << "\n";
    }
}
