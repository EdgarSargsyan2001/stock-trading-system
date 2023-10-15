#ifndef OVERTIMESELL_H
#define OVERTIMESELL_H
#include "BuySellStrategy.h"

class OverTimeSell : public BuySellStrategy
{
    bool execute_strategy(Trader *trader, const Order &order) const override;
};

#endif // OVERTIMESELL_H