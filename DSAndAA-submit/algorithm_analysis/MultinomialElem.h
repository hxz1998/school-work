/**
 * Created by Xiaozhong on 2018/12/3.
 * Copyright (c) 2018/12/3 Xiaozhong. All rights reserved.
 *
 * 构成列表的基础元素，
 *
 * ----------
 * |index   | 当前元素的下标
 * |data    | 数据域
 * |next*   | 指向下一个元素的指针
 * ----------
 */

#ifndef DSANDAA_MULTINOMIALELEM_H
#define DSANDAA_MULTINOMIALELEM_H


class MultinomialElem {
private:
    int _index;
    int _data;
    MultinomialElem *_next;
public:

    MultinomialElem() {
        _index = 0;
        _data = 0;
        _next = nullptr;
    }

    MultinomialElem(int index, int data) {
        _index = index;
        _data = data;
    }

    MultinomialElem(int index, int data, MultinomialElem *next) {
        _index = index;
        _data = data;
        _next = next;
    }

    int get_index() {
        return _index;
    }

    int get_data() {
        return _data;
    }

    void set_next(MultinomialElem *next) {
        _next = next;
    }

    MultinomialElem *get_next() {
        return _next;
    }
};


#endif //DSANDAA_MULTINOMIALELEM_H
