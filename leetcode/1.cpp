#include<iostream>
using namespace std;
#include<cstring>
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);

    int maxlen = 0;
    int i;
    int start = -1;
    int dist[256];
    for(i=0;i<256;i++){
        dist[i] = -1;
    }
    for(i=0;i<len;i++){
        //做一点改变
        //使用ascii码判断是否存在
        /*
        for(j=0;j<g[ind-1];j++){
            if(s[ind-1-j]==s[ind]){
                break;
            }
        }
        */
        if(dist[s[i]]>start){
            start = dist[s[i]];
        }
        dist[s[i]] = i;
        maxlen = max(maxlen,i-start);
    }
    return maxlen;
}



int main(){
    char ch[10];
    cin>>ch;
    cout<<lengthOfLongestSubstring(ch);
    return 0;
}
