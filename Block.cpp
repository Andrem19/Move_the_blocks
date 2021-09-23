//
// Created by 72555 on 9/23/2021.
//

#include "Block.h"

#include <utility>



Block::Block(Transaction transaction, string previous_hash) {
this->timestamp = time(NULL);
this->transaction = std::move(transaction);
this->previous_hash = previous_hash;
this->zeros = 2;
this->hash = this->calculate_hash();
}

ostream& operator<<(ostream& os, const Block& point)
{
    os<<point.timestamp<<", "<<point.hash<<", "<<point.previous_hash<<", ";
    return os;
}

string Block::calculate_hash() {
    long int NONCE_LIMIT = 10000000000;
    int ident = 0;
    string res;
    string src = to_string(this->timestamp) + this->transaction.from_adress + this->transaction.to_adress + to_string(this->transaction.amount) + this->previous_hash;

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

bool operator==(const Block &c1, const Block &c2) {
    return (c1.hash == c2.hash && c1.previous_hash == c2.previous_hash && c1.timestamp == c2.timestamp);
}

bool operator!=(const Block &c1, const Block &c2) {
    return (c1.hash != c2.hash && c1.previous_hash != c2.previous_hash && c1.timestamp != c2.timestamp);
}
void Block::operator= (const Block &other)
{
this->timestamp = other.timestamp;
this->hash = other.hash;
this->previous_hash = other.previous_hash;
}

Blockchain::Blockchain() {
this->chain.push_back(create_genesis_block());
}

Block Blockchain::create_genesis_block() {
    Transaction first("ghjkkgyufs5656ft8gg", "ghjgyuj784r5fvh89hjol8", 100);
    Block new_block(first, "uioj45641ki");

    return new_block;
}

Block Blockchain::get_latest_block() {
    return this->chain[this->chain.size() -1];
}

void Blockchain::add_block(Transaction transaction) {
    string prev_hash = get_latest_block().hash;

    Block new_block(transaction, prev_hash);

    this->chain.push_back(new_block);
    for (int i = 0; i < chain.size(); ++i) {
        cout<<chain[i]<<endl;
    }

}
ostream& operator<<(ostream& os, const Blockchain & point)
{
    for (int i = 0; i < point.chain.size(); ++i) {
        os<<point.chain[i].timestamp<<", "<<point.chain[i].hash<<", "<<point.chain[i].previous_hash<<", ";
    }
    return os;
}

bool Blockchain::is_chain_valid() {
    for (int i = 1; i < this->chain.size() - 1; i++) {
        Block current_block = this->chain[i];
        Block previous_block = this->chain[i - 1];

        if(current_block.hash != current_block.calculate_hash())
        {
            return false;
        }
        if(current_block.previous_hash != previous_block.hash)
        {
            return false;
        }
    }
    return true;
}

Transaction::Transaction(string from_adress, string to_adress, int amount) {
this->from_adress = from_adress;
this->to_adress = to_adress;
this->amount = amount;
}

Transaction::Transaction() {

}
