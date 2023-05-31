/*
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.
*/

class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
        int64_t sum = 0;
        int temp = 0;

        for(int i = s.size()-1; i >= 0; --i){
            temp = int(s[i]);
            sum += shifts[i];
            temp = (temp + sum % 26 > 122) ? temp + sum % 26 - 26 : temp + sum % 26;

            s[i] = char(temp);
        }
        return s;
    }
};
