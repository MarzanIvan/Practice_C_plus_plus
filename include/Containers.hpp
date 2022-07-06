#pragma once

template <class TypeItem>
struct Item {
    TypeItem *NextObject;
    TypeItem *CurrectObject;
    TypeItem *PreviousObject;
    Item(TypeItem *ObjectToContain = nullptr) {
        CurrectObject = ObjectToContain;
        NextObject = PreviousObject = nullptr;
    }
};

template <class TypeItems>
class Container {
protected:
    Item<TypeItems> *Items[];
    unsigned int AmountItems;
public:
    Container( TypeItems *ObjectsToContain = nullptr ) {
        
    }

};
