//
//
//

/*********************************************************
 * Design and implement a TwoSum class. It should support the following operations: add and find
 * 
 * add - Add the number to an internal data structure.
 * find - find if there exists any pair of numbers which sum is equal to the value.
 * 
 * For example,
 * 
 * add(1); add(3); add(5);
 * find(4) -> true;
 * find(7) -> false;
 * 
 * ********************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
private:
    unordered_map<int, int> nums;
public:

    void add(int number) {
        nums[number]++;
    }

    bool find(int value) {
        int one, two;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            one = it->first;
            two = value - one;
            if ((one == two  && it->second > 1) ||
                    (one != two && nums.find(two) != nums.end() )) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    TwoSum twoSum;
    twoSum.add(1);
    twoSum.add(3);
    twoSum.add(5);
  
    cout << twoSum.find(4) << endl;
    cout << twoSum.find(7) << endl;

    return 0;
}
