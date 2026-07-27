#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";

}

int main(){
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}