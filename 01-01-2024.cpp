// Array Pair Sum Divisibility Problem

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i] % k;
            int need = (k - curr) % k;

            if (mp.count(need))
            {
                mp[need]--;

                if (mp[need] == 0)
                    mp.erase(need);
            }
            else
                mp[curr]++;
        }

        if (mp.size() == 0)
            return true;
        else
            return false;
    }
};
