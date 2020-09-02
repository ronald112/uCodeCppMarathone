#include "stdAlgoV1.h"

void NamesFeature::print() {
    cout << "size: " << size << endl;
    cout << "contains 'rich': " << (rich ? "true" : "false") << endl;
    cout << "none of lengths is 15: " << 
        (big_lengths ? "true" : "false") << endl;
    cout << "all end with 'vel': " << 
        (size == all_end_vel ? "true" : "false") << endl;
    cout << "not contains 'mel': " << mel_amount << endl;
}
