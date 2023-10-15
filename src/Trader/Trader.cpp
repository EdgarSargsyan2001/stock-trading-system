#include "Trader/Trader.h"

Trader::Trader(const std::string &name, double money) noexcept
    : m_name(name), m_money(money)
{
}

Trader::~Trader() noexcept
{
    for (int i = 0; i < m_stocks.size(); ++i)
    {
        delete m_stocks[i];
    }
}

bool Trader::change_stock_quantity(const std::string &stockName, int deltaQuantity)
{
    for (int i = 0; i < m_stocks.size(); ++i)
    {
        if (m_stocks[i]->get_name() == stockName)
        {
            int quantity = m_stocks[i]->get_quantity();
            if ((deltaQuantity < 0) && (quantity < abs(deltaQuantity)))
            {
                return false;
            }
            m_stocks[i]->set_quantity(quantity + deltaQuantity);
            return true;
        }
    }
    return false;
}
bool Trader::includes_stock(const std::string &stockName) const
{
    for (auto it : m_stocks)
    {
        if (it->get_name() == stockName)
        {
            return true;
        }
    }
    return false;
}

// setters
void Trader::set_name(const std::string &n)
{
    m_name = n;
}
void Trader::set_money(double m)
{
    m_money = m;
}
void Trader::set_stock(Stock *sp)
{
    m_stocks.push_back(sp);
}

// getters
std::string Trader::get_name() const
{
    return m_name;
}
double Trader::get_money() const
{
    return m_money;
}

void Trader::print() const
{
    std::cout << m_name
              << "\n\tmoney: " << m_money << "\n\tstocks:[ ";
    for (auto it : m_stocks)
    {
        it->print();
    }
    std::cout << " ]" << std::endl;
}
