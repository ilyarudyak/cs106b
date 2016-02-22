//
// Created by Ilya Rudyak on 1/22/16.
//

#include <iostream>
#include "EditorBuffer.h"
using namespace std;

EditorBuffer::EditorBuffer() { }

EditorBuffer::~EditorBuffer() { }

/* ------------ commands -------------- */

/* 4 command to move cursor*/
void EditorBuffer::moveCursorForward() {
    if (!after.empty()) {
        before.push(after.top());
        after.pop();
    }

}

void EditorBuffer::moveCursorBackward() {
    if (!before.empty()) {
    after.push(before.top());
    before.pop();
    }
}

void EditorBuffer::moveCursorToStart() {
    while (!before.empty()) {
        moveCursorBackward();
    }
}

void EditorBuffer::moveCursorToEnd() {
    while (!after.empty()) {
        moveCursorForward();
    }
}

/* insert and delete */
void EditorBuffer::insertCharacter(char ch) {
    before.push(ch);
}

void EditorBuffer::deleteCharacter() {
    if (!after.empty()) {
        after.pop();
    }
}

/* ----------- getters -------------- */

string EditorBuffer::getText() {

    string res;
    int a_size = (int) after.size();
    moveCursorToStart();
    while (!after.empty()) {
        res += after.top();
        moveCursorForward();
    }
    for(int i = 0; i < a_size; i++) {
        moveCursorBackward();
    }
    return res;
}

int EditorBuffer::getCursor() {
    return (int) before.size();
}






























