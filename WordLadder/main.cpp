//
//  main.cpp
//  WordLadder
//
//  Created by bsarvan on 13/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isAdjacent(string a, string b) {
    size_t l1 = a.size();
    size_t l2 = b.size();
    
    if (l1 != l2) {
        return false;
    }
    
    int diffCount = 0;
    for (int i = 0; i < l1; i++ ) {
        if (a[i]!=b[i])
            diffCount++;
        
        if (diffCount > 1)
            return false;
    }
    
    return true;
    
//    if (diffCount == 1)
//        return true;
//    else
//        return false;
}

int WordLadderLength(string beginWord, string endWord, vector<string> wordList) {
    queue<pair<string, int>> Q;
    pair<string, int> p;
    
    pair<string, int> item = {beginWord, 1};
    Q.push(item);
    
    while(!Q.empty()) {
        pair<string, int> item = Q.front();
        Q.pop();
        
       // cout<<"Item Popped - "<<item.first<<endl;
        
        vector<string> :: iterator it;
        
        for (it = wordList.begin(); it != wordList.end(); it++) {
            string temp = *it;
            
            cout<<"Temp - "<<temp<<", Item Popped - "<<item.first<<endl;
            //Erase any letters in the list which are same as the one
            //for which adjacent word is been searched for.
            if (temp == item.first) {
                wordList.erase(it);
                cout<<"Continuing"<<endl;
                continue;
            }
            
            if (isAdjacent(item.first, temp)) {
                cout<<"Adjacent word - "<<*it<<endl;
                p = make_pair(temp, item.second + 1);
                Q.push(p);
                wordList.erase(it);
                
                if (temp == endWord) {
                    return p.second;
                }
            }
        }
        
    }
    
    return 0;
}

using ll = int;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, ll>> q;
    q.push({beginWord, 0});

    unordered_set<string> s;
    unordered_map<string, bool> vis;
    for (auto &word : wordList) {
        s.insert(word);
    }

    while (!q.empty()) {
        auto tp = q.front();

        if (tp.first == endWord) {
            return tp.second + 1;
        }
        
        q.pop();

        if (vis[tp.first]) continue;
        vis[tp.first] = 1;

        for (int i = 0; i < 26; ++i) {
            char c = 'a' + i;
            for (int j = 0; j < tp.first.size(); ++j) {
                string &temp = tp.first;
                char orig = temp[j];
                temp[j] = c;
                if (s.find(temp) != s.end()) q.push({temp, tp.second + 1});
                temp[j] = orig;
            }
        }
    }

    return 0;
}

int TransformString(vector<string> D, const string S, const string T) {
    struct StringWithDistance {
        string candidate_string;
        int distance;
    };
    
    queue<StringWithDistance> Q;
    auto iter = find(D.begin(), D.end(), S);
    if (iter != D.end())
        D.erase(iter);
    
    Q.emplace(StringWithDistance{S,0});
    
    while(!Q.empty()) {
        StringWithDistance f(Q.front());
        
        if (f.candidate_string == T)
            return f.distance;
        
        string str = f.candidate_string;
        for (int i = 0; i < str.size(); i++) {
            //cout<<"Candidate String - "<<str<<endl;
            for (int j = 0; j < 26; j++) {
                str[i] = 'a' + j;
                //cout<<"Partial String - "<<str<<endl;
                
                auto it = find(D.begin(), D.end(), str);
                
                if (it != D.end()) {
                    D.erase(it);
                    Q.emplace(StringWithDistance{str, f.distance + 1});
                }
            }
            str[i] = f.candidate_string[i];
        }
        
        Q.pop();
    }
    
    return -1;
}


int main() {
   vector<string> WordList = {"hot","dot", "dog", "lot" , "log", "cog"};
   string startWord = "hit";
   string endWord = "cog";
    
//    vector<string> WordList = {"a","b","c"};
//    string startWord = "a";
//    string endWord = "c";
    
    
//    int len = WordLadderLength(startWord, endWord, WordList);
    int l = TransformString(WordList, startWord, endWord);
    
//    cout<<"Length from Function WordLadderLength - "<<len<<endl;
    cout<<"Length from Function TransformString - "<<l<<endl;
    
    return 0;
}
