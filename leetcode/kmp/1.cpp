#include<iostream>
using namespace std;
#include<cstring>
#define MAX_LENGTH 100

int next[MAX_LENGTH]
void kmp(char *pattern){
    int len = strlen(pattern);
    int i=0,j=-1;
    next[0] = -1;
    while(i<len){
        //没有匹配上
        if(j==-1||pattern[i]==pattern[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

char *longestsubarray(char *ss,char *str){
    kmp(str);
    //next数组
    ss_len = strlen(ss);
    int i=0,j=0;
    while(i<ss_len){
        if(j==-1||ss[i]==str[j]){
            i++;j++;
        }else{
            j = next[j];
        }
    }

}

int main(){
    cout<<"hello world\n";

    return 0;
}
