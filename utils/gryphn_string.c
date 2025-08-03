#include "gryphn_string.h"
#include <stdlib.h>
#include <string.h>

static char* add_string_to_string(char* str1, char* str2) {
    char* buffer = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcpy(buffer, str1);
    strcat(buffer, str2);
    buffer[strlen(str1) + strlen(str2)] = '\0';
    return buffer;
}
// add char to char buffer
// better name
static char* add_char_to_string(char* str1, char str2) {
    char* buffer = (char*)malloc(sizeof(char) * (strlen(str1) + 2));
    strcpy(buffer, str1);
    buffer[strlen(str1)] = str2;
    buffer[strlen(str1) + 1] = '\0';
    return buffer;
}

typedef struct gnString_t {
    gnChar* value;
} gnString_t;

gnString gnCreateStringFromConstCharPtr(const gnChar* input) {
    gnString string = malloc(sizeof(gnString_t));;
    string->value = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(string->value, input);
    string->value[strlen(input)] = '\0';
    return string;
}
gnString gnCreateStringFromCharPtr(gnChar* input) {
    gnString sting = malloc(sizeof(gnString_t));;
    sting->value = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(sting->value, input);
    sting->value[strlen(input)] = '\0';
    return sting;
}
gnString gnCreateStringFromChar(gnChar input) {
    gnString string = malloc(sizeof(gnString_t));;
    string->value = (char*)malloc(sizeof(char) * 2);
    string->value[0] = input;
    string->value[1] = '\0';
    return string;
}

gnString gnCreateEmptyString(void) {
    gnString string = malloc(sizeof(gnString_t));
    string->value = (char*)malloc(sizeof(char));
    string->value[0] = '\0';
    return string;
}


void gnSetStringToChar(gnString string, gnChar input) {
    string->value = (gnChar*)malloc(sizeof(gnChar) * 2);
    string->value[0] = input;
    string->value[1] = '\0';
}
void gnSetStringToCharPtr(gnString string, gnChar* input) {
    string->value = (gnChar*)malloc(sizeof(gnChar) * (strlen(input) + 1));
    strcpy(string->value, input);
    string->value[strlen(input)] = '\0';
}
void gnSetStringToConstCharPtr(gnString string, const gnChar* input) {
    string->value = (gnChar*)malloc(sizeof(gnChar) * (strlen(input) + 1));
    strcpy(string->value, input);
    string->value[strlen(input)] = '\0';
}
void gnSetStringToString(gnString string, const gnString input) {
    string->value = (gnChar*)malloc(sizeof(gnChar) * (strlen(input->value) + 1));
    strcpy(string->value, input->value);
    string->value[strlen(input->value)] = '\0';
}

int gnStringFindChar(gnString string, const gnChar letter) {
    for (unsigned long i = 0; i < strlen(string->value); i++)
        if (string->value[i] == letter)
            return i;
    return -1;
}
int gnStringFindString(gnString string, const gnString value) {
    char first_char = value->value[0];
    for (unsigned long i = 0; i < strlen(string->value); i++)
        if (string->value[i] == first_char) {
            gnBool same = GN_TRUE;
            for (unsigned long c = 1; c < strlen(value->value); c++)
                if (string->value[i + c] != value->value[c]) {
                    same = GN_FALSE;
                    break;
                }

            if (same)
                return i;
        }
    return -1;
}

void gnAddCharToString(gnString string, gnChar val) {
    string->value = add_char_to_string(string->value, val);
}
void gnAddCharPtrToString(gnString string, gnChar* val) {
    string->value = add_string_to_string(string->value, val);
}
void gnAddConstCharPtrToString(gnString string, const gnChar* val) {
    string->value = add_string_to_string(string->value, (gnChar*)val);
}
void gnAddContGnStringToString(gnString string, gnString val) {
    string->value = add_string_to_string(string->value, val->value);
}

gnString gnCombineStringsChar(const gnString string, gnChar val) {
     return gnCreateString(add_char_to_string(string->value, val));
}
gnString gnCombineStringsCharPtr(const gnString string, gnChar* val) {
    return gnCreateString(add_string_to_string(string->value, val));
}
gnString gnCombineStringsConstCharPtr(const gnString string, const gnChar* val) {
    return gnCreateString(add_string_to_string(string->value, (gnChar*)val));
}
gnString gnCombineStringsString(const gnString string, const gnString val) {
    return gnCreateString(add_string_to_string(string->value, val->value));
}

gnChar gnGetCharAt(gnString string, int index) { return string->value[index]; }
void gnSetCharAt(gnString string, int index, gnChar letter) { string->value[index] = letter; }


gnBool gnStringEqualsCharPtr(const gnString string, gnChar* val) { return (strcmp(string->value, val) == 0); }
gnBool gnStringEqualsConstCharPtr(const gnString string,const gnChar* val) { return (strcmp(string->value, (gnChar*)val) == 0); }
gnBool gnStringEqualsString(const gnString string, const gnString val) { return (strcmp(string->value, val->value) == 0); }

const char* gnToCString(const gnString string) { return string->value; }
int gnStringLength(const gnString string) { return strlen(string->value); }
gnString gnSubstring(const gnString string, int index1, int index2) {
    if (index2 == -1) index2 = gnStringLength(string);
    char* out_value = (char*)malloc(sizeof(char) * ((index2 - index1) + 1));
    for (int i = 0; i < (index2 - index1); i++)
        out_value[i] = string->value[i + index1];
    out_value[(index2 - index1)] = '\0';
    return gnCreateString(out_value); // zero error checking on this function should really add that in later but like I dont have a logging library that I want to use
                                      // my code never breaks either so I dont need error checks, il just not make errors cuz im not tim
}
int gnLetterCount(const gnString string, const gnChar letter) {
    int count = 0;
    for (int i = 0; i < gnStringLength(string); i++) if (string->value[i] == letter) count++;
    return count;
}
