//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> v) 
    {
        int x= 0;
        for(auto &i: v) {
            x=x^i;
        }
        
        int temp =x , pos =0, bit =0 ;
        
        while(bit!=1) {
            bit =temp&1;
            pos++;
            temp=temp>>1;
        }
        int nx=0;
        for(int i =0 ; i< v.size() ; i++) {
            int chk = v[i]&(1<<(pos-1));
            
            if(chk != 0) {
                nx=nx^v[i];
            }
        }
        x= x^nx; 
        
        int mi =min(x, nx) , mx =max(x , nx);
        
        return {mi,mx};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends