#include "test.h"

Test::Test(int _a , int _b)
{
    a=_a;
    b=_b;
}

Test::Test()
{
    a=1;
    b=2;
    c=3;
}

void Test::show()
{
    std::cout << "hello\n";
}
