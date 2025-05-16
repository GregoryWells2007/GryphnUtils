#include "gryphn_file.h"
#include <stdio.h>
// #include "fstream"
// #include "iostream"

gnFile gnLoadFile(const gnString path, gnFileType type) {
    gnFile new_file = {
        .path = path,
        .type = type
    };

    if (type == GN_FILE_TEXT) {
        new_file.data = malloc(sizeof(gnString));
        *((gnString*)new_file.data) = gnCreateEmptyString();
    }

    if (type == GN_FILE_TEXT) {
        FILE *fptr;
        fptr = fopen(path.value, "r");

        int ch;
        if (fptr != NULL) {
            while ((ch = fgetc(fptr)) != EOF) {
                putchar(ch); // or process the char
            }
            fclose(fptr);
        }
    }
    else if (type == GN_FILE_BINARY) {
        FILE *file = fopen(path.value, "rb");
        if (file) {
            fseek(file, 0, SEEK_END);
            long size = ftell(file);
            rewind(file);
            char *buffer = malloc(size);
            if (buffer) {
                fread(buffer, 1, size, file);
                // use buffer here
                free(buffer);
            }
            fclose(file);
        }
    }
    return new_file;
}

gnString gnGetFileData(const gnFile file) { return *(gnString*)file.data;}
  // why I dont just return the file as a list of lines, cuz thats the easy way this way revealed so many errors in my string class,
  // dont you love it when you dont actually copy a string and then the data gets lost and you dont know why because your an idiot
  // thats never happened to me...... yea so im an idiot shouve actually copied the bytes over not just haphazardly asigned them to a string.

gnString gnGetFilePath(const gnFile file) {
    return file.path;
}

gnChar* gnGetFileBytes(const gnFile file) { return (gnChar*)file.data; }
