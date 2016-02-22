#include <iostream>
#include "EditorBuffer.h"
using namespace std;

/* just create an empty array
 * with initial capacity*/
EditorBuffer::EditorBuffer() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    length = 0;
    cursor = 0;
}

EditorBuffer::~EditorBuffer() {
    delete[] array;
}

/* ------------ commands -------------- */

/* 4 command to move cursor*/
void EditorBuffer::moveCursorForward() {
    if (cursor < length) cursor++;
}

void EditorBuffer::moveCursorBackward() {
    if (cursor > 0) cursor--;
}

void EditorBuffer::moveCursorToStart() {
    cursor = 0;
}

void EditorBuffer::moveCursorToEnd() {
    cursor = length;
}

/* insert and delete */
void EditorBuffer::insertCharacter(char ch) {
    if (length == capacity) expandCapacity();
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch;
    length++;
    cursor++;
}

void EditorBuffer::deleteCharacter() {
    if (cursor < length) {
        for (int i = cursor+1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;
    }
}

/* ----------- getters -------------- */

string EditorBuffer::getText() const {
    return string(array, (unsigned long)length);
}

int EditorBuffer::getCursor() const {
    return cursor;
}

void EditorBuffer::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}











