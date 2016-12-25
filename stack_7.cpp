// infix to postfix (without parenthesis )using stack

#include<iostream>
#include<stack>
#include<cstdio>
#include<string.h>
using namespace std;
bool checkOperand(char a){
    if(a>='a'&&a<='z')
        return true;
        else if(a>='0' && a<='9')
            return true;
    return false;
}

bool isOperator(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/')
        return true;
    return false;
}

bool isHighprec(char top, char curr){
    if(top=='*' && curr=='+') return true;
    else if (top=='*' && curr =='-') return true;
    else if (top=='/' && curr =='+') return true;
    else if (top=='/' && curr =='-') return true;

    return false;
}
void infixTopostfix(char a[]){
    stack<char> s;
    char result[20]="";                     // very important. it initializes array with empty
    int j=0;
    for(int i=0;i<strlen(a);i++){
        if(checkOperand(a[i])){
            result[j++]=a[i];
            cout <<result<<endl;

        }
        else if(isOperator(a[i])){
                if(!s.empty() && isHighprec(s.top(),a[i])){
                    while(!s.empty()){
                    result[j++]=s.top();
                    s.pop();
                    cout<< "curr > top "<<endl;
                    }
                }
                s.push(a[i]);

        }

    }
    while(!s.empty()){
        result[j++]=s.top();
        s.pop();

    }

    cout<< result;


}

int main(){
    char a[20];
    cout <<"Enter your Expression\n";
    fgets(a,20,stdin);
    infixTopostfix(a);


    return 0;
}
