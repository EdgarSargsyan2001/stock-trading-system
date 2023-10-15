#ifndef FUNCTIOC_H
#define FUNCTIOC_H

#include "Stock/Stock.h"
#include "OrderBook/OrderBook.h"
#include "Order/Order.h"

void change_stock_cost(Stock &Apple);
void orderBook_buy(OrderBook &orderBook);
void orderBook_sell(OrderBook &orderBook);
void print_OrderBook(OrderBook &orderBook);

// for user interface
void create_trader(OrderBook &orderBook);
void change_now_trader(OrderBook &orderBook);
void create_order(OrderBook &orderBook, Stock *stock);

#endif // FUNCTIOC_H