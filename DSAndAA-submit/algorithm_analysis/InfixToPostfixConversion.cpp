/**
 * Created by Xiaozhong on 2018/12/5.
 * Copyright (c) 2018/12/5 Xiaozhong. All rights reserved.
 *
 * Input:   3+5*7+2
 * Postfix: 3 5 7 * 2 + +
 * The result is :40
 */

#include <stack>
#include <string>
#include <iostream>

using namespace std;

/**
 * 判断是否是操作符的辅助方法
 * @param c
 * @return
 */
bool is_operator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * 根据操作符种类判断操作符优先级，最高为2， 最低为1， 异常为-1
 * @param c
 * @return
 */
int priority(const char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return -1;
}

int main() {
    string data;
    cin >> data;
    stack<char> operator_container;
    stack<char> postfix_container;

    for (int i = 0; i < data.length(); i++) {
        //是一个操作数，直接打印
        if (!is_operator(data[i])) {
            postfix_container.push(data[i]);
            continue;
        }

        //是一个符号，进行下面的操作
        if (operator_container.empty()) {
            operator_container.push(data[i]);
        } else if (priority(operator_container.top()) >= priority(data[i])) {
            postfix_container.push(operator_container.top());
            operator_container.pop();
            operator_container.push(data[i]);
        } else {
            operator_container.push(data[i]);
        }
    }

    //将后缀表达式存入待计算的栈中
    while (!operator_container.empty()) {
        postfix_container.push(operator_container.top());
        operator_container.pop();
    }

    //反转内容
    stack<char> temp;
    while (!postfix_container.empty()) {
        temp.push(postfix_container.top());
        postfix_container.pop();
    }
    postfix_container.swap(temp);

    int result = 0;
    stack<int> operand_container;
    //运算
    while (!postfix_container.empty()) {
        if (!is_operator(postfix_container.top())) {
            //说明是操作数，直接压进栈中，等待操作符出现
            operand_container.push(postfix_container.top() - 48);
            postfix_container.pop();
        } else {
            int operand_1 = operand_container.top();
            operand_container.pop();
            int operand_2 = operand_container.top();
            operand_container.pop();
            int temp_result = 0;
            //说明是操作符，那么进行弹出两个操作数进行运算
            if (postfix_container.top() == '+') {
                temp_result = operand_1 + operand_2;
            } else if (postfix_container.top() == '-') {
                temp_result = operand_2 - operand_1;
            } else if (postfix_container.top() == '*') {
                temp_result = operand_1 * operand_2;
            } else {
                temp_result = operand_1 / operand_2;
            }
            result = temp_result;
            operand_container.push(result);
            postfix_container.pop();
        }
    }
    cout << "The result is :" << result << endl;

    return 0;
}
