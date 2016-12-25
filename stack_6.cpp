// postfix using stack
// input 23 3 +
//output 26


#include<iostream>
#include<stack>
#include<string.h>
#include<cstdio>
using namespace std;

bool isNum(char );

bool isOperator(char);

int calculate(int,int,char);

int postfix(char* a){

    stack<int> s;

    for(int i=0;i<strlen(a);i++){

            if(a[i]==',' || a[i]==' ') continue;

            else if(isNum(a[i])){

                    int operand=0;
                    while(i<strlen(a)&&isNum(a[i]))
                    {
                        operand=(operand*10)+(a[i] - 48);
                        i++;
                    }

                    s.push(operand);
                    i--;
                    cout<< "push "<<s.top()<<endl;

            }
            else if(isOperator(a[i])){
                int op1=s.top(); s.pop();
                int op2=s.top(); s.pop();

                int result = calculate(op1,op2,a[i]);
                s.push(result);
            }

    }
    return s.top();
}

int main(){
    char a[20];
    cout << "Enter your string ";
    fgets(a,20,stdin);
    int ret = postfix(a);
    cout<<"Answer is : "<<ret;
    return 0;
}

bool isNum(char a){
    if(a>='0'&&a<='9')
        return true;
    else
        return false;
}

bool isOperator(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/') return true;
    else
        return false;
}

int calculate(int op1,int op2,char oprt){
    if(oprt=='+') return op1+op2;
    else if(oprt=='-') return op2-op1;
    else if(oprt=='*') return op1*op2;
    else if(oprt=='/') return op1/op2;
}
