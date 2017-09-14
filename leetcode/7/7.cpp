#include<iostream>
using namespace std;
#include<cmath>
#include<queue>

/*
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
*/

class Solution {
public:
    int reverse(int x) {
        //是否是正数
        int flag;
        x>=0?flag=1:flag=-1;
        x = abs(x);
        queue<int>q;

        while(x!=0){
            q.push(x%10);
            cout<<x%10<<":"<<x<<"\n";
            x = x/10;
        }

        int len = q.size();
        cout<<len<<endl;
        int sum = 0;
        int a;
        while(!q.empty()){
            len--;
            a = q.front();
            q.pop();
            cout<<a<<endl;
            sum+= a*pow(10,len);
        }

        return sum*flag;

    }
};

int main(){

    Solution s;
    cout<<s.reverse(1534236469);
    return 0;
}
