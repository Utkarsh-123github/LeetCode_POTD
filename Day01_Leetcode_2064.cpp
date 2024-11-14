// Minimized Maximum of Products Distributed to Any Store

// You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

// You need to distribute all products to the retail stores following these rules:

// A store can only be given at most one product type but can be given any amount of it.
// After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number  of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
// Return the minimum possible x.

// Example 1:
// Input: n = 6, quantities = [11,6]
// Output: 3
// Explanation: One optimal way is:
// - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
// - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
// The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

// Example 2:
// Input: n = 7, quantities = [15,10,10]
// Output: 5
// Explanation: One optimal way is:
// - The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
// - The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
// - The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
// The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

#include<bits/stdc++.h>
using namespace std;

int minimizedMaximum(int n, vector<int>& quantities) {
    // Initialise the search range for binary search
    int low = 1, high = INT_MIN, res = 0;
    // Find nax quantity in the quantities vector to set the high value
    for (auto it : quantities){
        high = max(high,it);
    }

    // Perform BS to find the minimized max value of product per store
    while(low <= high){
        // mid is the probable answer value
        int mid = low + (high-low)/2;
        int sum = 0; // Sum represents total stored needed if max products per store is mid
        for(int x : quantities){
            sum += (ceil((float)(x) / (float)(mid)));
        }

        // Check if mid allows for distribution within the given store limit n
        if(sum <= n){
            res = mid;
            // check for smaller value
            high = mid-1;
        }
        else{
            low  = mid+1; // Increase the lower bound if more stores are needed than available
        }
    }
    return res;
}

int main(){
    int n = 6;
    vector<int> quantities = {11,6};
    cout<<minimizedMaximum(n, quantities)<<endl;
    return 0;
}