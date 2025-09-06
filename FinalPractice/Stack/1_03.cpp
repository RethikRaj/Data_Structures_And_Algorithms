// Implement n stacks in an array

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
class NStack {
public:
    int* arr;   // array to store all stack elements
    int* top;   // top[i] stores the index of the top element of the i-th stack
    int* next;  // next[i] stores either the next free index OR the previous element in the stack
    int freeSpot; // beginning index of free slots (head of free list)

    // Constructor: Initialize data structure
    NStack(int N, int S) {
        arr = new int[S];   // main storage array
        top = new int[N];   // tracks tops of N stacks
        next = new int[S];  // helps in managing free list + stack links
        freeSpot = 0;       // first free index is 0

        // Initialize all stacks as empty
        for (int i = 0; i < N; i++) {
            top[i] = -1;    // -1 means no element in that stack
        }

        // Initialize free list
        // Every index points to the next one, last points to -1
        next[S - 1] = -1;
        for (int i = 0; i < S - 1; i++) {
            next[i] = i + 1;
        }
    }

    // Pushes 'x' into the Mth (1-based index) stack
    // Returns true if successful, false if overflow
    bool push(int x, int m) {
        // Check overflow (no free space left)
        if (freeSpot == -1) {
            return false;
        }

        // Step 1: Get index of free slot
        int index = freeSpot;

        // Step 2: Update freeSpot to next free index
        freeSpot = next[index];

        // Step 3: Insert element into arr[]
        arr[index] = x;

        // Step 4: Link new element to the previous top of stack m
        next[index] = top[m - 1];

        // Step 5: Update top of stack m
        top[m - 1] = index;

        return true;
    }

    // Pops from the Mth (1-based index) stack
    // Returns -1 if empty, otherwise popped element
    int pop(int m) {
        // Check underflow (stack is empty)
        if (top[m - 1] == -1) {
            return -1;
        }

        // Step 1: Get index of top element
        int index = top[m - 1];

        // Step 2: Move top to the next element in the stack
        top[m - 1] = next[index];

        // Step 3: Add this index back to the free list
        next[index] = freeSpot;
        freeSpot = index;

        // Step 4: Return the popped element
        return arr[index];
    }
};
