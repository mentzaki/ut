/* 
 * File:   Container.cpp
 * Author: yew_mentzaki
 * 
 * Created on May 18, 2015, 8:33 PM
 */

#include <cstddef>
#include <GL/glut.h>

#include "../Keyboard.hpp"
#include "../Mouse.hpp"

#include "Container.hpp"

Container::Container() {
    transperent = true;
}

Container::Container(int x, int y, int w, int h) : Element(x, y, w, h) {
    transperent = true;
}

Container::Container(int x, int y, int w, int h, int align) : Element(x, y, w, h, align) {
    transperent = true;
}

Container::Container(const Container& orig) {
    transperent = true;
}

Container::~Container() {
    transperent = true;
}

bool Container::handleElement(Mouse* m, Keyboard* k) {
    if (!visible)return false;
    if (m->x >= getX() & m->x <= getX() + w & m->y >= getY() & m->y <= getY() + h) {
        for(int i = 64; i >= 0; i--){
            if(elements[i] != NULL && elements[i]->handleElement(m, k))
                    return true;
        }
        hovered(m);
        if (m->isLeftReleased){
            clicked(m);
            m->isLeftReleased = false;
        }
        return !transperent;
    }
    return false;
}

void Container::add(Element* e) {
    for (int i = 0; i < 64; i++) {
        if (elements[i] == NULL) {
            elements[i] = e;
            return;
        }
    }
}

void Container::remove(Element* e) {
    for (int i = 0; i < 64; i++) {
        if (elements[i] == e) {
            elements[i] = NULL;
            return;
        }
    }
}

void Container::render() {
    for (int i = 0; i < 64; i++) {
        if (elements[i] != NULL) {
            elements[i]->render();
            return;
        }
    }
}
