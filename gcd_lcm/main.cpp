#include <iostream>

//Наибольший общий делитель gcd(a,b) двух положительных целых чисел - самое большое целое число на которое можно поделить a и b без остатка

int gcd_r(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    if (a % b == 0) return b;
    if (b % a == 0) return a;

    if (a > b) return gcd_r(a % b, b);
    else return gcd_r(a, b % a);
}
//Алгоритм Евклида
int gcd(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a >= b)
            a %= b;
        else
            b %= a;
    }

    int ans = a > b ? a : b;

    return ans;
}
//Наименьшее общее кратное lcm(a,b) самое маленькое число которое можно разделить и на a и на b
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
} 

int main()
{
    int a = 15;
    int b = 6;

    std::cout<< gcd(a,b)<<"\n";
    std::cout<< lcm(a,b)<<std::endl;
}