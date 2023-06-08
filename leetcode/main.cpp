#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>

using namespace std;

/* leetcode 1, map */
vector<int> twosum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++){
        auto it = map.find(target-nums[i]);
        if (it != map.end()) {
            return {it->second,i};
        }
        map[nums[i]] = i;
    }
    return {}; 
}

/* leetcode2559 dp */
bool is_target_word(string s) {
    string yuanyin = "aeiou";
    if(yuanyin.find(s.at(0)) !=-1 && yuanyin.find(s.at(s.size()))!=-1){
        return true;
    }

    return false;
}

vector<int> vowelString(vector<string>& words,vector<vector<int>>& queries) {
    int n = words.size();
    int dp[n+1];
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        if(is_target_word(words.at(i))){
            dp[i+1] = dp[i] + 1;
        }else{
            dp[i+1] = dp[i];
        }
    }

    vector<int> res;

    for (vector<int> tmp: queries){
        res.push_back(dp[tmp[1]+1]-dp[tmp[0]]);
    }
    
    return res;
}

/* leetcode 1156 string */
int maxRepOpt1(string text) {
    unordered_map<char,vector<int>> map;
    int n = text.size();
    for(int i = 0;i < n;i++){
        map[text[i]].push_back(i);
    }

    int res = 1;
    for(auto it = map.begin();it!=map.end();it++){
        vector<int> tmp = it->second;
        int n2 = tmp.size();
        int cur = 1;
        int pre = 0;
        int maxi = 0;
        //{0,2,3,6}
        for(int i=1;i<n2;i++){
            if(tmp[i] = tmp[i-1]+1){
                cur++;
            }else{
                pre = tmp[i]==tmp[i-1]+2?cur:0;
                cur = 1;
            }

            maxi = max(maxi,cur+pre);
        }

        res = max(res,maxi<n2?maxi+1:maxi);

    }

    return res;
}

/* leetcode 2465 set */
int distinctAverages(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    unordered_set<int> set;
    for (int i = 0;i < n/2;i++){
        set.insert(nums[i]+nums[n-i-1]);
    }

    return set.size();
}

/* leetcode 2517 binary*/
bool is_ok(vector<int>& price, int diff, int k) {

    int count = 1;
    for(int i = 0;i<price.size();i++){
        int j = i;
        while (j<price.size() && price[j]-price[i] < diff)
        {
            j++;
        }

        if (j<price.size()){
            count++;
            i = j-1;
        }else {
            break;
        }

        if(count>=k){
            return true;
        }
        
    }

    return false;
}
int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(),price.end());
    int left = 0,right = INT_MAX/2;

    while(left<right){
        //int mid = left + (right-left)/2;
        int mid = right - (right - left)/2;
        if(is_ok(price,mid,k)){
            left = mid;
        }else{
            right = mid - 1;
        }
    }

    return left;
}

/* leetcode 2460 */
vector<int> applyOperations(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for(int i = 0;i < n;i++ ){
        if(i < n-1 && nums[i] == nums[i+1]){
            res.push_back(nums[i]*2);
            i++;
        }else{
            if(nums[i]!=0){
                res.push_back(nums[i]);
            }
        }
    }

    while(res.size()<n){
        res.push_back(0);
    }

    return res;
}

/* leetcode 2352 */

bool helper(int i,int j,vector<vector<int>> grid){
    
}
int equalPairs(vector<vector<int>>& grid){
    int n = grid[0].size();

}

int main() {
    
    string s = "abaa";
    int res = maxRepOpt1(s);


    cout<<res<<endl;

    return 0;
}





















