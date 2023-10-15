#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <map>
#include <vector>
#include <functional>
#include <iostream>

class Trader; // forward declaration
class Order;  // forward declaration

enum Index : char
{
    buy_vector,
    sell_vector,
};

class OrderBook
{
public:
    OrderBook() = default;
    ~OrderBook() noexcept;

    // delete copy operations
    OrderBook(const OrderBook &) = delete;
    OrderBook &operator=(const OrderBook &) = delete;

    // setters
    void set_order(const Order *o, Index index);
    void set_trader(Trader *t);
    void change_now_trader(const std::string& name);

    // transfer
    void iterate_orders(std::function<bool(Trader *, const Order *, int i)> visitor, Index index);

    void remove_order(Trader *t, int o_i, Index index);

    //for user interface
    void print();
    void print_all_traders();

private:
    Trader *m_now_trader = nullptr;
    std::map<Trader *, std::map<Index, std::vector<const Order *>>> m_data;
};

#endif // ORDERBOOK_H