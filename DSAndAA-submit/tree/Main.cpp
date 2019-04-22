//
// Created by Monkey on 2018/12/20.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<char> container;
    string data = "abc1ba";
    int length = data.length();
    for (int i = 0; i < length / 2; i++) {
        container.push(data[i]);
    }
    for (int j = length / 2 + length % 2; j < length; ++j) {
        if (container.top() != data[j]) {
            cout << "no" << endl;
            return 0;
        }
        container.pop();
    }
    cout << "yes\n" << endl;
    return 0;

}

