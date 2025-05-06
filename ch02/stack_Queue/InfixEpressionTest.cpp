#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <stdexcept>
using namespace std;

const int MAXSIZE = 1000;

// ===== 自定义栈结构 =====
template<typename T>
struct Stack {
    T data[MAXSIZE];
    int top = -1;

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAXSIZE - 1; }

    void push(T val) {
        if (isFull()) throw runtime_error("栈溢出");
        data[++top] = val;
    }

    T pop() {
        if (isEmpty()) throw runtime_error("栈为空");
        return data[top--];
    }

    T peek() {
        if (isEmpty()) throw runtime_error("栈为空");
        return data[top];
    }
};

// ===== 运算符优先级 =====
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ===== 运算执行 =====
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

// ===== 运算处理函数 =====
void process(Stack<double>& values, Stack<char>& ops) {
    if (values.top < 1) throw runtime_error("表达式格式错误");
    double b = values.pop();
    double a = values.pop();
    char op = ops.pop();
    values.push(applyOp(a, b, op));
}

// ===== 表达式求值主函数 =====
double evaluate(const string& expr) {
    Stack<double> values;
    Stack<char> ops;
    int i = 0;

    while (i < expr.length()) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        // 数字或小数点
        if (isdigit(expr[i]) || expr[i] == '.') {
            string numStr;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                numStr += expr[i++];
            }
            values.push(stod(numStr));
        }
        // 左括号
        else if (expr[i] == '(') {
            ops.push(expr[i]);
            i++;
        }
        // 右括号
        else if (expr[i] == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                process(values, ops);
            }
            if (!ops.isEmpty() && ops.peek() == '(')
                ops.pop();
            else
                throw runtime_error("括号不匹配");
            i++;
        }
        // 运算符
        else if (strchr("+-*/%^", expr[i])) {
            char curOp = expr[i];
            while (!ops.isEmpty() && ops.peek() != '(' &&
                   (precedence(ops.peek()) > precedence(curOp) ||
                    (precedence(ops.peek()) == precedence(curOp) && curOp != '^'))) {
                process(values, ops);
            }
            ops.push(curOp);
            i++;
        }
        else {
            throw runtime_error(string("非法字符：") + expr[i]);
        }
    }

    while (!ops.isEmpty()) {
        process(values, ops);
    }

    if (values.top != 0) throw runtime_error("表达式格式不正确");

    return values.pop();
}

// ===== 主函数测试 =====
int main() {
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
