#ifndef IMMEDIATLEYSELL_H
#define IMMEDIATLEYSELL_H
#include "BuySellStrategy.h"

class ImmediatelySell : public BuySellStrategy
{
    bool execute_strategy(Trader *trader, const Order &order) const override;
};

#endif // IMMEDIATLEYSELL_H