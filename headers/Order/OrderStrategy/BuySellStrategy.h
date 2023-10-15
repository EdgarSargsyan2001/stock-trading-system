#ifndef BUYSELLSTRATEGY_H
#define BUYSELLSTRATEGY_H
#include "Trader/Trader.h"
#include "Order/Order.h"
#include <iostream>

class BuySellStrategy
{
public:
    virtual ~BuySellStrategy(){};
    virtual bool execute_strategy(Trader *, const Order &) const = 0;
    void set_stock_Trader(Trader *, const std::string &) const;
    void buy_stock(Trader *, const Order &) const;
    void sell_stock(Trader *, const Order &) const;
};

#endif // BUYSELLSTRATEGY_H
