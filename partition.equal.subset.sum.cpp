#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     bool canPartition(vector<int>& nums) {
       int totalSum=0; 
       for(int n:nums) totalSum +=n; 
       if(totalSum%2 !=0) return false; 
       int subSetSum = totalSum/2; 
       vector<bool> dp(totalSum+1, false); 
       dp[0] = true; 
       for(int n:nums){
         for(int j= subSetSum; j>=n; --j){
           dp[j] = dp[j] || dp[j-n] ;
         }
       }
       return dp[subSetSum]; 
     }
};
int main(){
  vector<int> nums ={1,5,11,5};
  Solution sol;
  cout << boolalpha << sol.canPartition(nums) << endl;
  return 0;
}
