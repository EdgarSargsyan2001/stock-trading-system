#include "Stock/Stock.h"

Stock::Stock(const std::string &name, double cost, int qty) noexcept
    : m_name(name), m_cost(cost), m_quantity(qty)
{
}
Stock::~Stock() noexcept {}

void Stock::set_cost(double c)
{
    m_cost = c;
}
void Stock::set_name(const std::string &n)
{
    m_name = n;
}
void Stock::set_quantity(int q)
{
    m_quantity = q;
}

double Stock::get_cost() const
{
    return m_cost;
}
std::string Stock::get_name() const
{
    return m_name;
}
int Stock::get_quantity() const
{
    return m_quantity;
}

void Stock::print() const
{
    std::cout << m_name << "-> count:" << m_quantity << " ";
}