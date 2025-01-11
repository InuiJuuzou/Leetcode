#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <map>

using std::string;
using std::unordered_set;
using std::unordered_map;
using std::map;

class Solution {
public:
    long long calculateScore(string s) {
        //unordered_set<int> index; //контейнер для используемых индексов
        long long answ = 0;
        unordered_map<char,char> alphabit;

        //заполнение хеш таблицы зеркальными символами
        char c = 'a';
        int shift = 25;
        for(int i = 0; i < 26; ++i)
        {
            if(i < 13)
            {
                alphabit[c] = (char)(c + shift);
                shift -= 2;           
                }
            else
            {
                shift += 2;
                alphabit[c] = (char)(c - shift);
            }
            ++c;
        }
        
        //заполним хеш таблицу списком индекс-элемент, удаление, поиск и добавление в unordered_map O(1)
        unordered_map<int, char> index_char;
        size_t size = s.size();
        for(size_t i = 0; i < size; ++i)
        {
            index_char[i] = s[i];
        }

        for(const auto& [index, ch] : index_char)
        {
            std::cout << index <<" - "<<ch<<std::endl;
        }

        return answ;
    }
};

int main()
{
    using namespace std;
    Solution s;
    s.calculateScore("absdfrtgsjddfhfdlfgkl");
    //cout << (char)('z' -25) <<endl; 
}