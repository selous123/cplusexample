#include<iostream>
using namespace std;
#include<string>
#include<stack>
#define MAX 26

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[MAX];
        bool isInStack[MAX];
        stack<char> st;
        int i;
        for(i=0;i<MAX;i++){
            counter[i] = 0;
            isInStack[i] = false;
        }

        for (i=0;i<s.length();i++){
            counter[s[i]-'a']++;
        }
        char ch;
        for(i=0;i<s.length();i++){
            ch = s[i];
            counter[ch- 'a']--;
            if(isInStack[ch-'a'])continue;
            while(!st.empty()&&st.top()>ch&&counter[st.top()-'a']>0){
                isInStack[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            isInStack[ch-'a'] = true;
        }
        string result;
        while(!st.empty()){
            result.append(1,st.top());
            st.pop();
        }

        return result;

    }
};



int main(){

    string s1="cbacdcbc";
    Solution s;
    cout<<s.removeDuplicateLetters(s1)<<endl;
    return 0;
}
