/*
 *  O(n^2) time complexity
 *      foreach (item1 in array) {
 *          foreach (item2 int array) {
 *              if (item1 + item2 == target) {
 *                  return result;
 *              }
 *          }
 *      }
 *      
 *      嵌套的循环只是用来查找， 可以用hashmap 存储 将time-complexity 缩减到O(1) 
 *       key： numer  value： position
 *       如果有重复数字怎么办？ 
 *       
 *      可以把‘target - num[i]' 放进 map，  num[i] 在map中 即找到
 *      
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            //not found the second one 
            if (m.find(numbers[i]) == m.end()) {
                    m[target - numbers[i]] = i;
            }else {
                //found the second one
                result.push_back(m[numbers[i]] + 1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    
    vector<int> ret = s.twoSum(v, 10);
    for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << " ";
    }
    return 0;

}
