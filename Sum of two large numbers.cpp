/**

Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.


Example 1:

Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.
Example 2:

Input:
X = "2500", Y = "23"
Output:
2523
Explanation:
The sum of 2500 and 23 is 2523.


**/
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        int xLength = X.length();
        int yLength = Y.length();
        
        if(xLength < yLength) {
            string tmp = X;
            X = Y;
            Y = tmp;
        }
        
        xLength = X.length();
        yLength = Y.length();
        
        int xIndex = xLength-1;
        int yIndex = yLength-1;
        
        int carry = 0;
        
        while(xIndex>-1)  
        {
            if(yIndex>-1) 
            {
                
                int sum = ((X[xIndex]-'0') + carry + (Y[yIndex]-'0')); 
                carry = (sum/10)%10;
                X[xIndex] = ((sum%10)+'0');
                if(xIndex==0) {
                    if(carry>0) {
                        string s = to_string(carry);
                        X = s+X;
                        // cout << carry;
                    }
                }
                yIndex--;
            }
            else
            {
                int sum = ((X[xIndex]-'0') + carry);
                carry = (sum/10)%10;
                X[xIndex] = ((sum%10)+'0');
                if(xIndex==0){
                    if(carry>0) {
                        string s = to_string(carry);
                        X = s+X;
                        // cout << carry;
                    }
                }
            }
            
            
            xIndex--;
        }
        char k[10001];
        int kIndex = 0;
        int f = 0;
        for(int i=0;i<X.length();i++)
        {
            if((X[i]-'0')>0) f = 1;
            if(f==1) {
                k[kIndex++] = X[i];
            }
        }
        
        if(kIndex==0) k[kIndex++] = '0'; 
        
        k[kIndex] = '\0';
        X = k;
        return X;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends
