/* Given two words (beginWord and endWord), and a dictionary's word list,
 * find all shortest transformation sequence(s) from beginWord to endWord, such that:
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list.
 * Note that beginWord is not a transformed word.
 * For example,
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Return
 *   [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>  // hash table
using namespace std;

class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        clock_t begin_time = clock();

        unordered_set<string> dict(wordList.begin(), wordList.end());
        // step 1: BFS to find minimum length
        // build a list of word dict along the way
        vector<unordered_set<string>> dict_path;
        dict_path.push_back(dict);
        // BFS
        int min_length = BFS(beginWord, endWord, dict, dict_path);
        clock_t bfs_end_time = clock();
        //cout << "BFS done; min-length=" << min_length << "; time=" << double(bfs_end_time - begin_time) << endl;

        // step 2: DFS to find path
        vector<vector<string>> all_sols;
        if (min_length > 0) {
            vector<string> sol(min_length, "");
            sol[0] = beginWord;
            int length = 1;
            DFS(all_sols, sol, length, min_length, endWord, dict_path);
        }
        clock_t dfs_end_time = clock();
        //cout << "DFS done; time=" << double(dfs_end_time - bfs_end_time) << endl;
        return all_sols;
    }

    void DFS(vector<vector<string>>& all_sols,
            vector<string>& sol,
            int& length,
            const int& min_length,
            const string& endWord,
            vector<unordered_set<string>>& dict_path)
    {
        const string& beginWord = sol[length-1];
        if (beginWord == endWord) {
            all_sols.push_back(sol);
            return;
        }
        if (length >= min_length) {
            // not a min-length solution
            return;
        }
        // DFS
        queue<string> word_queue;
        queue<string> back_queue;
        findWords(beginWord, dict_path[length-1], word_queue);
        while (!word_queue.empty()) {
            auto word = word_queue.front();
            word_queue.pop();
            back_queue.push(word);
            sol[length] = word;
            ++ length;
            DFS(all_sols, sol, length, min_length, endWord, dict_path);
            -- length;
        }
        while (!back_queue.empty()) {
            dict_path[length-1].insert(back_queue.front());
            back_queue.pop();
        }
    }

    int BFS(const string& beginWord,
            const string& endWord,
            unordered_set<string> dict,
            vector<unordered_set<string>>& dict_path)
    {
        queue<string> word_queue;
        // level-order BFS
        word_queue.push(beginWord);
        int num_next = 1;
        int num_cur = 0;
        int length = 1;
        while (num_next > 0) {
            //cout << "length=" << length << ", size=" << dict.size() << ", num=" << num_next << endl;
            num_cur = num_next;
            num_next = 0;
            while (num_cur > 0) {
                string word = word_queue.front();
                word_queue.pop();
                -- num_cur;
                if (word == endWord) {
                    //// sanity check
                    //for (uint32_t i = 0; i < dict_path.size(); ++i) {
                    //    cout << dict_path[i].size() << " ";
                    //}
                    //cout << endl;
                    return length;
                }
                num_next += findWords(word, dict, word_queue);
            }
            dict_path.push_back(dict);
            ++ length;
        }
        return 0;
    }

    int findWords(const string& word,
            unordered_set<string>& dict,
            queue<string>& words)
    {
        int num = 0;
        for (uint32_t i = 0; i < word.size(); ++i) {
            string new_word = word;
            for (uint32_t k = 0; k < 26; ++k) {
                new_word[i] = 'a' + k;
                if (word != new_word && dict.count(new_word)) {
                    words.push(new_word);
                    dict.erase(new_word);
                    ++ num;
                }
            }
        }
        return num;
    }
};

int main() {
    Solution obj;
    vector<string> wordList1({"hot","dot","dog","lot","log","cog"});
//    vector<string> wordList1({"hot","dot","dog","lot","log"});
    auto ans1 = obj.findLadders("hit", "cog", wordList1);
    for (auto &path : ans1) {
        for (auto &word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    vector<string> wordList2({"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes",\
            "ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot",\
            "bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip",\
            "fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie",\
            "sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob",\
            "ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far",\
            "mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay",\
            "vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam",\
            "pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat",\
            "fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar",\
            "kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom",\
            "vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar",\
            "cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla",\
            "auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit",\
            "maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis",\
            "hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who",\
            "bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe",\
            "hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe",\
            "our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun",\
            "try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan",\
            "lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur",\
            "sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt",\
            "lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte",\
            "sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant",\
            "net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob",\
            "way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac",\
            "baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob",\
            "hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala",\
            "ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her",\
            "nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay",\
            "toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax",\
            "jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi",\
            "hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp",\
            "ale","bud","gee","pin","dun","pat","ten","mob"});
    auto ans2 = obj.findLadders("cet", "ism", wordList2);
    for (auto &path : ans2) {
        for (auto &word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}


