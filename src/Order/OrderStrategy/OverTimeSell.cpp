#include "Order/OrderStrategy/OverTimeSell.h"

bool OverTimeSell::execute_strategy(Trader *trader, const Order &order) const
{
    if (order.get_stock().get_cost() < order.get_limit_cost())
    {
        return false;
    }
    sell_stock(trader, order);
    return true;
}
