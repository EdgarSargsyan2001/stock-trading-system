#include "Order/Order.h"
#include "Trader/Trader.h"
#include "Stock/Stock.h"
#include "Order/OrderStrategy/BuySellStrategy.h"

Order::Order(Stock *stock, int qty, BuySellStrategy *p) noexcept
    : m_stock(*stock), m_quantity(qty), m_buySellStrategy(p)
{
}
Order::~Order() noexcept
{
    delete m_buySellStrategy;
}
double Order::get_limit_cost() const
{
    return 0;
}
const BuySellStrategy *Order::get_buySellStrategy() const
{
    return m_buySellStrategy;
};
Stock Order::get_stock() const
{
    return m_stock;
}
int Order::get_quantity() const
{
    return m_quantity;
}

