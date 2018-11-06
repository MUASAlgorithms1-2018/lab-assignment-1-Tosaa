//
// Created by Toni on 06.11.2018.
//

#ifndef LAB1_TONI_STACK_H
#define LAB1_TONI_STACK_H


class Toni_Stack {
private:
    int actualPosition = -1;
    char chararray[10];

public:

    int size() {
        return (actualPosition + 1);
    }

    void push(char c) {
        actualPosition += 1;
        chararray[actualPosition] = c;
    }

    char pop() {
        if (size() > 0) {
            char result = chararray[actualPosition];
            chararray[actualPosition] = '0';
            actualPosition -= 1;
            return result;
        }
        return '0';
    }
};


#endif //LAB1_TONI_STACK_H
