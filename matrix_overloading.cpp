#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
   public:
      vector<vector<int>> a;
   Matrix operator+(const Matrix& otherMatrix)
   {
      Matrix result;
      int d1 = a.size();
      int d2 = a[0].size();
      result.a.resize(d1, vector<int>(d2));

      for (int i = 0; i < d1; i++)
      {
         for (int j = 0; j < d2; j++)
         {
            result.a[i][j] = this->a[i][j] + otherMatrix.a[i][j];
         }
      }
      return result;
   }

};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}

