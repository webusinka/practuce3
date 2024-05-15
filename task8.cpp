#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        //задание 8.
    cout << "\tTask #8" << endl;

    vector<int> school_scores = {205, 212, 198, 220, 201, 215, 207, 203, 211, 218};
    vector<int> lyceum_scores = {208, 213, 202, 217, 209, 216, 204, 210, 219, 206};

    vector<int> all_scores(school_scores.size() + lyceum_scores.size());
    copy(school_scores.begin(), school_scores.end(), all_scores.begin());
    copy(lyceum_scores.begin(), lyceum_scores.end(), all_scores.begin() + school_scores.size());

    sort(all_scores.begin(), all_scores.end(), std::greater<int>());

    // Определяем, из какого учреждения дети заняли 5 первых мест
    int school_count = 0, lyceum_count = 0;
    for (int i = 0; i < 5; ++i) {
        if (find(school_scores.begin(), school_scores.end(), all_scores[i]) != school_scores.end()) {
            ++school_count;
        } else {
            ++lyceum_count;
        }
    }

    cout << "Top 5 scores:\n";
    cout << "School: " << school_count << " students\n";
    cout << "Lyceum: " << lyceum_count << " students\n";

    auto it = find(all_scores.begin(), all_scores.end(), 213);
    if (it != all_scores.end()) {
        iter_swap(all_scores.begin(), it);
    }

    all_scores.erase(remove_if(all_scores.begin(), all_scores.end(), [](int score) {
        return score < 210;
    }), all_scores.end());

    cout << "\nSorted scores:\n";
    for (int score : all_scores) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}