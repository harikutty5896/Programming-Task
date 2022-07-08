#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool backspaceCompare(string s, string t) {
    stack<int> s1,s2;
    for(char c : s){
        if(c=='#'){
            if(!s1.empty()){
            s1.pop();
            }
        }
        else{
            s1.push(c);
        }
    }
    for(char c : t){
        if(c=='#'){
            if(!s2.empty()){
            s2.pop();
            }
        }
        else{
            s2.push(c);
        }
    }
    if(s1.size()!=s2.size())return false;
    while(!s1.empty() and !s2.empty()){
        if(s1.top()!=s2.top())return false;
        s1.pop();
        s2.pop();
    }
    return true;
}
