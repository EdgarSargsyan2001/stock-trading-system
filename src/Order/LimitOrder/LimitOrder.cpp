#include "Order/LimitOrder/LimitOrder.h"
#include "Order/OrderStrategy/BuySellStrategy.h"

LimitOrder::LimitOrder(Stock *stock, int qty, BuySellStrategy *const p, double limit_cost) noexcept
    : Order(stock, qty, p), m_limit_cost(limit_cost)
{
}
double LimitOrder::get_limit_cost() const
{
    return m_limit_cost;
}
bool LimitOrder::be_done(Trader *trader) const
{
    return get_buySellStrategy()->execute_strategy(trader, *this);
}