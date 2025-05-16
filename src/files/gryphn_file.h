#pragma once
#include "../strings/gryphn_string.h"
#include "../lists/gryphn_array_list.h"

typedef enum gnFileType {
    GN_FILE_TEXT, GN_FILE_BINARY
} gnFileType;

typedef struct gnFile {
    void* data;
    // GN_FILE_TEXT = gnString
    // GN_FILE_BINARY = gnChar*
    gnString path;
    gnFileType type;
} gnFile;

#ifdef GN_UITLS_CPP
gnFile gnLoadFile(const gnString& path, gnFileType type = GN_FILE_TEXT);
#else
gnFile gnLoadFile(const gnString path, gnFileType type);
#endif
// gnFile gnCreateFile(const gnString path);
// gnFile gnWriteFile(const gnFile file);

gnString gnGetFilePath(const gnFile file);
gnString gnGetFileData(const gnFile file); // i should rename this
gnChar* gnGetFileBytes(const gnFile file);  // fuck object oriented code
                                                    // and fuck error detection the user can get the bytes of a text file if they want to cuz its slow to do error checking, its also smart but im slow
                                                    // so me and this project are one in the same
