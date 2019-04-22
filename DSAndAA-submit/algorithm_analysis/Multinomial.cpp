/**
 * Created by Xiaozhong on 2018/12/3.
 * Copyright (c) 2018/12/3 Xiaozhong. All rights reserved.
 */

#include "Multinomial.h"

MultinomialElem *Multinomial::put(MultinomialElem *elem) {
    _current_elem->set_next(elem);
    _current_elem = elem;
    _length++;
    return _current_elem;
}

MultinomialElem *Multinomial::get(int index) {
    MultinomialElem * iterator = _head;
    for (int i = 0; i <= index; ++i) {
        iterator = iterator->get_next();
    }
    return iterator;
}
