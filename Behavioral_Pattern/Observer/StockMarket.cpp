#include "StockMarket.h"
#include <iostream>
using namespace std;

void StockMarket::setPrice(const string& stock, double price) {
    stockPrices[stock] = price;
    notify(stock);
}

double StockMarket::getPrice(const string& stock) {
    return stockPrices[stock];
}

void StockMarket::attach(shared_ptr<Observer> obs) {
    observers.push_back(obs);
}

void StockMarket::detach(shared_ptr<Observer> obs) {
    observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
}

void StockMarket::notify(const string& stock) {
    for (auto& obs : observers) {
        obs->update(stock, stockPrices[stock]);
    }
}
