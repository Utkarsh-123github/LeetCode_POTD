// Minimum operations to exceed threshold value II
// You are given a 0-indexed integer array nums, and an integer k.

// In one operation, you will:

// Take the two smallest integers x and y in nums.
// Remove x and y from nums.
// Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.

// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
    int ans=0;
    while(pq.top()<k){
        long long x=pq.top(); pq.pop();
        long long y=pq.top(); pq.pop();
        pq.push(2*x+y);
        ans++;
    }
    return ans; 
}