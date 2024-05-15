#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    //задание 4. map с именем человека, пара: количество ранений и тяжесть(0 – царапина, 5 - предсмертное)
    //Рассортируйте по уменьшению тяжести и определить максимальный расход бинтов на царапины.
    cout << "\tTask #4" << endl;
    map<string, pair <int, int>> injured = {{"Djed", {2, 0}}, {"Tom", {1, 3}}, {"Robert", {2, 5}}, {"Tim", {4, 0}}};

    vector<pair<string, pair<int, int>>> sorted_wounded(injured.begin(), injured.end());
    sort(sorted_wounded.begin(), sorted_wounded.end(), [](const auto& a, const auto& b) {
        return a.second.second > b.second.second;
    });

    auto max_bandages_iter = max_element(sorted_wounded.begin(), sorted_wounded.end(), [](const auto& a, const auto& b) {
        return a.second.first < b.second.first && a.second.second == 0;
    });
    int max_bandages = (max_bandages_iter != sorted_wounded.end()) ? max_bandages_iter->second.first : 0;

    cout << "Sorted injured people:" << endl;
    for (const auto& [name, state] : sorted_wounded) {
        cout << name << ": " << state.first << " injuries, severity " << state.second << endl;
    }
    cout << "Maximum bandages for a scratch: " << max_bandages << endl;

    return 0;
}