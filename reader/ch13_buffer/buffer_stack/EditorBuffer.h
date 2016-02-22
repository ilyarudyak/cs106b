//
// Created by Ilya Rudyak on 1/22/16.
//

#ifndef BUFFER_STACK_EDITORBUFFER_H
#define BUFFER_STACK_EDITORBUFFER_H

#include <string>
#include <stack>
using namespace std;

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

    string getText();
    int getCursor();


private:
    stack<char> before;
    stack<char> after;
};


#endif //BUFFER_STACK_EDITORBUFFER_H
