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

class ExceptionIncorrectIndex {
    unsigned int IncorrectIndex;
public:

    ExceptionIncorrectIndex( unsigned int IncorrectIndex) {
        this->IncorrectIndex = IncorrectIndex;
    }

    unsigned int GetIncorrectIndex() {
        return IncorrectIndex;
    }

};

template <class TypeItems>
class Container {
protected:
    Item<TypeItems> *StartItem;
    Item<TypeItems> *EndItem;
    unsigned int AmountItems;
public:
    Container( TypeItems *ObjectToContain = nullptr );
    
    ~Container();

    TypeItems *operator[]( unsigned int IndexItem );

    bool PullItem();

    void PushItem( TypeItems &ItemToContain );

};

template <class TypeItems>
Container<TypeItems>::Container( TypeItems *ObjectToContain ) {
    StartItem = EndItem = nullptr;
    if (!ObjectToContain) {
        AmountItems = 0;
    } else {
        AmountItems = 1;
    }
}

template <class TypeItems>
TypeItems *Container<TypeItems>::operator[]( unsigned int IndexItem ) {
    if ( IndexItem >= AmountItems ) {
        throw ExceptionIncorrectIndex(IndexItem);
    }
    Item<TypeItems> *ItemToGet = StartItem;
    for ( unsigned int i = 1; i <= IndexItem; i++ ) {
        ItemToGet = ItemToGet->NextItem;
    }
    return ItemToGet->CurrectObject;
}

template <class TypeItems>
Container<TypeItems>::~Container() {
    Item<TypeItems> *ItemToDelete,*TempItem = StartItem;
    for ( unsigned int i = 0; i < AmountItems; i++ ) {
        ItemToDelete = TempItem;
        TempItem = TempItem->NextItem;
        delete ItemToDelete;
    }
}

template <class TypeItems>
void Container<TypeItems>::PushItem( TypeItems &ItemToContain ) {
    if (AmountItems == 1) {
        EndItem = new Item<TypeItems>(&ItemToContain);
        StartItem->NextItem = EndItem;
        EndItem->PreviousItem = StartItem;
        AmountItems++;
        return;
    }
    if (!AmountItems) {
        StartItem = new Item<TypeItems>(&ItemToContain);
        AmountItems++;
        return;
    }
    Item<TypeItems> *PreviousItem = EndItem;
    EndItem->NextItem = new Item<TypeItems>(&ItemToContain);
    EndItem = EndItem->NextItem;
    EndItem->PreviousItem = PreviousItem;
    AmountItems++;
}

template <class TypeItems>
bool Container<TypeItems>::PullItem() {
    if (!AmountItems) {
        return false;
    }
    if (AmountItems == 1) {
        delete EndItem;
        delete StartItem;
        AmountItems--;
        return true;
    }
    EndItem = EndItem->PreviousItem;
    delete EndItem->NextItem;
    EndItem->NextItem = nullptr;
    AmountItems--;
    return true;
}