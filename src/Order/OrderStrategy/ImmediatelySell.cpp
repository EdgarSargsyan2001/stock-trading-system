#include "Order/OrderStrategy/ImmediatelySell.h"

bool ImmediatelySell::execute_strategy(Trader *trader, const Order &order) const
{
    sell_stock(trader, order);
    return true;
}