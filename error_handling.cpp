#include <iostream>
#include <cstdio>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n)
{
    if (n <= 0)
        throw std::invalid_argument("largest proper divisor is not defined for n=0");
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return n / i;
    }
    return 1;
}
void process_input(int n) {
   try{
      int d = largest_proper_divisor(n);
      cout << "result=" << d << endl;
   } catch(std::invalid_argument& e){
        cerr << e.what() << endl;
   }
    printf("returning control flow to caller");
}

int main()
{
    int i;
    cin >> i;
    process_input(i);
}