#include <iostream>
#include <string>

using std::string;
using std::size_t;

class Solution {
public:
    string generateTheString(int n) {
        string answer;
        char ch = 'a';

        if(n < 26)
        {
            for(int i = 0; i < n; ++i)
            {
                answer += ch + i;
            }
            return answer;
        }

        if(n % 2 != 0)
        {
            string ans(n, ch);
            return ans;
        }
        char c = ch+n%7;
        string ans(n-1,c);
        if(ch != c)
            ans += ch;
        else
            ans += ch+1;
        return ans;

    }
    //решение с литкода
    string generateTheStringL(int n) {
        return "b" + string(n - 1, 'a' + n % 2);
    }
};

int main()
{
    Solution s;
    string str = s.generateTheStringL(33);
    std::cout << str << std::endl;
}