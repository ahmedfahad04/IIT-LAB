#include <stdio.h>
#include <assert.h>
#include "sqlite3.h"


int main(){

    char *ch = "whats the issue?";

    // 1. initialize sqlite3_str object using sqlite3_str_new()
    sqlite3_str *str = sqlite3_str_new(NULL);

    // 2. Now insert the text into the sqlite3_str object using sqlite3_str_appendf()
    //    it's like sqlite3's printf function
    sqlite3_str_appendf(str, "%s", ch); 

    // 3. the string value can be achieved from sqlite3_str_value()
    char *sqlite3_string = sqlite3_str_value(str);          
    printf("BEFORE: %s\n", sqlite3_string);

    // 4. *** Now using sqlite3_str_append function we can append string to specific bytes
    sqlite3_str_append(str, "Books", 6);
    printf("AFTER : %s\n", sqlite3_string);
    
}