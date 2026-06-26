#include <iostream>

int absolute(int *a, int *b)
{

    int result;
    result = (*a) - (*b);
    if (result < 0) {
        return result *= -1;
    }
    else {
        return result;
    }
}

int sum(int *a, int *b)
{
    return (*a) + (*b);
}

int main()
{
    int a, b;
    std::cin >> a;
    std::cin >> b;
    printf("%d\n", sum(&a, &b));
    printf("%d\n", absolute(&a, &b));
}