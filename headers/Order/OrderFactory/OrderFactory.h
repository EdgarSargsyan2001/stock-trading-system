#ifndef ORDERACTORY_H
#define ORDERACTORY_H
#include "Order/Order.h"

class OrderFactory
{

public:
    OrderFactory() = delete;

    static Order *createLimitOrderSell(Stock *stock, int qty, double limit_cost);
    static Order *createLimitOrderBuy(Stock *stock, int qty, double limit_cost);

    static Order *createMarketOrderSell(Stock *stock, int qty);
    static Order *createMarketOrderBuy(Stock *stock, int qty);
};

#endif // ORDERACTORY_H