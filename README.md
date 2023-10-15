# Stock Trading System

- The program is designed for **Windows** operating system.

- There is a **build.bat** to build the app․

  > It uses **G++** compiler.

- After that a folder named **build** is created in which the executable file is located.

- The design includes **Trader**, **Stock**, **Order**, **OrderBook** classes.
  **Order** is an abstract class from which the **MarketOrder** and **LimitOrder** classes inherit.

- I used the **Strategy** design pattern for MarketOrder and LimitOrder and
  **Factory** design pattern with the help of which I create different types of Orders by giving them the appropriate strategy.

## functionality։

- You can exploit the system

| isnt. number |     operation     |
| :----------: | :---------------: |
|      0       |       Exit        |
|      1       |   Create Trader   |
|      2       | Change now Trader |
|      3       |   Create Order    |
