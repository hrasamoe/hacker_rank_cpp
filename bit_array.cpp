#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;
int main()
{
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    long long int_max = 1LL << 31;
    vector<long long> array(N);
    array[0] = S % int_max;
    for (size_t i = 1; i < N; i++)
    {
        array[i] = array[i - 1] * P + Q % int_max;
    }
    unordered_set<int> set(array.begin(), array.end());
    int response = set.size();
    cout << response << endl;
}