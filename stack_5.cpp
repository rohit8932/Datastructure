// balanced parenthesis
//input [(afdf)]
//output balanced


#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
bool check(char a,char b){
    if(a=='(' && b==')') return true;
    else if(a=='{' && b=='}') return true;
    else if(a=='[' && b==']') return true;
    return false;
}
bool checkBalance(char *a){
    stack<char> s;
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='(' || a[i]=='{' || a[i]=='['){
                    s.push(a[i]);
                    cout<<"push "<<s.top()<<endl;
           }

       else if(a[i]==')' || a[i]=='}' || a[i]==']'){
                if(s.empty() || !check(s.top(),a[i])){
                    return false;
                }
                else
                {
                    s.pop();

                }

           }

    }
    s.empty()? true : false;

}

int main(){
    char a[20]; bool ret;
    cout<<"Enter The String";
    cin>>a;
    ret=checkBalance(a);
    if(ret)
        cout<<"Balanced ";
    else
        cout<<"Unbalanced ";

}
