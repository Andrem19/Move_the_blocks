#include <iostream>
#include "picosha2.h"
#include "Block.h"

int main() {
    Blockchain my_chain;
    Transaction transaction("gyu87tg7ut677u", "hbu7iy89y87fr567", 100);
    my_chain.add_block(transaction);
    my_chain.add_block(transaction);
    my_chain.add_block(transaction);

//    my_chain.chain[2].data = "Hi there";

    cout<< "is chain valid?"<< my_chain.is_chain_valid()<<endl;
    return 0;
}
