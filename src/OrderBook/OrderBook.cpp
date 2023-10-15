#include <algorithm>
#include "OrderBook/OrderBook.h"
#include "Order/Order.h"
#include "Trader/Trader.h"

OrderBook::~OrderBook() noexcept
{
    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        Trader *trader = it->first;
        auto &map_orders = it->second;
        for (auto it = map_orders.begin(); it != map_orders.end(); ++it)
        {
            std::vector<const Order *> &v = it->second;
            for (int i = 0; i < v.size(); ++i)
            {
                delete v[i];
            }
        }
        delete trader;
    }
}
void OrderBook::remove_order(Trader *trader, int order_index, Index index)
{

    auto &map_orders = m_data[trader];

    if (map_orders.find(index) != map_orders.end())
    {
        std::vector<const Order *> &v = map_orders[index];
        int last_el = v.size() - 1;

        std::swap(v[order_index], v[last_el]);

        delete v[last_el];
        v.pop_back();
    }
}
void OrderBook::set_order(const Order *order, Index index)
{
    if (m_now_trader != nullptr)
    {
        m_data[m_now_trader][index].push_back(order);
    }
}

void OrderBook::set_trader(Trader *t)
{
    m_now_trader = t;
    m_data[t];
}
void OrderBook::change_now_trader(const std::string &name)
{
    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        Trader *trader = it->first;
        if (trader->get_name() == name)
        {
            m_now_trader = trader;
        }
    }
}

void OrderBook::iterate_orders(std::function<bool(Trader *, const Order *, int i)> visitor, Index index)
{
    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        Trader *trader = it->first;
        auto &map_orders = it->second;

        if (map_orders.find(index) != map_orders.end())
        {
            std::vector<const Order *> &v = map_orders[index];
            for (int i = 0; i < v.size();)
            {
                if (!visitor(trader, v[i], i))
                {
                    ++i;
                }
            }
        }
    }
}
void OrderBook::print()
{
    if (m_now_trader != nullptr)
    {
        auto Orders = m_data[m_now_trader];

        m_now_trader->print();
        std::cout << "\torders-> buy: " << Orders[Index::buy_vector].size()
                  << "  sell: " << Orders[Index::sell_vector].size() << "\n\n";
    }
}

void OrderBook::print_all_traders()
{
    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        std::cout << it->first->get_name() << '\n';
    }
}
