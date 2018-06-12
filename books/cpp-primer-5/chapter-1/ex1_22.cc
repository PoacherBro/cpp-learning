#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item item;
        while (std::cin >> item)
        {
            if (item.isbn() == total.isbn())
                total = total + item;
            else
            {
                std::cout << total << std::endl;
                total = item;
            }
        }

        std::cout << total << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data or error input!" << std::endl;
        return -1;
    }
}
