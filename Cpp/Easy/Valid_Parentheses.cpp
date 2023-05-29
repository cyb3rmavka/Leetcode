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
