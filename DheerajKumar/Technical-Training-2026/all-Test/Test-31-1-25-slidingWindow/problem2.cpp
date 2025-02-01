#include<iostream>
#include<limits.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int start = 0, end = 1, maximumLength = 0, counter = 0, currentAlphabet = 0;
        vector<int> mapper = {'a' - 'a', 'e' - 'a', 'i' - 'a', 'o' - 'a', 'u' - 'a'};
        
        while(word[start] - 'a' != 0){
            start++;
        }
        cout<<"\nsize of word = "<<word.size();
        cout<<"\nfirst a is at -> "<<start;

        end = start;

        while(end < word.size()){
            if(word[end] - 'a' == currentAlphabet){

            }
            end++;
        }
        return maximumLength;
    }
};


int main(){
    Solution test;

    string s;
    cout<<"enetr the string ->> ";
    getline(cin, s);

    cout<<"the maximum Lenght -> "<<test.longestBeautifulSubstring(s);
}


/*complaxity -> time  O(n)
    space -> O(1)*/