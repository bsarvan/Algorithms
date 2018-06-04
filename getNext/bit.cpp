#include <iostream>

using namespace std;



int getNext(int n)
{
		int c = n;
		int c0 = 0;
		int c1 = 0;

		while(((c & 1) == 0) && (c!=0)) {
				c0++;
				c >>=1;
		}
		while(((c & 1) == 1) && (c!=0)) {
				c1++;
				cout<<c<<endl;
				c >>=1;
		}

		int p = c0 + c1;
    
        n |=1<<p;
        n &= ~((1<<p) - 1);
        n |= (1<<(c1-1)) - 1;
    
		return n;
}

int main()
{
		cout<<"Test program for bit manipulation"<<endl;

		int j = getNext(220);

		cout<<"Returned Number is - "<<j<<endl;

		return 0;
}
