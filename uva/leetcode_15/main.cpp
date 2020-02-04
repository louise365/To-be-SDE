#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());//O(NLogN)
        for(int i=0;i<nums.size();i++)
        {
            int s = i+1;
            int e = nums.size()-1;
            while(1)
            {
                if(s>=nums.size() || s>= e)
                    break;
                int sum2 = nums[i] + nums[s];
                if(sum2 < 0 && nums[e] <= 0)
                    break;
                if(sum2 >=0 && nums[e] >0)
                    break;
                int sum3 = sum2 + nums[e];
                if(sum3 == 0)
                {
                    vector<int> rt = {nums[i],nums[s],nums[e]};
                    ret.push_back(rt);
                }
                else if(sum3 < 0)
                    s++;
                else
                    e--;
            }
        }
    }
};
int main()
{
    vector<int> vt = {-1, 0, 1, 2, -1, -4};
    Solution s;
    cout<<s.threeSum(vt)<<endl;
    return 0;
}
