#include <iostream> 
#include <stack> 
#include <cstdio>
using namespace std; 
  
int main() 
{ 
    int t;
    cin>>t;
    int buffer = 0;
    while(t--){
        stack<char> stack; 
        string str;
        if(buffer == 1)
            getline(cin, str);
        else{
            getline(cin, str);
            getline(cin, str);
        }
        int f =1 ;
        for(int i=0; i<str.length(); ++i){
            if(str[i]=='['||str[i]=='{'||str[i]=='(')
                stack.push(str[i]);
            else if(str[i] != '"'){
                if(!stack.empty()){
                    if(((stack.top()=='[') && (str[i]==']')) || ((stack.top()=='{') && (str[i]=='}')) || ((stack.top()=='(') && (str[i]==')')))
                        stack.pop();
                    else{
                        f=0;
                    }
                }else{
                    f=0;
                }
            }else{
                
            }
            if(!f)
                break;
        }
        
        if(stack.empty() && f)
            cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;
        if(buffer == 0)
            buffer++;
    }
    return 0;
}
