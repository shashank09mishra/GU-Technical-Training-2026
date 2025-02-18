#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int> frequency;
            int higestFrequencyNumber = 1; float higestFrequency = 0;
            
            for(int i = 0; i < nums.size(); i++){
                auto locator = frequency.find(nums[i]);
                
                if(locator == frequency.end()){
                    frequency[nums[i]] = 1;
                }
                else{
                    frequency[nums[i]]++;
                }
            }
    
            for(auto element : frequency){
                if(element.second > higestFrequency){
                    
                    higestFrequency = element.second;
                    higestFrequencyNumber = element.first;
                }
            }
            return higestFrequencyNumber;
        }
    };