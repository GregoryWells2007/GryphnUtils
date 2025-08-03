#pragma once
#include "gryphn_bool.h"

typedef char gnChar;
typedef struct gnString_t* gnString;

gnString gnCreateStringFromConstCharPtr(const gnChar* input);
gnString gnCreateStringFromCharPtr(gnChar* input);
gnString gnCreateStringFromChar(gnChar input);
gnString gnCreateEmptyString(void);
#define gnCreateString(input) _Generic((input), \
    const gnChar*: gnCreateStringFromConstCharPtr, \
    gnChar*: gnCreateStringFromCharPtr, \
    gnChar: gnCreateStringFromChar \
)(input)

const char* gnToCString(const gnString string);
int gnStringLength(const gnString string);
gnString gnSubstring(const gnString string, int index1, int index2);
int gnLetterCount(const gnString string, const gnChar letter);

int gnStringFindChar(gnString string, const gnChar letter);
int gnStringFindString(gnString string, const gnString value);
#define gnStringFind(string, value) _Generic((value), \
    const gnChar: gnStringFindChar, \
    const gnString: gnStringFindValue \
)(string, value)

void gnAddCharToString(gnString string, gnChar val);
void gnAddCharPtrToString(gnString string, gnChar* val);
void gnAddConstCharPtrToString(gnString string, const gnChar* val);
void gnAddContGnStringToString(gnString string, gnString val);
#define gnAddToString(string, value) _Generic((value), \
    gnChar: gnAddCharToString, \
    int: gnAddCharToString, \
    gnChar*: gnAddCharPtrToString, \
    const gnChar*: gnAddConstCharPtrToString, \
    gnString: gnAddContGnStringToString \
)(string, value)

gnString gnCombineStringsChar(const gnString string, gnChar val);
gnString gnCombineStringsCharPtr(const gnString string, gnChar* val);
gnString gnCombineStringsConstCharPtr(const gnString string, const gnChar* val);
gnString gnCombineStringsString(const gnString string, const gnString val);
#define gnCombineStrings(string, value) _Generic((value), \
    gnChar: gnCombineStringsChar, \
    int: gnCombineStringsChar, \
    gnChar*: gnCombineStringsCharPtr, \
    const gnChar*: gnCombineStringsConstCharPtr, \
    gnString: gnCombineStringsString \
)(string, value)

gnBool gnStringEqualsCharPtr(const gnString string, gnChar* val);
gnBool gnStringEqualsConstCharPtr(const gnString string,const gnChar* val);
gnBool gnStringEqualsString(const gnString string, const gnString val);
#define gnStringEquals(string, value) _Generic((value), \
    gnChar*: gnStringEqualsCharPtr, \
    const gnChar*: gnStringEqualsConstCharPtr, \
    gnString: gnStringEqualsString \
)(string, value)

gnChar gnGetCharAt(const gnString string, int index);
void gnSetCharAt(gnString string, int index, gnChar letter);

void gnSetStringToChar(gnString string, gnChar input);
void gnSetStringToCharPtr(gnString string, gnChar* input);
void gnSetStringToConstCharPtr(gnString string, const gnChar* input);
void gnSetStringToString(gnString string, const gnString input);
#define gnSetString(string, value) _Generic((value), \
    gnChar: gnSetStringToChar, \
    int: gnSetStringToChar, \
    gnChar*: gnSetStringToCharPtr, \
    const gnChar*: gnSetStringToConstCharPtr, \
    gnString: gnSetStringToString \
)(string, value)
