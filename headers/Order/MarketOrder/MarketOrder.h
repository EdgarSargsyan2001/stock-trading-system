#ifndef MARKETORDER_H
#define MARKETORDER_H
#include "Order/Order.h"

class MarketOrder : public Order
{
public:
    explicit MarketOrder(Stock *stock, int qty, BuySellStrategy *const p) noexcept;
    bool be_done(Trader *trader) const override;
};

#endif /// MARKETORDER_H