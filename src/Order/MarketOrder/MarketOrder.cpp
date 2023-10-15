#include "Order/MarketOrder/MarketOrder.h"
#include "Order/OrderStrategy/BuySellStrategy.h"

MarketOrder::MarketOrder(Stock *stock, int qty, BuySellStrategy *const p) noexcept
    : Order(stock, qty, p)
{
}

bool MarketOrder::be_done(Trader *trader) const
{
    return get_buySellStrategy()->execute_strategy(trader, *this);
}