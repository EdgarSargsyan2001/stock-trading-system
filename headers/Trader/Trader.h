#ifndef TRADER_H
#define TRADER_H
#include <vector>
#include <string>
#include "Stock/Stock.h"

class Trader 
{
public:
    explicit Trader(const std::string &name, double money) noexcept;
    ~Trader() noexcept;

    // delete copy operations
    Trader(const Trader &) = delete;
    Trader &operator=(const Trader &) = delete;

    bool change_stock_quantity(const std::string &stockName, int deltaQuantity);
    bool includes_stock(const std::string &stockName) const;

    // setters
    void set_name(const std::string &n);
    void set_money(double m);
    void set_stock(Stock *sp);

    // getters
    std::string get_name() const;
    double get_money() const;

    void print() const;

private:
    std::vector<Stock *> m_stocks;
    std::string m_name;
    double m_money;
};

#endif // TRADER_H