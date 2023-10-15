#ifndef IMMEDIATLEYBUY_H
#define IMMEDIATLEYBUY_H
#include "BuySellStrategy.h"

class ImmediatelyBuy : public BuySellStrategy
{
    bool execute_strategy(Trader *trader, const Order &order) const override;
};

#endif // IMMEDIATLEYBUY_H