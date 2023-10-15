#ifndef OVERTIMEBUY_H
#define OVERTIMEBUY_H
#include "BuySellStrategy.h"

class OverTimeBuy : public BuySellStrategy
{
    bool execute_strategy(Trader *trader, const Order &order) const override;
};

#endif // OVERTIMEBUY_H