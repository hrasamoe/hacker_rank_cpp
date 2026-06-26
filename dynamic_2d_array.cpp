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
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
    }
    while (q > 0)
    {
        int x,y;
        cin >> x >> y;
        printf("%d\n", a[x][y]);
        q--;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}