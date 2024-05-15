#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main() {
    //задание 3. Количество черных и белых полос и найти какой цвет преобладает.
    cout << "\tTask #3" << endl;

    vector<string> life = {"White", "White", "Black", "White", "Black", "Black", "Black",  "White",  "White",  "White",  "White"};

    int black_count = count(life.begin(), life.end(), "Black");
    int white_count = count(life.begin(), life.end(), "White");

    life.erase(unique(life.begin(), life.end()), life.end());
    cout << "Count of white days: " << count(life.begin(), life.end(), "White") << endl;
    cout << "Count of black days: " << count(life.begin(), life.end(), "Black") << endl;
    
    if (black_count > white_count) {
        cout << "Black time of life" << endl;
    } else if (black_count < white_count) {
        cout << "White time of life" << endl;
    } else {
        cout << "Grey time..." << endl;
    }

    return 0;
}