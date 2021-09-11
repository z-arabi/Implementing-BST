#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test
{
    public:
        Test(int _a){a = _a;}
        Test(int _a , int _b);
        Test();
        void show();
        int a , b , c;
};

#endif