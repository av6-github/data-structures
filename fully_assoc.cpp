#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define CACHE_SIZE 5

int main() {
    vector<int> mainMemory = {1,2,3,4,5,6,7,8,9,10};
    vector<int> cache;

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

        auto it = find(cache.begin(), cache.end(), value);

        if (it != cache.end()) {
            cout << "Cache HIT\n";
            HIT_COUNT++;

            cache.erase(it);
            cache.insert(cache.begin(), value);
        }
        else {
            cout << "Cache MISS\n";

            if (cache.size() == CACHE_SIZE) {
                cout << "Cache Full — Removing least recently used element: " << cache.back() << "\n";
                cache.pop_back();
            }
            cache.insert(cache.begin(), value);
        }

        cout << "Current Cache: ";
        for (int x : cache) cout << x << " ";
        cout << "\nTotal Requests: " << TOTAL_COUNT;
        cout << "\nHit Count: " << HIT_COUNT;
        cout << "\nHit Ratio: " << (double)HIT_COUNT / TOTAL_COUNT << "\n";
    }
}
