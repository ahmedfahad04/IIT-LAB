#include <stdio.h>
#include <assert.h>
#include "sqlite3.h"


int main(){

    char *ch = "Are you sure that this line will print out?";

    // 1. initialize sqlite3_str object using sqlite3_str_new()
    sqlite3_str *str = sqlite3_str_new(NULL);

    // 2. Now insert the text into the sqlite3_str object using sqlite3_str_appendf()
    //    it's like sqlite3's printf function
    sqlite3_str_appendf(str, "%s", ch); 

    // 3. the string value can be achieved from sqlite3_str_value()
    printf("%s\n", sqlite3_str_value(str));

    // 4. *** Now using sqlite3_str_append function we can append string to specific bytes
    sqlite3_str_append(str, "Yes, sure.", 9);
    printf("%s\n", sqlite3_str_value(str));

    // 5. Destroy the sqlite3_str after it's operation is completed
    sqlite3_str_finish(str);
}