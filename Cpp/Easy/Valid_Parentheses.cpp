/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> symStack;
        for(int i = 0; i < s.size(); i++){
            if(!symStack.empty()){
                if(s[i] == ']' and symStack.top() == '['){
                    symStack.pop();
                } else if (s[i] == ')' and symStack.top() == '('){
                    symStack.pop();
                } else if (s[i] == '}' and symStack.top() == '{') {
                    symStack.pop();
                } else {
                    symStack.push(s[i]);
                }
            } else {
                symStack.push(s[i]);
            }
        }
        return symStack.empty();
    }
};
