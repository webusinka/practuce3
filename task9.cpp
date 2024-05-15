#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> remove_and_sort_by_descending(vector<string> car_brands) {

    car_brands.erase(remove_if(car_brands.begin(), car_brands.end(), [](const std::string& brand) {
        return brand.find("BM") != string::npos;
    }), car_brands.end());

    sort(car_brands.rbegin(), car_brands.rend());
    
    return car_brands;
}

int main() {
    //задание 9.
    cout << "\tTask #9" << endl;

    vector<string> car_brands = {"BMW", "Mercedes", "Audi", "Skoda", "Volvo", "Subaru", "Lamborghini", "BMWi"};
    
    vector<string> result = remove_and_sort_by_descending(car_brands);

    for (const auto& brand : result) {
        cout << brand << " ";
    }
    cout << endl;
    
    return 0;
}