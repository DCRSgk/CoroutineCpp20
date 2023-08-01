/*****************************************************************************
FileName            : coroutine_fibonacci.hpp
Author              : DC
Version             : 
Date Of Creation    : 2023年07月29日
Description         : 协程版本实现斐波那契数列

Others              : 
Function List       : 
1.  ......
Modification History: 

Author  :
Modification  :
*****************************************************************************/

#include "generator.hpp"

Generator fibonacci()
{
    co_yield 0;
    co_yield 1;

    int a = 0;
    int b = 1;
    while (true)
    {
        co_yield a + b;
        b = a + b;
        a = b - a;
    }
}