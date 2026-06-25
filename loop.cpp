#include <iostream>

int main() 
{
    int i, j, k;
    std::cin >> i;
    std::cin >> j;
    for (k = i; k <= j; k++)
    {
        if (k == 1)
        {
            printf("one\n");
        } else if (k == 2)
        {
            printf("two\n");
        } else if (k == 3)
        {
            printf("three\n");
        } else if (k == 4)
        {
            printf("four\n");
        } else if (k == 5)
        {
            printf("five\n");
        } else if (k == 6)
        {
            printf("six\n");
        } else if (k == 7)
        {
            printf("seven\n");
        } else if (k == 8)
        {
            printf("eight\n");
        } else if (k == 9)
        {
            printf("nine\n");
        } else if (k > 9)
        {
            if (k % 2 == 0)
            {
                printf("even\n");
            } else
            {
                printf("odd\n");
            }
        }
    }

}