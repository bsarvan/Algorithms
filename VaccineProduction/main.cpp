//
//  main.cpp
//  VaccineProduction
//
//  Created by Bharat Sarvan on 07/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int ComputeDays(int D1, int V1, int D2, int V2, int P) {
    
    int days = 1;
    int vaccines = 0;
    int vac1 = 0;
    int vac2 = 0;
    
    if (D1 == D2) {
        while(vaccines < P) {
            vaccines = (V1 + V2)*days;
            days++;
            cout<<vaccines<<" "<<days<<endl;
        }
        days--;
        
        if (D1 > 1) {
            days += D1 - 1;
        }
        
    } else {
        
        if (D2 < D1) {
            swap(D1, D2);
            swap(V1, V2);
        }

        int diff = D2 - D1;
        
        for (int i = 1; i <= diff; i++) {
            vac1 = V1*i;
            
            if (vac1 >= P) {
                return D1 + i - 1;
            }
        }
        
        vaccines = vac1;
        
        while(vaccines < P) {
            vac2 = (V1 + V2)*days;
            vaccines = vac1 + vac2;
            days++;
        }
        days--;
        
        days += D2 - 1;
    }
      
    return days;
}

int main(int argc, const char * argv[]) {

    int D1, D2, V1, V2 = 0;
    int P = 0;
    
    cin>>D1>>V1>>D2>>V2>>P;

    int result = ComputeDays(D1, V1, D2, V2, P);
    cout<<result<<endl;
    return 0;
}
