#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <iostream>
using namespace std;
const int MAXSIZE = 1000;
//定义一个栈

template <typename T>
    
struct Stack{
    T data[MAXSIZE];
    int top=-1;

    bool isEmpty(){return top== -1;}
    bool isFull(){return top == MAXSIZE-1;}
    void push(T val){
        if(isFull()) 
        {
            cout<<"栈已满！"<<endl;
            return;
        }
        data[++top]=val;
    }
    T pop(){
        if (isEmpty()) throw runtime_error("栈为空");
        return data[top--];
    }
    T peek(){
        if (isEmpty()) throw runtime_error("栈为空");
        return data[top];
    }
};
//优先级
int pre(char op){
    if(op=='(') return 4;
    if(op=='^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 运算执行 
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("除以零错误");
            return a / b;
        case '%': 
            if (b == 0) throw runtime_error("除以零错误");
            return fmod(a, b);
        case '^': return pow(a, b);
        default: throw runtime_error("未知运算符");
    }
}
//运算处理
void process(Stack<double>& values,Stack<char>& ops){
    if(values.top<1)throw runtime_error("格式错误！");
    double b=values.pop(),a=values.pop();
    char op= ops.pop();
    values.push(applyOp(a,b,op));
}
bool isRightAssociative(char op) {
    return op == '^';
}

//表达式求值（栈）
double evaluate(const string &input){
    Stack <double> values;
    Stack <char> ops;
    int i=0;
    while (i<input.length()){
        if(isspace(input[i])){
            i++;
            continue;
        }
        //数字和小数点
        if(isdigit(input[i])||input[i] == '.'){
            string num;
            while(i<input.length()&&(isdigit(input[i])||input[i]=='.'))
            {
                num+=input[i++];
            }
            values.push(stod(num));
        }
        //左括号
        else if (input[i]=='('){
            ops.push(input[i]);
            i++;
        }
        //右括号
        else if (input[i]==')'){
            //弹栈，匹配左括号
            while(!ops.isEmpty()&&ops.peek()!='('){
                process(values,ops);
            }
            if (!ops.isEmpty() && ops.peek() == '(')
                ops.pop();
            else
                throw runtime_error("括号不匹配");
            i++;
        }
        //运算符
        else if (strchr("+-*/%^",input[i])){
            char op=input[i];
            // while(!ops.isEmpty()&&(pre(op)<=pre(ops.peek()))){
            //     process(values,ops);
            // }
            while (!ops.isEmpty() && (
                (isRightAssociative(op) && pre(op) < pre(ops.peek())) || 
                (!isRightAssociative(op) && pre(op) <= pre(ops.peek()))
            )) {
            process(values, ops);
        }
            ops.push(op);
            i++;
        }
    }
    while (!ops.isEmpty()) {
        process(values, ops);
    }

    if (values.top != 0) throw runtime_error("表达式格式不正确");

    return values.pop();
}

int main(){
    string expr;
    cout << "请输入表达式（支持 + - * / % ^ 和小数）：";
    getline(cin, expr);

    try {
        double result = evaluate(expr);
        cout << "结果为: " << result << endl;
    } catch (exception& e) {
        cout << "错误: " << e.what() << endl;
    }

    return 0;
}