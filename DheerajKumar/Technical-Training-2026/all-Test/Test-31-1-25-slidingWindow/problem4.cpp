#include<iostream>
#include<vector>
#include<limits.h>
#include<string>

using namespace std;

class Solution{
    public:
        int longestSemiRepetitive(string& number){
            int count = 0, start = 0, end = 1, maximumLenght = INT_MIN;

            while(end < number.size()){
                if(number[end] == number[end - 1]){
                    count++;
                }

                if(count > 1){
                    maximumLenght = max(maximumLenght, (end - start));
                    count = 0;
                    start = end;
                }
                end++;
            }

            return maximumLenght;
        }
};

int main(){
    Solution test;

    string s;
    cout<<"Enter the string ->> ";
    getline(cin, s);

    cout<<"maximum length -> "<<test.longestSemiRepetitive(s);
}


/* complaxity -> O(n)
    space complaxity -> O(1)
    
    excluding the input time and space complaxity !*/