#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class TypeString{
    char *String;
    int *LengthString;
    void DeleteFragmentInString( char *CharFragment );

    public:

    TypeString() {
        String = 0;
        LengthString = 0;
    }

    TypeString( char *InputString ) {
        LengthString = new int[strlen(InputString)];
        String = new char[*LengthString + 1];
        strcpy(this->String, InputString);
    }

    ~TypeString() {
        if ( LengthString ) {
            delete[] String;
        }
    }

    TypeString ( const TypeString &CopyingObject );
    TypeString operator=( TypeString InputString );
    TypeString operator=( char *InputString );
    TypeString operator+( TypeString &ObjectTerm );
    TypeString operator+( char *TermString );
    TypeString operator-( TypeString &DeletingFragment );
    TypeString operator-( char *DeletingFragment );
    friend char *operator-( char *String, TypeString &Fragment );
    char operator[]( int Index );
    void operator()( char *InputString );
    void operator()( TypeString &InputString );
    void FreeExistingMemoryMembersClass();
    void AllocationNewLenghtString( int NewLength );
    void ShowString();
    void ShowLenghtString();
};

TypeString::TypeString ( const TypeString &CopyingObject ) {
    try {
        if( !CopyingObject.LengthString ) {
            throw ("The empty string has been transmitted");
        }
        LengthString = new int(*CopyingObject.LengthString);
        String = new char[*LengthString + 1];
        strcpy(String, CopyingObject.String);
    }catch( const char *MessageExplain ) {
        cout << MessageExplain << '\n';
        String = 0;
        LengthString = 0;
    }       
}

TypeString TypeString::operator=( TypeString InputString ) {
    if ( !InputString.LengthString ) {
        return *this;
    }
    FreeExistingMemoryMembersClass();
    AllocationNewLenghtString(*InputString.LengthString);
    strcpy( String, InputString.String );
    return *this;
}

TypeString TypeString::operator=( char *InputString ) {
    if ( !strlen(InputString) ) {
        return *this;
    }
    FreeExistingMemoryMembersClass();
    AllocationNewLenghtString(strlen(InputString));
    strcpy(String, InputString);
    return *this;
}

TypeString TypeString::operator+( TypeString &ObjectTerm ) {
    if ( !ObjectTerm.LengthString ) {
        return *this;
    }
    *LengthString += *ObjectTerm.LengthString;
    char *NewContentString = new char[*LengthString + 1];
    strcpy(NewContentString, String);
    strcat(NewContentString, ObjectTerm.String);
    delete[] String;
    String = new char[*LengthString + 1];
    strcpy(String, NewContentString);
    delete[] NewContentString;
    return *this; 
}  

TypeString TypeString::operator+( char *TermString ) {
    if ( !LengthString ) {
        LengthString = new int(0);
        String = new char('\0');
    }
    *LengthString += strlen(TermString);
    char *NewString = new char[*LengthString + 1];
    strcpy(NewString, String);
    strcat(NewString,TermString);
    delete[] String;
    String = new char[*LengthString + 1];
    strcpy(String, NewString);
    delete[] NewString;
    return *this;
}

TypeString TypeString::operator-( TypeString &DeletingFragment ) {
    try {
        if ( !LengthString ) {
            throw ("The left operand is empty!");
        }
        DeleteFragmentInString( DeletingFragment.String );
    }catch( const char *MessageExplain ) {
        cout << MessageExplain << '\n';
    }
    return *this;
}

TypeString TypeString::operator-( char *DeletingFragment ) {
    try {
        if ( !LengthString ) {
            throw ("The left operand is empty!");
        }
        DeleteFragmentInString( DeletingFragment );
    }catch( const char *MessageExplain ) {
        cout << MessageExplain << '\n';
    }
    return *this;
}

void DeleteFragmentInString( char *String, char *CharFragment ) {
    char *ElementString = String;
    while( *ElementString ) {
        if( *ElementString == *CharFragment ) {
            char *ElementDeletingString = ElementString;
            char *ElementCharFragment = CharFragment;
            while( *ElementDeletingString == *ElementCharFragment ) {
                *ElementDeletingString = ' ';
                ElementDeletingString++;
                ElementCharFragment++;
            }
            strcpy(ElementString--, ElementDeletingString--);
        }
        ElementString++;
    }
}

char *operator-( char *String, TypeString &Fragment ) {
    try {
        if( !strlen(String) ) {
            throw ("The left operand is empty!");
        }
        DeleteFragmentInString(String, Fragment.String);
    }catch( const char *MessageExplain ) {
        cout << MessageExplain << '\n';
    }
    return String;
}



void TypeString::DeleteFragmentInString(char *CharFragment ) {
    char *ElementString = String;
    while( *ElementString ) {
        if( *ElementString == *CharFragment ) {
            char *ElementDeletingString = ElementString;
            char *ElementCharFragment = CharFragment;
            while( *ElementDeletingString == *ElementCharFragment ) {
                *ElementDeletingString = ' ';
                ElementDeletingString++;
                ElementCharFragment++;
            }
            strcpy(ElementString--, ElementDeletingString--);
        }
        ElementString++;
    }
}

char TypeString::operator[]( int Index ) {
    try {
        if( Index < 0 || Index >= *LengthString ) {
            throw ("The incorrect index has been used!");
        }
        return String[Index];
    }catch( const char *MessageError ) {
        cout << MessageError << '\n';
        return 0;
    }
}

void TypeString::operator()( char *InputString ) {
    FreeExistingMemoryMembersClass();
    AllocationNewLenghtString(strlen(InputString));
    strcpy(String, InputString);
}

void TypeString::operator()( TypeString &InputString ) {
    FreeExistingMemoryMembersClass();
    AllocationNewLenghtString(strlen(InputString.String));
    strcpy(String, InputString.String);
}

void TypeString::FreeExistingMemoryMembersClass() {
    if ( LengthString ) {
        delete LengthString;
        delete[] String;
    }
}

void TypeString::AllocationNewLenghtString( int NewLength ) {
    LengthString = new int(NewLength);
    String = new char[ *LengthString + 1];
}

void TypeString::ShowString() {
    if( LengthString ) {
        cout << String;
    }
}

void TypeString::ShowLenghtString() {
    if( LengthString ) {
        cout << *LengthString << '\n';
    }
}