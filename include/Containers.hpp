#pragma once

#include <iostream>

using namespace std;

template <class TemplateType>
class Container {
protected:
    TemplateType *Objects;
    unsigned int AmountObjects;
public:

    Container( TemplateType Objects[], unsigned int AmountObjects );

    Container( const Container &ContainerToCopy );

    Container() {
        this->Objects = 0;
        this->AmountObjects = 0;
    }

    ~Container() {
        if (Objects) {
            if (AmountObjects == 1) {
                delete Objects;
            } else {
                delete[] Objects;
            }
        }
    }

    TemplateType &operator=( Container<TemplateType> &ObjectToCopy );

    TemplateType &operator[]( unsigned int Index );

    inline bool Is_Element_Exist( unsigned int Index );

    void AddElement( TemplateType &Object );

    void DeleteElement();

    void Clear();

    unsigned int GetSize() {
        return AmountObjects;
    }

};


template <class TemplateType>
Container<TemplateType>::Container( TemplateType Objects[], unsigned int AmountObjects ) {
    this->Objects = new TemplateType[AmountObjects];
    for (register unsigned int i = 0; i < AmountObjects; i++) {
        this->Objects[i] = Objects[i];
    }
    this->AmountObjects = AmountObjects; 
}

template <class TemplateType>
Container<TemplateType>::Container( const Container &ContainerToCopy ) {
    AmountObjects = ContainerToCopy.AmountObjects;
    if (AmountObjects) {
        Objects = new TemplateType[ContainerToCopy.AmountObjects];
    } else {
        Objects = 0;
        return;
    }
    for (register unsigned int i = 0; i < AmountObjects; i++) {
        Objects[i] = ContainerToCopy.Objects[i];
    }
}

template <class TemplateType>
TemplateType &Container<TemplateType>::operator=( Container<TemplateType> &ObjectToCopy ) {
    if (Objects) {
        if (AmountObjects == 1) {
            delete Objects;
        } else {
            delete[] Objects;
        }
        Objects = 0;
    }
    AmountObjects = ObjectToCopy.AmountObjects;
    if (ObjectToCopy.Objects) {
        Objects = new TemplateType[AmountObjects];
        for (register unsigned int i = 0; i < AmountObjects; i++ ) {
            Objects[i] = ObjectToCopy[i];
        }
    }
}

template <class TemplateType>
TemplateType &Container<TemplateType>::operator[]( unsigned int Index ) {
    try {
        if (Index >= AmountObjects) {
            throw (Index);
        }
        return Objects[Index];
    } catch ( unsigned int ErrorIndex ) {
        std::cerr << "The index " << ErrorIndex << " isn't belonged this collection\n";
        exit(1);
    }
}

template <class TemplateType>
inline bool Container<TemplateType>::Is_Element_Exist( unsigned int Index ) {
    if (Index < AmountObjects && Index >= 0 ) {
        return true;
    } 
    else {
        return false;
    }
}

template <class TemplateType>
void Container<TemplateType>::AddElement( TemplateType &Object ) {
    if (!Objects) {
        Objects = new TemplateType(Object);
        AmountObjects++;
        return;
    }
    TemplateType *NewListObjects = new TemplateType[AmountObjects + 1];
    for ( register unsigned int i = 0; i < AmountObjects; i++ ) {
        NewListObjects[i] = Objects[i];
    }
    if (AmountObjects == 1) {
        delete Objects;
    } else {
        delete[] Objects;
    }
    NewListObjects[AmountObjects] = Object;
    Objects = NewListObjects;
    AmountObjects++;
}

template <class TemplateType>
void Container<TemplateType>::DeleteElement() {
    if (!Objects) {
        return;
    }
    if (AmountObjects == 1) {
        AmountObjects--;
        delete Objects;
        Objects = 0;
        return;
    }
    TemplateType *NewList = new TemplateType[AmountObjects - 1];
    for ( register unsigned int i = 0; i < AmountObjects - 1; i++ ) {
        NewList[i] = Objects[i];
    }
    delete[] Objects;
    Objects = NewList;
}

template <class TemplateType>
void Container<TemplateType>::Clear() {
    if (!AmountObjects) {
        return;
    }
    if (AmountObjects == 1) {
        delete Objects;
    } else {
        delete[] Objects;
    }
    AmountObjects = 0;
}