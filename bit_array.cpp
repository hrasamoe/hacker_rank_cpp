#include <iostream>
using namespace std;

int main()
{
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;
    long long MOD = 1LL << 31;
    long long tortue = (S * P + Q) % MOD;
    long long lievre = (tortue * P + Q) % MOD;
    size_t i = 1;
    while (tortue != lievre && i <= N)
    {
        tortue = (tortue * P + Q) % MOD;
        lievre = (lievre * P + Q) % MOD;
        lievre = (lievre * P + Q) % MOD;
        i++;
    }
    if ( N <= i)
    {
        cout << N << endl;
    }else 
    {
        size_t j = 0;
        tortue = S % MOD;
        while (tortue != lievre)
        {
            tortue = (tortue * P + Q) % MOD;
            lievre = (lievre * P + Q) % MOD;
            j++;
        }
        size_t k = 1;
        lievre = (tortue * P + Q) % MOD;
        while (lievre != tortue)
        {
            lievre = (lievre * P + Q) % MOD;
            k++;
        }
        size_t result = j + k;
        if (result > N)
            cout << N << endl;
        else 
            cout << result << endl;
        // cout <<  << endl;
    }
}