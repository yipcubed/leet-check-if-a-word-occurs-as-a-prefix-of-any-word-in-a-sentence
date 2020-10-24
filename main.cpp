#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/add-strings/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  bool isPre(string &searchWord, string &sentence, int start) {
    if (start + searchWord.length() > sentence.length())
      return false;
    for (int i = 0; i < searchWord.length(); i++) {
      if (searchWord[i] != sentence[start + i])
        return false;
    }
    return true;
  }

  int isPrefixOfWord(string sentence, string searchWord) {
    if (isPre(searchWord, sentence, 0))
      return 1;
    int count = 2;
    int found = sentence.find(" ");
    while (found != string::npos) {
      if (isPre(searchWord, sentence, found + 1))
        return count;
      count++;
      found = sentence.find(" ", found + 1);
    }
    return -1;
  }
};

void test1() { // test
  string sentence = "i am tired";
  string searchWord = "you";
  cout << "-1 ? " << Solution().isPrefixOfWord(sentence, searchWord) << endl;
  sentence = "i use triple pillow";
  searchWord = "pill";
  cout << "4 ? " << Solution().isPrefixOfWord(sentence, searchWord) << endl;
  sentence = "hello from the other side";
  searchWord = "they";
  cout << "-1 ? " << Solution().isPrefixOfWord(sentence, searchWord) << endl;
}

void test2() {}

void test3() {}