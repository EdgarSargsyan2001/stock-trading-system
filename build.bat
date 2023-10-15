@echo off

rem Compiler settings (you can change these as needed)
set CXX=g++
set CXXFLAGS=-std=c++17  

rem Source code and output directories
set SRC_DIR=src
set INCLUDE_DIR=headers
set BUILD_DIR=build

rem List of source files (update this with your source files)
set SOURCES=%SRC_DIR%\main.cpp
set SOURCES=%SOURCES% %SRC_DIR%\functions\Functions.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\Order.cpp

set SOURCES=%SOURCES% %SRC_DIR%\Order\LimitOrder\LimitOrder.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\MarketOrder\MarketOrder.cpp

set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderFactory\OrderFactory.cpp

set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderStrategy\BuySellStrategy.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderStrategy\ImmediatelyBuy.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderStrategy\ImmediatelySell.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderStrategy\OverTimeBuy.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Order\OrderStrategy\OverTimeSell.cpp

set SOURCES=%SOURCES% %SRC_DIR%\OrderBook\OrderBook.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Stock\Stock.cpp
set SOURCES=%SOURCES% %SRC_DIR%\Trader\Trader.cpp


rem Output executable name
set OUTPUT_EXECUTABLE=%BUILD_DIR%\myApp.exe

rem Create the build directory if it doesn't exist
mkdir %BUILD_DIR%

rem Compile the source code
%CXX% %CXXFLAGS% -I%INCLUDE_DIR% %SOURCES% -o %OUTPUT_EXECUTABLE%

rem Check if compilation was successful
if %errorlevel% equ 0 (
    echo Compilation successful. Executable: %OUTPUT_EXECUTABLE%
) else (
    echo Compilation failed.
)
