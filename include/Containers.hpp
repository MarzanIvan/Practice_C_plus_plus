#pragma once

template <class TypeItem>
struct Item {
    Item *NextItem;
    TypeItem *CurrectObject;
    Item *PreviousItem;
    Item(TypeItem *ObjectToContain = nullptr) {
        CurrectObject = ObjectToContain;
        NextItem = PreviousItem = nullptr;
    }
};

template <class TypeItems>
class Container {
protected:
    Item<TypeItems> *StartElement;
    Item<TypeItems> *EndElement;
    unsigned int AmountItems;
public:
    Container( TypeItems *ObjectToContain = nullptr ) {
        StartElement = new Item<TypeItems>(ObjectToContain);
        EndElement = StartElement;
        if (!ObjectToContain) {
            AmountItems = 0;
        } else {
            AmountItems = 1;
        }
    }
    Item<TypeItems> *Container::operator[]( unsigned int IndexItem ) {
        TypeItems ItemToGet = ;
        for ( unsigned int i = 0; i < IndexItem; i++ ) {
            
        }
    }

};
