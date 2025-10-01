#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include "Subject.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

class StockMarket : public Subject {
private:
    unordered_map<string, double> stockPrices;
    vector<shared_ptr<Observer>> observers;

public:
    void setPrice(const string& stock, double price);
    double getPrice(const string& stock);
    void attach(shared_ptr<Observer> obs) override;
    void detach(shared_ptr<Observer> obs) override;
    void notify(const string& stock) override;
};

#endif
