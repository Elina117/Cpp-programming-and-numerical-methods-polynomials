#include <iostream>
#include <cmath>

bool polindrom(int x)
{
    int original = x;
    int reversed = 0;

    while (x>0)
    {
        int digit = x%10;
        reversed = reversed*10+digit;
        x/=10;
    }

    return original == reversed;
}

int main()
{
    for (int i = 1 ; i<100; i++)
    {
        int sqr = i*i;
        if(polindrom(sqr))
        {
            std::cout << i << " ^ 2 = " << sqr << "(полиндром)";
        }
    }
}