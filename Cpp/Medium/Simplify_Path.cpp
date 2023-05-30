/* Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.*/

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> st;
        std::string temp = "";

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (temp == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else if (temp != "" && temp != ".") {
                    st.push(temp);
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }

        if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (temp != "" && temp != ".") {
            st.push(temp);
        }

        std::string simplifiedPath = "";
        while (!st.empty()) {
            simplifiedPath = "/" + st.top() + simplifiedPath;
            st.pop();
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }

};
