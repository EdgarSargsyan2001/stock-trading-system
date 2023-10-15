#ifndef LIMITORDER_H
#define LIMITORDER_H
#include "Order/Order.h"

class LimitOrder : public Order
{
public:
    explicit LimitOrder(Stock *stock, int qty, BuySellStrategy *const p, double limit_cost) noexcept;

    double get_limit_cost() const override;
    bool be_done(Trader *trader) const override;

private:
    double m_limit_cost;
};

#endif // LIMITORDER_H
