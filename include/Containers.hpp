#pragma once

#include <iostream>

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

    unsigned int GetSize() {
        return AmountObjects;
    }

};


template <class TemplateType>
Container<TemplateType>::Container( TemplateType Objects[], unsigned int AmountObjects ) {
    TemplateType *CopyObjects = new TemplateType[AmountObjects];
    for (register unsigned int i = 0; i < AmountObjects; i++) {
        CopyObjects[i] = Objects[i];
    }
    this->AmountObjects = AmountObjects;
    this->Objects = CopyObjects;  
}

template <class TemplateType>
Container<TemplateType>::Container( const Container &ContainerToCopy ) {
    Objects = new TemplateType[ContainerToCopy.AmountObjects];
    AmountObjects = ContainerToCopy.AmountObjects;
    for (register unsigned int i = 0; i < AmountObjects; i++) {
        Objects[i] = ContainerToCopy.Objects[i];
    }
}

template <class TemplateType>
TemplateType &Container<TemplateType>::operator=( Container<TemplateType> &ObjectToCopy ) {
    AmountObjects = ObjectToCopy.AmountObjects;
    if (Objects) {
        delete[] Objects;
        Objects = 0;
    }
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
    if (AmountObjects != 1) {
        delete[] Objects;
    }
    NewListObjects[AmountObjects] = Object;
    Objects = NewListObjects;
    AmountObjects++;
}

template <class TemplateType>
void Container<TemplateType>::DeleteElement() {
    AmountObjects--;
    delete &Objects[AmountObjects];
    if (AmountObjects == 0) {
        Objects = 0;
    }
}