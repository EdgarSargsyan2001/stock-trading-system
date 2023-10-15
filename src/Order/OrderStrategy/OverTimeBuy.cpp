#include "Order/OrderStrategy/OverTimeBuy.h"

bool OverTimeBuy::execute_strategy(Trader *trader, const Order &order) const
{
    if (order.get_stock().get_cost() > order.get_limit_cost())
    {
        return false;
    }
    buy_stock(trader, order);
    return true;
}