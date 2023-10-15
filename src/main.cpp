#include <iostream>
#include <vector>
#include <windows.h>

#include "Stock/Stock.h"
#include "Trader/Trader.h"
#include "Order/OrderFactory/OrderFactory.h"
#include "OrderBook/OrderBook.h"
#include "functions/Functions.h"

// global variables
int Time_for_chenging = 3200;
bool is_over = false;
bool is_typing = false;

int main()
{
    // create Apple Stock
    Stock Apple("Apple", 150.1, 10000);
    HANDLE changeStocksThread = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(change_stock_cost), &Apple, 0, NULL); // for user interface

    // create order Book
    OrderBook orderBook;
    HANDLE printThread = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(print_OrderBook), &orderBook, 0, NULL); // for user interface
    HANDLE sellThread = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(orderBook_sell), &orderBook, 0, NULL);
    HANDLE buyThread = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(orderBook_buy), &orderBook, 0, NULL);

    orderBook.set_trader(new Trader("Edgar", 100000));

    int x;
    while (!is_over) // for user interface
    {
        is_typing = false;

        std::cin >> x;
        is_typing = true;

        switch (x)
        {
        case 0:
            is_over = true;
            break;
        case 1:
            create_trader(orderBook);
            break;
        case 2:
            change_now_trader(orderBook);
            break;
        case 3:
            create_order(orderBook, &Apple);
            break;
        }
    }

    // Wait threads to finish
    WaitForSingleObject(changeStocksThread, INFINITE);
    WaitForSingleObject(printThread, INFINITE);
    WaitForSingleObject(sellThread, INFINITE);
    WaitForSingleObject(buyThread, INFINITE);

    // Close thread handles
    CloseHandle(changeStocksThread);
    CloseHandle(printThread);
    CloseHandle(sellThread);
    CloseHandle(buyThread);

    std::cout << "App is over\n";
    system("pause");
}
