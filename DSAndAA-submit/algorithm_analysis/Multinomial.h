/**
 * Created by Xiaozhong on 2018/12/3.
 * Copyright (c) 2018/12/3 Xiaozhong. All rights reserved.
 *
 * 链表的管理者，屏蔽链表自带的复杂性，提供方便的接口
 * 内部使用的元素为 MultinomialElem
 *
 * index:   0       1       2
 *          7*x^2 + 8 * x + 9   [7  8  9 ]
 *          6*x^2 + 0 * x + 8   [6  0  8 ]
 *          resut ->            [13 8  17]
 *
 * @see MultinomialElem
 */

#ifndef DSANDAA_MULTINOMIAL_H
#define DSANDAA_MULTINOMIAL_H

#include "MultinomialElem.h"

class Multinomial {
private:
    MultinomialElem *_head;
    MultinomialElem *_current_elem;
    int _length;
public:
    Multinomial(MultinomialElem *head) {
        _head = head;
        _current_elem = _head;
        _length = 0;
    }

    /**
     * 在多项式表达式末尾插入一个多项式元素，然后返回指向新插入元素的指针
     * @param elem 新插入的元素
     * @return ptr -> elem
     */
    MultinomialElem * put(MultinomialElem * elem);

    /**
     * 根据所需要的多项式的位数来获取所需的元素
     * @param index
     * @return 指定下标所指的元素
     */
    MultinomialElem * get(int index);

};


#endif //DSANDAA_MULTINOMIAL_H
