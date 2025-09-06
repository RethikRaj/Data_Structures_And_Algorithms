#include <bits/stdc++.h>
using namespace std;

int findMaximumEle(vector<int> &arr) {
    int maxi = INT_MIN;
    for (int ele : arr) {
        maxi = max(ele, maxi);
    }
    return maxi;
}

long long getSum(vector<int> &arr) {
    long long sum = 0;
    for (int ele : arr) {
        sum += ele;
    }
    return sum;
}

bool canWePaintInGivenTime(long long time, int A, int B, vector<int> &arr) {
    int z = 0; // index of board and also we can get numberOfBoardsPainted with z
    for (int painter = 0; painter < A && z < arr.size(); painter++) {
        long long timeTaken = 0;
        while (z < arr.size() && timeTaken + (1LL * arr[z] * B ) <= time) {
            timeTaken += 1LL * arr[z] * B;
            z++;
        }
    }
    return z == arr.size();
}

int paint(int A, int B, vector<int> &C) {
    int maximumEle = findMaximumEle(C);
    long long sum = getSum(C);

    long long low = 1LL * maximumEle * B; // If you dont want to multiply with 1LL we need to do type casting
    long long high = 1LL * sum * B;
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        bool canWePaintInMidTime = canWePaintInGivenTime(mid, A, B, C);

        if (canWePaintInMidTime) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans % 10000003;
}
