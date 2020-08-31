#include "walletManager.h"

Wallet *createWallet(const ssize_t& septims) {
    Wallet* my_wallet = new Wallet;

    my_wallet->septims = septims;
    return my_wallet;
}

Wallet *createWallets(const ssize_t& size) {
    return new Wallet [size];
}

void destroyWallet(Wallet *wallet) {
    delete(wallet);
}

void destroyWallets(Wallet *wallets) {
    delete[](wallets);
}
