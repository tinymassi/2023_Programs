#include <iostream>
#include "logger.h"

int main () {
    log::log table;
    table.insert(1003, "11/2/23", "hello world");
    table.insert(1003, "11/4/23", "This data structure works!!");
    table.print_log();
    table.remove(1003, "11/2/25");
    table.print_log();
}