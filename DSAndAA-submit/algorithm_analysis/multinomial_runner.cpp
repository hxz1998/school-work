/**
 * Created by Xiaozhong on 2018/12/3.
 * Copyright (c) 2018/12/3 Xiaozhong. All rights reserved.
 */

#include "MultinomialElem.h"
#include "Multinomial.h"
#include <iostream>

using namespace std;

int main() {
    int multi1[] = {7, 8, 9};
    int multi2[] = {6, 0, 8};
    auto * head1 = new MultinomialElem;
    auto * head2 = new MultinomialElem;
    Multinomial list1(head1);
    Multinomial list2(head2);
    for (int i = 0; i < 3; ++i) {
        auto * elem1 = new MultinomialElem(i, multi1[i]);
        auto * elem2 = new MultinomialElem(i, multi2[i]);
        list1.put(elem1);
        list2.put(elem2);
    }

    cout << "[";
    for (int j = 0; j < 3; ++j) {
        cout << list1.get(j)->get_data() + list2.get(j)->get_data() << " ";
    }
    cout << "]";
}
