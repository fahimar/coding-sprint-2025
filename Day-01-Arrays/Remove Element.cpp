#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int index = 0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }

};


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int val;
    cout << "Enter value to remove: ";
    cin >> val;

    Solution obj;
    int k = obj.removeElement(nums, val);

    cout << "\nOutput k = " << k << '\n';
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';

    return 0;
}