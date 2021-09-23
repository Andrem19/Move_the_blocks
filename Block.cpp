//
// Created by 72555 on 9/23/2021.
//

#include "Block.h"

Block::Block(int index, string data, string previous_hash) {
this->index = index;
this->timestamp = time(NULL);
this->data = data;
this->previous_hash = previous_hash;
this->zeros = 2;
this->hash = this->calculate_hash();
}

ostream& operator<<(ostream& os, const Block& point)
{
    os<<point.index<<", "<<point.timestamp<<", "<<point.data<<", "<<point.hash<<", "<<point.previous_hash<<", ";
    return os;
}

string Block::calculate_hash() {
    long int NONCE_LIMIT = 10000000000;
    int ident = 0;
    string res;
    string src = to_string(this->index) + to_string(this->timestamp) + this->data + this->previous_hash;

    for (int i = 0; i < NONCE_LIMIT; ++i) {
        res = picosha2::hash256_hex_string(src + to_string(i));
//        cout<< res<< endl;

        char* res_char = new char[res.length()];
        strcpy(res_char, res.c_str());

        for (int j = 0; j < this->zeros; ++j) {
            if(res_char[j] == '0')
            {
                ident++;
            }
            else
            {
                ident = 0;
                break;
            }
        }
        if (ident == this->zeros) {
            cout<<"code: " << i << endl;
            break;
        }
    }
    return res;
}

Blockchain::Blockchain() {
this->chain.push_back(create_genesis_block());
}

Block Blockchain::create_genesis_block() {
    Block new_block(1, "Genesisblock", "uioj45641ki");
    return new_block;
}

Block Blockchain::get_latest_block() {
    return this->chain[this->chain.size() -1];
}

void Blockchain::add_block(string data) {
    int ind = this->get_latest_block().index + 1;
    string prev_hash = get_latest_block().hash;

    Block new_block(ind, data, prev_hash);
    cout<<new_block<<endl;
    this->chain.push_back(new_block);
}
