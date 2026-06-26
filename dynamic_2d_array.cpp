#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = new int[k];
    }
}