//
//  main.cpp
//  AssignOperatorOverloading
//
//  Created by bsarvan on 02/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;
class Value {
    int a, b;
    float c;
public:
    Value(int aa = 0, int bb = 0, float cc = 0.0)
    : a(aa), b(bb), c(cc) {}
    Value& operator=(const Value& rv) {
        cout<<"Assignment operator called"<<endl;
        a = rv.a;
        b = rv.b;
        c = rv.c;
        return *this;
    }
    
    Value(const Value& v) {
        cout<<"In Copy Constructor"<<endl;
        a = v.a;
        b = v.b;
        c = v.c;
    }
    
    friend ostream&
    operator<<(ostream& os, const Value& rv) {
        requires( rv.a!= 2,"Should be one!!");
        return os << "a = " << rv.a << ", b = " << rv.b << ", c = " << rv.c;
    } };
int main() {
    Value a, b(1, 2, 3.3);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    a = b;
    cout << "a after assignment: " << a << endl;
    
    Value e(2,4,6);
    Value d = e;
    
    cout << "d after assignment: " << d << endl;
    
    
}

