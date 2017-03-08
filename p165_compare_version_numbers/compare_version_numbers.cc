/* Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * You may assume that the version strings are non-empty and
 * contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int compareVersion(string version1, string version2) {
        return compareVersion(version1, 0, version2, 0);
    }

    int compareVersion(const string& version1, uint32_t start1,
                       const string& version2, uint32_t start2) {
        auto getVersionNum = [](const string& version, uint32_t& start)->int {
            int v = 0;
            while(start < version.size()) {
                if (version[start] == '.') {
                    break;
                }
                v = v * 10 + version[start] - '0';
                ++ start;
            }
            return v;
        };
        int v1 = getVersionNum(version1, start1);
        int v2 = getVersionNum(version2, start2);
        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        } else {
            if (start1 >= version1.size() && start2 >= version2.size()) {
                return 0;
            } else {
                return compareVersion(version1, start1+1, version2, start2+1);
            }
        }
    }
};

int main() {
    Solution obj;
    cout << obj.compareVersion("1.0", "1") << endl;
    cout << obj.compareVersion("3.1", "2.6") << endl;
    cout << obj.compareVersion("2.7", "4.1") << endl;
    cout << obj.compareVersion("2.7", "2.7") << endl;
    cout << obj.compareVersion("2.7", "2.7.1") << endl;
    cout << obj.compareVersion("2.7.1.2", "2.7.1") << endl;
    return 0;
}
