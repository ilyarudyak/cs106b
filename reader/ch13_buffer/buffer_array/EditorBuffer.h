//
// Created by Ilya Rudyak on 1/22/16.
//

#ifndef BUFFER_ARRAY_BUFFER_H
#define BUFFER_ARRAY_BUFFER_H

#include <string>

class EditorBuffer {

public:
    EditorBuffer();
    ~EditorBuffer();

    void moveCursorForward();
    void moveCursorBackward();

    void moveCursorToStart();
    void moveCursorToEnd();

    void insertCharacter(char ch);
    void deleteCharacter();

    std::string getText() const;
    int getCursor() const;

private:
    static const int INITIAL_CAPACITY = 10;

    char *array;
    int capacity;
    int length;
    int cursor;

    void expandCapacity();

};


#endif //BUFFER_ARRAY_BUFFER_H





















