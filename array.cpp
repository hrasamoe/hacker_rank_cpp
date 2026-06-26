#include <iostream>
#include <cstdio>

int main()
{
    int i, j, swap;
    std::cin >> i;
    int arr[i];
    for (j = 0; j < i; j++ )
    {
        std::cin >> swap;
        arr[j] = swap;
    }
    j -= 1;
    while (j >= 0)
    {
        printf("%d ", arr[j]);
        j--;
    }
}