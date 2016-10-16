// 

/*
 * 
 * Givern an array of integers that is already sorted in ascending order;
 * find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target.
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
 * are not zero-based
 * 
 * You may assume that each input would have exactly on solution.
 * 
 * Input: number = {2, 7, 11, 15}, target = 9
 * Output: index1 = 1, index2 = 2
 * 
 * *******************************/


//已排好序的数组， 可以左右夹逼。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }else {
                numbers[low] + numbers[high] > target ? high-- : low++;
            }
        }

        return result;
    }
};

void myFunc(int i) {
    cout << i << " ";
}

int main()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    vector<int> result = s.twoSum(v, 9);
    for_each(result.begin(), result.end(), myFunc);

    cout << endl;
    return 0;    
}


















