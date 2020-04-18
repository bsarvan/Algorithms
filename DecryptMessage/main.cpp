/*
 An infamous gang of cyber criminals named “The Gray Cyber Mob”, which is behind many hacking attacks and drug trafficking, has recently become a target for the FBI. After intercepting some of their messages, which looked like complete nonsense, the agency learned that they indeed encrypt their messages, and studied their method of encryption.
 
 Their messages consist of lowercase latin letters only, and every word is encrypted separately as follows:
 
 Convert every letter to its ASCII value. Add 1 to the first letter, and then for every letter from the second one to the last one, add the value of the previous letter. Subtract 26 from every letter until it is in the range of lowercase letters a-z in ASCII. Convert the values back to letters.
 
 For instance, to encrypt the word “crime”
 
 Decrypted message:    c    r    i    m    e
 Step 1:    99    114    105    109    101
 Step 2:    100    214    319    428    529
 Step 3:    100    110    111    116    113
 Encrypted message:    d    n    o    t    q
 
 
 */



#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string decrypt( const string& word )
{
    string result;
    
    result.insert(result.begin(), char(int(word[0]) - 1));
    
    for (int i = 1; i<word.size(); i++) {
        int prev = int(word[i-1]);
        int curr = int(word[i]);
        
        cout<<"Current - "<<curr<<", Prev - "<<prev<<endl;
        
        int val = curr - prev;
        while (val < 99) {
            curr+=26;
            val = curr - prev;
        }
        cout<<"Decrypted - "<<val<<endl;
        result.insert(result.end(),char(val));
        
    }
    
    return result;
}

int main() {
    
    string res = decrypt("dnotq");
    cout<<res<<endl;
    return 0;
}
