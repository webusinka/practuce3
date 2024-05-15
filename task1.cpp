#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

struct Human {
    string name;
    int year_of_birth;
    int height;
    string sex;
};

int main() {
    //задание 1. Найти мужчину, самого молодого и самого низкого из мужчин!!!
    cout << "\tTask #1" << endl;
    vector<Human> human = {{"Dimtriy", 2006, 176, "M"}, {"Dasha", 2010, 151, "W"}, {"Veronika", 2005, 178, "W"}, {"Leonardo", 2011, 190, "M"}};
    human.push_back({"Ann", 1986, 169, "W"});
    human.push_back({"Sasha", 2003, 201, "M"});

    vector<Human> man;
    copy_if(human.begin(), human.end(), back_inserter(man), [](const Human& man) { 
        return man.sex == "M"; 
    });
    
    auto minAge = min_element(man.begin(), man.end(), [](const Human& man1, const Human& man2) {
        return man1.year_of_birth < man2.year_of_birth;
    });

    auto minHeight = min_element(man.begin(), man.end(), [](const Human& man1, const Human& man2) {
        return man1.height < man2.height;
    });

    cout << "Youngest man: " << minAge->name << endl;
    cout << "Shortest man: " << minHeight->name << endl;

    return 0;
}