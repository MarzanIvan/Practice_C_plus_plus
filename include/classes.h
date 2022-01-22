#pragma once

#include <iostream>

using namespace std;

template <class type> void GenerateValue( type &Value ) {
    Value = rand() % 100;
}

int GenerateValue() {
    return rand() % 100;
}