#include <iostream>
#include "picosha2.h"
#include "Block.h"

int main() {
    Blockchain my_chain;
    Transaction transaction("gyu87tg7ut677u", "hbu7iy89y87fr567", 40);
    my_chain.add_pend_t(transaction);
    Transaction transaction2("gyu87pojsdd777u", "hbu7iy45gtyd67", 80);
    my_chain.add_pend_t(transaction2);

    my_chain.add_block("andrew_address");

    Transaction transaction3("gyu87tkjg7ut677u", "hbuswgf7iy89y87fr567", 60);

    my_chain.add_pend_t(transaction3);

    my_chain.add_block("andrew_address");

    cout<< "Your amount is: "<<my_chain.get_balance_amount("andrew_address")<<endl;

    cout<< "is chain valid?"<< my_chain.is_chain_valid()<<endl;
    return 0;
}
