/*
647. Palindromic Substrings
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

//CODE

#include <string>
class Solution {
public:
    int count;
    void countPalin(std::string &s, int i, int j){
        while (i >= 0 && j < s.length() && s[i] == s[j]){
            count += 1;
            i -= 1;
            j += 1;
        }
    }
    int countSubstrings(std::string s) {
        count = 0;
        for (int i = 0; i < s.length(); ++i){
            countPalin(s, i, i);
            countPalin(s, i, i+1);
        }
        return count;
    }
};