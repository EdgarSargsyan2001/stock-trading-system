#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <iostream>

class Stock
{
public:
    explicit Stock(const std::string &name, double cost, int qty) noexcept;
    ~Stock() noexcept;

    // setters
    void set_cost(double c);
    void set_name(const std::string &n);
    void set_quantity(int q);

    // getters
    double get_cost() const;
    std::string get_name() const;
    int get_quantity() const;

    //
    void print() const;

private:
    std::string m_name;
    double m_cost;
    unsigned int m_quantity;
};

#endif // STOCK_H