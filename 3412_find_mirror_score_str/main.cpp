#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

using std::string;
using std::unordered_set;
using std::unordered_map;
using std::set;
using std::vector;

class Solution {
public:
//не проходит по времени
    long long calculateScoreM(string s) {
        //unordered_set<int> index; //контейнер для используемых индексов
        long long answ = 0;
        unordered_map<char,char> alphabit;

        size_t size = s.size();
        //заполняем весь алфовит чтобы не идти по длинной строке
        for(char i = 'a'; i <= 'z'; ++i)
        {
            alphabit[i] = 'a' + 'z' - i;
        }

        //заполним хеш таблицу списком индекс-элемент, удаление, поиск и добавление в unordered_map O(1)
        unordered_map<int, char> index_char;//индекс элемент
        for(size_t i = 0; i < size; ++i)
        {
            index_char[i] = s[i];
        }

        //проходим по строке с 1го элемента, проверяем элемента в index_char которые ниже по индексу
        for(size_t i = 1; i < size; ++i)
        {
           // size_t j = 0;
            int j = i-1;
            //while( j < i)
            while(j >= 0)
            {
                if(index_char.find(j) != index_char.end())
                {
                    //если индекс существует берем символ, ищем его в алфавите и смотрим равен ли зеркальный сивол нашему. Если да удаляем
                    if(alphabit.at(index_char.at(j)) == s[i])
                    {
                        answ+=(i-j);//заполняем требуемое в условии в ответ
                        index_char.erase(index_char.find(j));
                        index_char.erase(index_char.find(i));
                        break;
                    }
                }
               // ++j;
               --j;
            }
        }

        return answ;
    }
    
    long long calculateScore(string s)
    {
        long long answer = 0;
        unordered_map<char, vector<int>> char_index;
        int size = s.size();

        for(int i = 0; i < size; ++i)
        {
            char mirror = 'a' + 'z' - s[i];
            if(char_index.find(mirror) != char_index.end())
            {
                int j = char_index.at(mirror).back();
                answer += (i - j);
                if(char_index.at(mirror).size() == 1)
                {
                    char_index.erase(mirror);
                }
                else
                {
                    char_index.at(mirror).pop_back();
                }
                continue;
            }
            char_index[s[i]].push_back(i);
        }

        return answer;
    }

//списанное решение(не мое)
    long long calculateScore1(string s) {
        unordered_map<char, vector<int>> d;
        int n = s.length();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            char x = s[i];
            char y = 'a' + 'z' - x;
            if (d.count(y)) {
                vector<int>& ls = d[y];
                int j = ls.back();
                ls.pop_back();
                if (ls.empty()) {
                    d.erase(y);
                }
                ans += i - j;
            } else {
                d[x].push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    using namespace std;
    Solution s;
    cout << s.calculateScore("aczzx") << endl;


}