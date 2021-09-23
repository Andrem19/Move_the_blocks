
#include <iostream>
#include <vector>
#include "picosha2.h"
#include <string>
using namespace std;

class Transaction {
public:
    string from_adress;
    string to_adress;
    double amount;
    Transaction(string from_adress, string to_adress, int amount);
    Transaction();
};

class Block {
public:
    Block(Transaction transaction, string previous_hash);

    int timestamp;
    int zeros;
    Transaction transaction;
    string previous_hash;
    string hash;
    string calculate_hash();

Block(Transaction transaction, string previous_hash, Transaction transaction1);
    friend ostream& operator<<(ostream& os, const Block& point);
    friend bool operator== (const Block &c1, const Block &c2);
    friend bool operator!= (const Block &c1, const Block &c2);
    void operator= (const Block &other);
};

class Blockchain{
public:
    vector<Block> chain;
    vector<Block> pending_t;
    int mining_reward = 100;

    Blockchain();
    Block create_genesis_block();
    Block get_latest_block();
    void add_block(Transaction transaction);
    bool is_chain_valid();
    friend ostream& operator<<(ostream& os, const Blockchain& point);
};

