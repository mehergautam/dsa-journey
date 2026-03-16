#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k){

    int sum = 0;
    int maxSum = 0;

    for(int i=0;i<k;i++)
        sum += arr[i];

    maxSum = sum;

    for(int i=k;i<arr.size();i++){

        sum += arr[i];
        sum -= arr[i-k];

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){

    vector<int> arr = {2,1,5,1,3,2};
    int k = 3;

    cout<<"Max Sum: "<<maxSumSubarray(arr,k);
}
