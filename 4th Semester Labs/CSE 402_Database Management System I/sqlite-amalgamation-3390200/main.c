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
    char *updated_sqlite3_str = sqlite3_str_value(str);          
    printf("%s\n", updated_sqlite3_str);

    // 4. *** Now using sqlite3_str_append function we can append string to specific bytes
    sqlite3_str_append(str, "Yes, I am.", -1);
    printf("%s\n", updated_sqlite3_str);
    
}