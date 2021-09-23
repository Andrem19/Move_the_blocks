
#include <iostream>
#include <vector>
#include "picosha2.h"
#include <string>
using namespace std;

class Block {
public:
    int index;
    int timestamp;
    int zeros;
    string data;
    string previous_hash;
    string hash;
    string calculate_hash();

Block(int index, string data, string previousHash);
    friend ostream& operator<<(ostream& os, const Block& point);
};

class Blockchain{
public:
    vector<Block> chain;

    Blockchain();
    Block create_genesis_block();
    Block get_latest_block();
    void add_block(string data);
};

