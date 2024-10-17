/*
670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 108
*/

// CODE

#include <vector>
#include <queue>
class Solution {
public:
    int maximumSwap(int num) {
        std::vector<int> digits;
        std::priority_queue<int> pq;
        int digit;
        while (num > 0){
            digit = num % 10;
            num = (num - digit) / 10;
            digits.push_back(digit);
            pq.push(digit);
        }
        

        int maxDigit = pq.top();
        pq.pop();
        for (int i = digits.size()-1; i >= 0; --i){
            if (digits[i] != maxDigit){
                int temp = digits[i];
                auto it = find(digits.begin(), digits.end(), maxDigit);
                int index = it - digits.begin();
                digits[i] = digits[index];
                digits[index] = temp;
                break;
            }
            maxDigit = pq.top();
            pq.pop();
        }

        for (int i = digits.size()-1; i >= 0; --i){
            num += digits[i];
            num *= 10;
        }
        return num/10;
    }
};