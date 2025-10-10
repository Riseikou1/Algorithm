#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int>& perms, vector<int>& nums, vector<bool>& pick){
    if(perms.size() == nums.size()){
        res.push_back(perms);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(!pick[i]){
            pick[i] = true;
            perms.push_back(nums[i]);
            backtrack(perms, nums, pick);
            pick[i] = false;
            perms.pop_back();
        }
    }
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> perms;
    vector<bool>pick(nums.size(), false);
    backtrack(perms, nums, pick);

    for(auto& a : res){
        for(int num : a){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}