#pragma once 

#include <iostream>

#include "StringFunction.h"

#include "Containers.hpp"

using namespace std;

class File{
    char *Name;
public:
    
    File( const char *Name )  {
        this->Name = new char[GetAmountSymbolsInString(Name) + 1];
        CopyString(this->Name, Name);
    }

    File() {
        Name = 0;
    }

    File( const File &FileToCopy )  {
        this->Name = new char[GetAmountSymbolsInString(FileToCopy.Name) + 1];
        CopyString(this->Name, FileToCopy.Name);
    }
    
    ~File() {
        if (Name) {
            delete[] Name;
        }
    }

    void ShowName() {
        if (Name) {
            cout << Name << "  " << &Name;
        }
    }
    void operator=( const File &ObjectToCopy );
};

void File::operator=( const File &ObjectToCopy ) {
    if (!ObjectToCopy.Name) {
        this->Name = 0;
        return;
    }
    if (this->Name) {
        delete[] this->Name;
    }
    this->Name = new char[GetAmountSymbolsInString(ObjectToCopy.Name) + 1];
    CopyString(this->Name, ObjectToCopy.Name);
}
    
class StorageFiles{
protected:
    Container <File> *ListFiles;
    char *Name;
public:

    StorageFiles( const char *NameStorage, Container<File> *Files);
    
    StorageFiles( const StorageFiles &StorageToCopy );

    StorageFiles() {
        Name = 0;
        ListFiles = 0;
    }

    StorageFiles( const char *NameStorage ) {
        Name = new char[GetAmountSymbolsInString(NameStorage) + 1];
        CopyString(Name, NameStorage);
        ListFiles = 0;
    }

    void ShowName() {
        if (Name) {
            cout << Name;
        }
    }

    void AddFile( File &AdditionFile ) {
        if (!ListFiles) {
            ListFiles = new Container<File>;
        }
        ListFiles->AddElement(AdditionFile);
    }

    bool Is_File_Exist( unsigned int NumberFile ) {
        if (!ListFiles) {
            return false;
        }
        return ListFiles->Is_Element_Exist(NumberFile - 1);
    }

    ~StorageFiles() {
        if (Name) {
            delete[] Name;
        }
        if (ListFiles) {
            delete ListFiles;
        }
    }
};

StorageFiles::StorageFiles( const StorageFiles &StorageToCopy ) {
    this->Name = new char[GetAmountSymbolsInString(StorageToCopy.Name) + 1];
    CopyString(this->Name, StorageToCopy.Name);
    ListFiles = StorageToCopy.ListFiles ? new Container<File> (*StorageToCopy.ListFiles) : 0;
}

StorageFiles::StorageFiles( const char *NameStorage, Container<File> *Files ) {
    this->Name = new char[GetAmountSymbolsInString(NameStorage) + 1];
    CopyString(this->Name, NameStorage);
    ListFiles = Files ? new Container<File> (*Files) : 0;
}

class Folder : public StorageFiles {
    Container <Folder> *ListFolders;
    public:

    Folder( const char *NameFolder, Container <File> *Files, Container <Folder> *Folders) : StorageFiles( NameFolder, Files ) {
        ListFolders = Folders ? new Container<Folder>(*Folders) : 0;
    }

    Folder( const char *Name ) : StorageFiles (Name) {
        ListFolders = 0;
    }

    Folder() {
        ListFolders = 0;
    }

    Folder( const Folder &FolderToCopy ) : StorageFiles( FolderToCopy ) {
        ListFolders = FolderToCopy.ListFolders ? new Container<Folder>(*FolderToCopy.ListFolders) : 0;
    }

    ~Folder() {
        if (ListFolders) {
            delete ListFolders;
        }
    }

    bool Is_Folder_Exist( unsigned int NumberFile ) {
        if (!ListFolders) {
            return false;
        }
        return ListFolders->Is_Element_Exist(NumberFile - 1);
    }

    void AddFolder( Folder &AdditionFolder ) {
        if (!ListFolders) {
            ListFolders = new Container<Folder>;
        }
        ListFolders->AddElement(AdditionFolder);
    }

};
