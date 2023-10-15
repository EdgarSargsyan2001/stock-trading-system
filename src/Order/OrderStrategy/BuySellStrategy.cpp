#include "Order/OrderStrategy/BuySellStrategy.h"

void BuySellStrategy::set_stock_Trader(Trader *trader, const std::string &stockName) const
{
    if (!trader->includes_stock(stockName))
    {
        trader->set_stock(new Stock(stockName, 0, 0));
    }
}
void BuySellStrategy::buy_stock(Trader *trader, const Order &order) const
{
    int quantity = order.get_quantity();
    double wholePrice = order.get_stock().get_cost() * quantity;

    if (trader->get_money() >= wholePrice)
    {
        std::string stockName = order.get_stock().get_name();
        set_stock_Trader(trader, stockName);
        trader->change_stock_quantity(stockName, quantity);
        trader->set_money(trader->get_money() - wholePrice);
    }
}
void BuySellStrategy::sell_stock(Trader *trader, const Order &order) const
{
    std::string stockName = order.get_stock().get_name();

    if (trader->includes_stock(stockName))
    {
        int quantity = order.get_quantity();
        if (trader->change_stock_quantity(stockName, -quantity))
        {
            double cost = order.get_stock().get_cost();
            trader->set_money(trader->get_money() + (cost * quantity));
        }
    }
}
