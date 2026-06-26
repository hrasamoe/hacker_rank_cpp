#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {   int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int l = 0; l < q; l++)
    {
        int x, y;
        cin >> x >> y;
        printf("%d\n",a[x][y]);
    }
}