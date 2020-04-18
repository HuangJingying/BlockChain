#include <ctime>
#include <string>
#include "transaction.h"
#include "sha256.h"

int Transaction::mineReward = 5; //to be set
vector<Transaction> Transaction::txPool;
vector<Transaction> Transaction::toBePackedTx;

string Transaction::GetTxHash()
{
    string time = ctime(&_time);
    string hashInfo = time + senderAdr + receiverAdr + to_string(input.GetValue());
    string txHash = sha256(hashInfo);
    return txHash;
}

bool Transaction::IsCoinbase()
{
    if (input.GetPrevID() == -1 && input.GetValue() == 0)
    {
        return true;
    }
}