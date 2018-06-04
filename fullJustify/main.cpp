//
//  main.cpp
//  fullJustify
//
//  Created by bsarvan on 02/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string> words, int L)
{
    vector<string> res;
    int k = 0, l = 0;
    for (int i = 0; i < words.size(); i += k) {
        for (k = l = 0; i + k < words.size() && l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        
        cout<<"Line Size - "<<l<<",k - "<<k<<endl;
        string tmp = words[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= words.size()) {
                tmp += " ";
            }
            else {
                tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                cout<<tmp<<endl;
            }
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to Justify the text"<<endl;
    vector<string> A = {"This", "is", "an", "example", "of", "text", "justification."};
    
    vector<string> r = fullJustify(A, 16);
    
    for(auto c:r){
        cout<<c<<endl;
    }
    return 0;
}
