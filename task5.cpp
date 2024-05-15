#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //задание 5. Пройдет ли автобус под мостом, если не проходит – на каком мосту произойдет авария.
    cout << "\tTask #5" << endl;

    vector<int> bridges = {455, 500, 653, 350, 300};
    const int bus_height = 437;

    auto crash_it = find_if(bridges.begin(), bridges.end(), [](int bridge_height) {
        return bus_height >= bridge_height;
    });

    if (crash_it == bridges.end()) {
        cout << "No crash";
    } else{
        cout << "Crash " << distance(bridges.begin(), crash_it) + 1 << " bridges";
    }
    
    return 0;
}