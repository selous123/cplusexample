#include<iostream>
using namespace std;
#include<vector>
#include<map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

        vector <int> result;
        map <int,int> m;//<value,position>
        int len = nums.size();

        int i;
        for(i=0;i<len;i++){
            m[nums[i]] = i;
            cout<<m[nums[i]]<<endl;
        }

        int findNumsLen = findNums.size();
        int pos;
        int j;
        for(j=0;j<findNumsLen;j++){
            pos = m[findNums[j]];
            cout<<"pos:"<<pos<<endl;
            for(i=pos+1;i<len;i++){
                if(nums[i]>findNums[j]){
                    result.push_back(nums[i]);
                    break;
                }
            }
            if(i==len){
                result.push_back(-1);
            }
        }
        return result;


    }
};



int main(){
    vector<int> v1;
    vector<int> v2;

    v1.push_back(4);
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(2);

    Solution s;
    vector<int> result;
    result = s.nextGreaterElement(v1,v2);

    int i;
    for(i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }


    return 0;
}

