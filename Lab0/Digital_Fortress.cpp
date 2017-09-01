#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Calculate squares up to 100
    int arr[101];
    for(int i =1;i<=100;i++)
    {
        arr[i] = i*i;
    }


    int T;
    cin>>T;
    string in;
    getline(cin,in);
    while(T--)
    {
        getline(cin,in);
        bool valid = false;
        int num = 0;
        
        for(int i=1;i<=100;i++)
        {
            if(in.length()==arr[i]){valid = true;num = i;}
        }
        if(valid){
            for(int i=0;i<num;i++)
            {
                for(int k=0;k<num;k++){
                    cout<<in[k*num+i];
                }
            }
            cout<<"\n";

        }
        else{
            cout<<"INVALID\n";
        }
    }
	return 0;
}