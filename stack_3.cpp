//reversal of string using stack (array)

#include<iostream>
#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;
void rvrse(char *c,int n){
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        s.push(c[i]);
    }
    for(int i=0;i<n;i++)
    {
        c[i]=s.top();
        s.pop();
    }
}
int main(){
    char c [20];
    cout<<"Enter the String\n";
    fgets(c,20,stdin);
    rvrse(c,strlen(c));
    cout<<"Reverse is : "<<c;

    //cout<<"Reverse is : "<<puts(c);

    return 0;
}
