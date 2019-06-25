/* Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names.
 * The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
 * 
 * Example 1:
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory name.
 * Example 2:
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
 * Example 3:
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 * Example 4:
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * Example 5:
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * Example 6:
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 */

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
        deque<string> simple_path;
        string dirname;
        for (unsigned int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                // a potential new dirname
                if (dirname.size() > 0) {
                    if (dirname == ".") {
                        // nothing to do
                    } else if (dirname == "..") {
                        // go up a level
                        if (simple_path.size() > 0) {
                            simple_path.pop_back();
                        }
                    } else {
                        // go down a level
                        simple_path.push_back(dirname);
                    }
                }
                dirname.clear();
            } else {
                dirname.push_back(path[i]);
            }
        }
        // constrct simplified path
        string res_path;
        while (simple_path.size() > 0) {
            res_path.push_back('/');
            res_path.append(simple_path.front());
            simple_path.pop_front();
        }
        if (res_path.size() > 0) {
            return res_path;
        } else {
            return "/";
        }
    }
};

int main() {
    Solution obj;
    auto run = [&obj](const string& path)->void {
        std::cout << obj.simplifyPath(path) << std::endl;
    };
    run("/a/./b/../../c/");
    run("/a/../../b/../c//.//");
    run("/a//b////c/d//././/..");
    return 0;
}
