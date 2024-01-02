// Largest Sum Subarray of Size at least K

#include <bits/stdc++.h>
using namespace std;
 
// TC -> O(n)
// SC -> O(n)
class Solution{
    public:  
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int maxSubarraySum[n];
        long long int currSum = a[0];
        
        maxSubarraySum[0] = (currSum);
        for(long long int i=1; i<n; i++)
        {
            if(currSum > 0)
                currSum += a[i];
            else
                currSum = a[i];
            
            maxSubarraySum[i] = (currSum);
        }
        
        long long int ans = INT_MIN;
        
        long long int exactK = 0;
        for(long long int i=0; i<k; i++)
        {
            exactK += a[i];
        }
        
        if(exactK > ans)
            ans = exactK;
            
        for(long long int i=k; i<n; i++)
        {
            exactK = a[i] + exactK - a[i-k] ;
            
            if(exactK > ans)
                ans = exactK;
                
            long long int prevBestSubarray = exactK + maxSubarraySum[i-k];
            if(prevBestSubarray > ans)
                ans = prevBestSubarray;
        }
        
        return ans;
    }
};

int main()
{
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}