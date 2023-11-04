#include <iostream>
#include "logger.h"

int main () {
    log::log table;
    table.insert(1003, "11/2/23", "hello world");
    table.insert(1003, "11/2/23", "hello world");
    table.print_log();
}