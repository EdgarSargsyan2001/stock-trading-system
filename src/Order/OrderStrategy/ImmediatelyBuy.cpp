#include "Order/OrderStrategy/ImmediatelyBuy.h"

bool ImmediatelyBuy::execute_strategy(Trader *trader, const Order &order) const
{
    buy_stock(trader, order);
    return true;
}