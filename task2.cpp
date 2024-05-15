#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    for (const auto& el : vec) {
        cout << el << " ";
    }
    cout << endl;
}

int main(){    
    //задание 2. Найти сумму всех отрицательных, найти max и min, переместить в вектор квадраты чисел между ними
    cout << "\tTask #2" << endl;
    vector<int> task10 = { 2, -10, 3, -60, 4 , -5, 9, -59, 100};

    int sum_negative = accumulate(task10.begin(), task10.end(), 0, [](const int& result, const int& element) {
        return element < 0 ? result + element : result;
    });
    cout << "Sum of negative numbers: " << sum_negative << endl;

    auto minmax = minmax_element(task10.begin(), task10.end());
    vector<int> squares(minmax.second - minmax.first - 1);
    transform(next(minmax.first), minmax.second, squares.begin(),[](const int& val) {
        return val * val;
    });
    cout << "Vector of square: ";
    printVector(squares);

    return 0;
}