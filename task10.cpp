#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Transaction {
    int buy_day;
    int buy_time;
    int sell_day;
    int sell_time;
    int profit;
};

vector<Transaction> find_top_day_transactions(const vector<int>& stock_prices, const vector<int>& buy_times, const vector<int>& sell_times) {
    vector<Transaction> transactions;
    
    // Находим все возможные прибыльные сделки
    for (int buy_day = 0; buy_day < stock_prices.size(); ++buy_day) {
        for (int sell_day = buy_day + 1; sell_day < stock_prices.size(); ++sell_day) {
            int profit = stock_prices[sell_day] - stock_prices[buy_day];
            if (profit > 0) {
                transactions.push_back({buy_day, buy_times[buy_day], sell_day, sell_times[sell_day], profit});
            }
        }
    }
    
    // Сортируем сделки по убыванию прибыли
    sort(transactions.begin(), transactions.end(), [](const Transaction& t1, const Transaction& t2) {
        return t1.profit > t2.profit;
    });
    
    // Фильтруем сделки, совершенные только днем
    vector<Transaction> day_transactions;
    for (const auto& transaction : transactions) {
        if (transaction.buy_time == 1 && transaction.sell_time == 1) {
            day_transactions.push_back(transaction);
            if (day_transactions.size() == 2) {
                break;
            }
        }
    }
    
    return day_transactions;
}

int main() {
    //задание 10.
    cout << "\tTask #10" << endl;
    vector<int> stock_prices_in_mlrd = {10, 7, 5, 8, 11, 9};
    vector<int> buy_times = {0, 1, 0, 1, 1, 1}; // 0 - ночь, 1 - день
    vector<int> sell_times = {1, 0, 1, 1, 0, 1};
    
    vector<Transaction> top_day_transactions = find_top_day_transactions(stock_prices_in_mlrd, buy_times, sell_times);
    
    // Вывод результата
    for (const auto& transaction : top_day_transactions) {
        cout << "Buy on day " << transaction.buy_day << " (time: " << (transaction.buy_time == 0 ? "night" : "day") << "), "
                << "sell on day " << transaction.sell_day << " (time: " << (transaction.sell_time == 0 ? "night" : "day") << "), "
                << "profit: " << transaction.profit << endl;
    }
    
    return 0;
}