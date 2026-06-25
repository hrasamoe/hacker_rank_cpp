#include <iostream>
#include <cstdio>

int max_of_four(int a, int b, int c, int d)
{

    int max = 0;
    if ( a > max) {
        max = a;
    }
        if ( c > max) {
        max = c;
    }
        if ( b > max) {
        max = b;
    }
        if ( d > max) {
        max = d;
    }
    return (max);
}


int main()
{
    int i, j, k, l;

    std::cin >> i;
    std::cin >> j;
    std::cin >> k;
    std::cin >> l;
    printf("%d\n", max_of_four(i, j, k, l));
}