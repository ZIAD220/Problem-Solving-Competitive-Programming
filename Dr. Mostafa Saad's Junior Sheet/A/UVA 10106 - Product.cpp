#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
    Key idea: Constraints are big, they dont fit in long long. 
              So, you need to multiply the two numbers using old school multiplication method.
	      Also, you can use BigIntegers if you're using Java.  
*/


int A[505];

void multiply(string X, string Y)
{
    int cnt = 0, n1 = X.length(), n2 = Y.length();
    for (int i = n1 - 1; i >= 0; i--)
    {
        int r = 0, idx = 504 - cnt;
     
	for (int j = n2 - 1; j >= 0; j--)
        {
            int p = (X[i] - '0') * (Y[j] - '0');
         
	    A[idx] += (p%10) + r;
           
	    int k = idx;
            while (A[k] >= 10){
                A[k - 1] += A[k] / 10, A[k] %= 10;
                k--;
            }
           
	    p /= 10, r = p, idx--;
        }
        if (r)
            A[idx] += r;
        
	idx = 504 - cnt;
        while (idx >= 0){
            if (A[idx] >= 10)
                A[idx] %= 10, A[idx - 1]++;
            idx--;
        }
        
	cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string X, Y, S1, S2;

    while(cin >> X >> Y){

        if (X[0] == '0' || Y[0] == '0')
        {
            cout << 0<<endl;
        }

        else
        {

            if (X.length() >= Y.length())
                S1 = X, S2 = Y;

            else if (X.length() < Y.length())
                S1 = Y, S2 = X;

            multiply(S2, S1);

            int idx = 0;
            for (int i = 0; i <= 504; i++){
                if (A[i]){
                    idx = i;
                    break;
                }
            }

            for (int i = idx; i <= 504; i++)
                cout << A[i];
            cout << endl;
        }

        memset(A, 0, sizeof(A));
    }
}
