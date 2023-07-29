/*****************************************************************************
FileName            : normal_fibonacci.hpp
Author              : DC
Version             : 
Date Of Creation    : 2023年07月29日
Description         : 传统方式生成斐波那契数列

Others              : 
Function List       : 
1.  ......
Modification History: 

Modification  :
*****************************************************************************/

class Fibonacci
{
public:
    int next() {
        if (a == -1) {
            a = 0;
            b = 1;
            return 0;
        }

        int next = b;
        b = a + b;
        a = b - a;
        return next;
    }

private:
    int a = -1;
    int b = 0;
};
