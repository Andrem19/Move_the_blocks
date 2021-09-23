#include <iostream>
#include "picosha2.h"
#include "Block.h"

int main() {
    Blockchain my_chain;
    my_chain.add_block("HelloWorld");
    my_chain.add_block("HelloWorld");
    my_chain.add_block("HelloWorld");
    return 0;
}
