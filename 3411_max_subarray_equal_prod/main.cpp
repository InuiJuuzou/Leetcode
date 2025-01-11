#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
//NOD(a1,a2,a3,a4)=NOD(NOD(NOD(a1,a2),a3),a4)
class Solution {
public:
    int maxLength1(vector<int>& nums) {
        int answer = 0;
        vector<int> tmp;

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                tmp.push_back(nums[j]);
                if(product(tmp) == gcd_vec(tmp) * lcm_vec(tmp))
                {
                    if(tmp.size() > answer)
                        answer = tmp.size();
                }
            }
            tmp.clear();
        }

        return answer;
    }


    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i=0; i< n; ++i){
            if (n-i <= ans) break;
            
            int p= 1, l = nums[i], g = nums[i];
            for (int j=i; j < n; ++j){
                p *= nums[j];
                l = std::lcm(l, nums[j]);
                g = std::gcd(g, nums[j]);
 
                if (p == l * g) ans = std::max(ans, j-i+1);
                else if (i != j) break;
            }
        }
        return ans;
    }
private:
    long int product(vector<int>& nums)
    {
        long int answ = 1;
        for(int n : nums)
        {
            answ *= n;
        }
        return answ;
    }
    //НОД
    long int gcd_vec(vector<int>& nums)
    {
        long int gcd = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            gcd = std::gcd(gcd, nums[i]);
        }
        return gcd;
    }
    //НОК
    long int lcm_vec(vector<int>& nums)
    {
        long int lcm = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            //lcm = (lcm * nums[i])/std::gcd(lcm,nums[i]);
            lcm = std::lcm(lcm, nums[i]);
        }
        return lcm;
    }

};

int main()
{
    using namespace std;
    Solution s;
    vector<int> nums = {1,2,1,2,1,1,1};

    cout<<s.maxLength(nums)<<endl;
}