#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int circles_count(int init, int c) {
    if (c == '0' || c == '6' || c == '9')
        return init + 1;
    if (c == '8')
        return init + 2;
    return init;
}

int main() {
    //задание 6. Количество кругов в цифрах числа. 
    cout << "\tTask #6" << endl;

    string number = "506834782119";
    int result = accumulate(number.begin(), number.end(), 0, circles_count);

    // Вывод в консоль
    cout << result << endl;

    return 0;
}