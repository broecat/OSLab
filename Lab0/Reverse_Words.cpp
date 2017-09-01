#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

int main() {
	// your code goes here
    int N;
    cin>>N;
    string in;
    getline(cin,in);
    for(int i=1;i<=N;i++)
    {
        stack<string> st;
        getline(cin,in);
        stringstream ss;
        ss.str(in);
        string temp;
        while(getline(ss,temp,' ')){
            st.push(temp);
        }
        bool first = true;
        cout<<"Case #"<<i<<": ";
        while(!st.empty()){
            if(first){
                cout<<st.top();
                first = false;
            }
            else{
                cout<<" "<<st.top();
            }
            st.pop();
        }
        cout<<"\n";   
    }
	return 0;
}