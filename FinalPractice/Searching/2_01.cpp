// Binary Search => Reduces the search space logarithmically

#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            // Discard left
            low = mid + 1;
        } else {
            // discard right
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int> &arr, int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);
    } else {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
}