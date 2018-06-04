//
//  main.cpp
//  validIPAddresses
//
//  Created by bsarvan on 06/03/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool Valid(string s){
    if(s.size() > 1 && s[0] == '0')return false;
    if((stoi(s) >= 0) && (stoi(s)<=255)){
        return true;
    }
    else{
        return false;
    }
}


vector<string> restoreIpAddresses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = (int)(A.length());
    vector <string> ans;
    if(l < 4 || l > 12)return ans;
    string temp;
    string first,second,third,fourth;
    for(int i = 1;i < 4;i++){
        first = A.substr(0,i);
        if(!Valid(first))continue;
        for(int j = 1;j < 4 && i+j < l;j++){
            second = A.substr(i,j);
            if(!Valid(second))continue;
            for(int k = 1;k < 4 && i+j+k < l;k++){
                third = A.substr(i+j,k);
                fourth = A.substr(i+j+k);
                if(Valid(third) && Valid(fourth)){
                    temp = first + "." + second + "."+third+"."+fourth;
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to list valid IP addresses from string"<<endl;
    vector<string> str_vec;
    str_vec = restoreIpAddresses("101231211223");
    
    for(int i=0;i<str_vec.size();i++){
        cout<<str_vec[i]<<endl;
    }
    return 0;
}
