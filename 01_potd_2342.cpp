// Max Sum of a Pair With Equal Sum of Digits

#include<bits/stdc++.h>
using namespace std;

// Brute approach
int maximumSum(vector<int>& nums) {
    int n = nums.size();
    vector<int>digSum(n);
    for(int i=0;i<n;i++){
        int p = nums[i];
        string x = to_string(p);
        int num = 0;
        for(int j=0;j<x.length();j++){
            int a = x[j]-'0';
            num += a;
        }
        digSum[i] = num;
    }
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(digSum[i] == digSum[j]){
                maxi = max(maxi,nums[i] + nums[j]);
            }
        }
    }
    return maxi;
}

// Optimal Approach

int calcSum(int n){
    int res = 0;
    while(n>0){
        res += n%10;
        n = n/10;
    }
    return res;
}
int maximumSum(vector<int>& nums) {
    int maxi = -1;
    int n = nums.size();
    unordered_map<int,int>digSum;
    for(int i=0;i<n;i++){
        int sum = calcSum(nums[i]);
        if(digSum.find(sum) != digSum.end()){
            maxi = max(maxi,nums[i] + digSum[sum]);
            digSum[sum] = max(digSum[sum],nums[i]);
        }
        else{
            digSum[sum] = nums[i];
        }
    }
    return maxi;
}
