
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
    Block(vector<Transaction> &transactions, string previous_hash);

    int timestamp;
    int zeros;
    vector<Transaction> transactions;
    string previous_hash;
    string hash;
    string calculate_hash();

    friend ostream& operator<<(ostream& os, const Block& point);
    friend bool operator== (const Block &c1, const Block &c2);
    friend bool operator!= (const Block &c1, const Block &c2);
    void operator= (const Block &other);
};

class Blockchain{
public:
    vector<Block> chain;
    int mining_reward = 100;

    Blockchain();
    Block create_genesis_block();
    Block get_latest_block();
    vector<Transaction> pending_t;
    void add_pend_t(Transaction transaction);
    void add_block(string reward_address);
    int get_balance_amount(string address);
    bool is_chain_valid();
    friend ostream& operator<<(ostream& os, const Blockchain& point);
};

