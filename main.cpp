#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
    public:
    vector<vector<int>> subArr(vector<int>nums){
        int n = nums.size();
        vector<vector<int>> result;
    
        // cout << "{";
        for(int st = 0; st<n; st++){
            for(int end = st; end<n; end++){
                vector<int> currentSub;
                for(int i = st; i<=end; i++){
                    currentSub.push_back(nums[i]);
                }
                result.push_back(currentSub);
            }
            // cout << endl;
        }
        // cout << "}";
        return result;

    }
};

int main() {
    //vector<int> nums = {1,2,3,4,5};
    vector<int> nums = {3,-4,5,4,-1,7,-8};
    
    Solution sol;
    vector<vector<int>> ans = sol.subArr(nums);
    
    cout << "ans = [";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << "]\n";
    
    int maxSum = 0;
    int sum = 0;
    int subArrSum = 0;
    for(int i=0; i<ans.size(); i++){
        subArrSum = accumulate(begin(ans[i]), end(ans[i]),0);
        sum += accumulate(begin(ans[i]), end(ans[i]),0);
        maxSum = max(maxSum, subArrSum);
    }
    
    cout << "Sum of all subArray element: " << sum << endl;
    cout << "Maximum subArray  sum: " << maxSum << endl;

    
    return 0;
}