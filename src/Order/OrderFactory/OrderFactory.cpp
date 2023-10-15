
#include "Order/OrderFactory/OrderFactory.h"

#include "Order/LimitOrder/LimitOrder.h"
#include "Order/MarketOrder/MarketOrder.h"

#include "Order/OrderStrategy/ImmediatelyBuy.h"
#include "Order/OrderStrategy/ImmediatelySell.h"
#include "Order/OrderStrategy/OverTimeBuy.h"
#include "Order/OrderStrategy/OverTimeSell.h"

Order *OrderFactory::createLimitOrderSell(Stock *stock, int qty, double limit_cost)
{
    return new LimitOrder(stock, qty, new OverTimeSell(), limit_cost);
}
Order *OrderFactory::createLimitOrderBuy(Stock *stock, int qty, double limit_cost)
{
    return new LimitOrder(stock, qty, new OverTimeBuy(), limit_cost);
}
Order *OrderFactory::createMarketOrderSell(Stock *stock, int qty)
{
    return new MarketOrder(stock, qty, new ImmediatelySell());
}
Order *OrderFactory::createMarketOrderBuy(Stock *stock, int qty)
{
    return new MarketOrder(stock, qty, new ImmediatelyBuy());
}