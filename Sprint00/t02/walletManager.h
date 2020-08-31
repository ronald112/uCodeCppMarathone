#pragma once
#include <iostream>

struct Wallet {
    int septims;
};

Wallet *createWallet(const ssize_t& septims);
Wallet *createWallets(const ssize_t& size);
void destroyWallet(Wallet *wallet);
void destroyWallets(Wallet *wallets);
