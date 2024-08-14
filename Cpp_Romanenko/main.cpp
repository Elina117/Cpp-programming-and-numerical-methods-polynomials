#include <stdio.h>
#include <iostream>
#include <cmath>


bool task_number_59_B(double x, double y);

int main() 
{
    //59B
    double x, y;
    std::cout << "Enter the coordinates of the point (x, y): ";
    std::cin >> x >> y;

    if (task_number_59_B(x, y)) {
        std::cout << "The point belongs to the shaded area";
    } else {
        std::cout << "The point does not belong to the shaded area";
    }

    return 0;

  
    
}


bool task_number_59_B(double x, double y) 
{
    if (x >= -1 && x <= 1 && -1 <= y && y <= 1) {
        return true;
    } else {
        return false;
    }
}

std::vector<int> num_common_divisors_227(int a, int b)
{
    std::vector<int> common_div;
    if(a==0 && b==0)
    {
        std::cout << "mistake";
    }
    else
    {
        int min_num = std::min(std::abs(a), std::abs(b));
        
        for(int div = 1; div<=min_num; ++div)
        {
            if(a%div == 0 && b%div == 0)
            {
                common_div.push_back(div);
                common_div.push_back(-div);
            }
        }
    }
    return common_div;
}

double num_103(double u, double v, double e)
{
    u = 1;
    v = 2/3;
    if (e<0)
    {
        while ((v-u)>e)
        {
            u = v;
            v = ((u+1)/(u+2));
        }
        std::cout << v;
    }
    return v;
}