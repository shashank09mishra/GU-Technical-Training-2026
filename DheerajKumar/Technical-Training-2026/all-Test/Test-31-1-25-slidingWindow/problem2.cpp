#include<iostream>
#include<limits.h>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int largestString(string& s){
            vector<char> mapper = {'a', 'e', 'i', 'o', 'u'};
            int start = 0, end = 0, pointer = 0, counter = 0, maxLength = INT_MIN;

            while(end < s.size()){
                if(s[end] != mapper[pointer]){
                    pointer++;
                }
                if(pointer < 5){
                    if(s[end] != mapper[pointer]){
                        start = end;
                    }
                }
                if(counter == 5){
                    maxLength = max(maxLength, end - start);
                }
                end++;
            }
            return maxLength == INT_MIN ? 0 : maxLength;
        }
};

int main(){
    Solution test;

    string s;
    cout<<"enetr the string ->> ";
    getline(cin, s);

    cout<<"the maximum Lenght -> "<<test.largestString(s);
}


/*complaxity -> time  O(n)
    space -> O(1)*/