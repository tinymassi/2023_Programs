#include <iostream>
#include "logger.h"

int main () {
    log::log table;
    table.insert(103, "11/2/23", "hello world");
    //table.print_log();
}