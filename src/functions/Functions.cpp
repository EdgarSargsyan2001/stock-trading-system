#include <iostream>
#include <vector>
#include <windows.h>
#include <mutex>
#include <random>

#include "Order/OrderFactory/OrderFactory.h"
#include "functions/Functions.h"
#include "Trader/Trader.h"

std::mutex mtx; // Mutex for protecting access to shared resources
extern int Time_for_chenging;
extern bool is_over;
extern bool is_typing;

void orderBook_buy(OrderBook &orderBook)
{
    while (!is_over)
    {
        Sleep(Time_for_chenging);
        orderBook.iterate_orders([&orderBook](Trader *trader, const Order *order, int i)
                                 {
                                        std::lock_guard<std::mutex> lock(mtx);
                                        if (order->be_done(trader))
                                        {
                                            orderBook.remove_order(trader,i,Index::buy_vector);
                                            return true;
                                        }
                                        return false; },
                                 Index::buy_vector);
    }
}

void orderBook_sell(OrderBook &orderBook)
{
    while (!is_over)
    {
        Sleep(Time_for_chenging);
        orderBook.iterate_orders([&orderBook](Trader *trader, const Order *order, int i)
                                 {  
                                        std::lock_guard<std::mutex> lock(mtx);
                                        if (order->be_done(trader))
                                        {
                                            orderBook.remove_order(trader,i,Index::sell_vector);
                                            return true;

                                        } return false; },
                                 Index::sell_vector);
    }
}

// for user interface
void change_stock_cost(Stock &Apple)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(149.5, 190.5);
    double perv_val = 0;
    while (!is_over)
    {

        Apple.set_cost(dist(mt));
        double cost_now = Apple.get_cost();

        if (!is_typing)
        {
            std::cout << Apple.get_name() << ": [" << cost_now << "] " << (((perv_val - cost_now) > 0) ? '-' : '+');
            std::cout << "\n\n";
        }

        perv_val = cost_now;

        Sleep(Time_for_chenging - 70);
        if (!is_typing)
        {
            system("cls");
        }
    }
}
// for user interface
void print_OrderBook(OrderBook &orderBook)
{
    while (!is_over)
    {
        if (!is_typing)
        {
            orderBook.print();
            std::cout << "[0]: exit\n";
            std::cout << "[1]: create Trader\n";
            std::cout << "[2]: change now Trader\n";
            std::cout << "[3]: create Order\n";
        }
        Sleep(Time_for_chenging);
    }
}
// for user interface
void create_trader(OrderBook &orderBook)
{
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    orderBook.set_trader(new Trader(name, 1000));
}
void change_now_trader(OrderBook &orderBook)
{
    orderBook.print_all_traders();
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    orderBook.change_now_trader(name);
}

void create_order(OrderBook &orderBook, Stock *stock)
{
    std::cout << "[0]: Market order sell\n";
    std::cout << "[1]: Market order buy\n";
    std::cout << "[2]: Limit order sell\n";
    std::cout << "[3]: Limit order buy\n";
    int n, m;
    std::cin >> n;
    switch (n)
    {
    case 0:
        std::cout << "enter quantity: ";
        std::cin >> n;
        orderBook.set_order(OrderFactory::createMarketOrderSell(stock, n), Index::sell_vector);
        break;
    case 1:
        std::cout << "enter quantity: ";
        std::cin >> n;
        orderBook.set_order(OrderFactory::createMarketOrderBuy(stock, n), Index::buy_vector);
        break;
    case 2:
        std::cout << "enter quantity: ";
        std::cin >> n;
        std::cout << "enter cost: ";
        std::cin >> m;
        orderBook.set_order(OrderFactory::createLimitOrderSell(stock, n, m), Index::sell_vector);
        break;
    case 3:
        std::cout << "enter quantity: ";
        std::cin >> n;
        std::cout << "enter cost: ";
        std::cin >> m;
        orderBook.set_order(OrderFactory::createLimitOrderBuy(stock, n, m), Index::buy_vector);
        break;
    }
}