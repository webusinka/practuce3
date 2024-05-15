#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Задание 7.
    cout << "\tTask #7" << endl;

    vector<double> dollar_rate = {60.5, 61.2, 59.8, 62.1, 63.5, 64.0, 63.7, 62.9, 61.3, 60.1, 59.2, 58.8};

    vector<double> deposits(12, 0.0);
    double current_deposit = 0.0;
    for (int i = 0; i < 12; ++i) {
        current_deposit += 100.0;
        deposits[i] = current_deposit;
    }

    auto max_it = max_element(deposits.begin(), deposits.end());
    int index_of_max_deposit = distance(deposits.begin(), max_it);

    cout << "The most profitable month to withdraw the deposit: " << index_of_max_deposit + 1 << "-th month" << endl;

    return 0;
}