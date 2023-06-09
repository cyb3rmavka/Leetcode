//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

class Solution {
public:
  int firstUniqChar(std::string s) {
      ios_base::sync_with_stdio(false);
        cin.tie(NULL) ;
        int pos = 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[pos] == s[i] and i != pos){
                pos++;
                i = -1;
                continue;
            }
            if(pos == s.size()) return -1;
        }
        return pos;
    }
};
