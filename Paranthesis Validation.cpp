#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string removeParanthesis(string s) {
        int n = s.length();
        stack<int> stk;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == ')')
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    s.erase(i,1);
                    i--;//here index value is decremented
                }
            }
            else if(s[i]=='(')
            {
                stk.push(i);
                
            }
        }
    int m=stk.size();
    if(!stk.empty()){
        while(m--)
        {
            s.erase(stk.top()-1,1);//here index value is decremented
        }
    }
    
    cout<<"STR :"<<s<<endl;
    return s;
    return 0;
}
int main()
{
    string expression;
    cin >> expression;
    if(!expression.empty())
        cout<< removeParanthesis(expression);
    else
        cout << "String is Empty";
    return 0;
}
