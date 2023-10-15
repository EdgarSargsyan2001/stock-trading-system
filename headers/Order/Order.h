#ifndef ORDER_H
#define ORDER_H

class Stock;           // forward declaration
class Trader;          // forward declaration
class BuySellStrategy; // forward declaration

class Order
{
public:
    explicit Order(Stock *stock, int qty, BuySellStrategy *p) noexcept;
    virtual ~Order() noexcept;

    // delete copy operations
    Order(const Order &) = delete;
    Order &operator=(const Order &) = delete;

    virtual bool be_done(Trader *) const = 0;
    virtual double get_limit_cost() const;

    // getters
    Stock get_stock() const;
    int get_quantity() const;
    const BuySellStrategy *get_buySellStrategy() const;

private:
    const BuySellStrategy *const m_buySellStrategy;
    Stock &m_stock;
    int m_quantity;
};

#endif // ORDER_H