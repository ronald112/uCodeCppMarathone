#include <iostream>
#include <string>

#include "CBLVector.h"
#include "algorithmUtils.h"

#include <vector>
#include <cassert>

int main() {
    // Simple vector
    {
        CBL::Vector<int> v{ 2, 3, 4, 5 };

        int i = 2;
        for (auto& item : v) {
            assert(i == item);
            ++i;
        }

        assert(*v.begin() == 2);
        assert(*(v.end() - 1) == 5);

        assert(v.size() == 4);
        assert(v.capacity() >= 4);
        assert(!v.isEmpty());

        // std::cout << "Simple vector PASS" << std::endl;
    }

    // Vectors copy and comparsion
    {
        CBL::Vector<double> v;

        for (auto i = 1; i < 4; ++i) {
            v.push_back(i);
        }

        auto cpy = v;
        assert(cpy.size() == v.size());

        for (size_t i = 0; i < cpy.size(); ++i) {
            assert(cpy[i] == v[i]);
        }

        assert(v == cpy);

        cpy.push_back(3.14);

        assert(v != cpy);
        assert(v < cpy);
        assert(!(v > cpy));
        assert(v <= cpy);
        assert(!(v >= cpy));

        // std::cout << "Vectors copy and comparsion <double> PASS" << std::endl;
    }

    // Vectors copy and comparsion
    {
        CBL::Vector<std::string> v{"1.1", "2.2", "3.3", "4.4", "5.5"};

        auto cpy = v;
        assert(cpy.size() == v.size());

        for (size_t i = 0; i < cpy.size(); ++i) {
            assert(cpy[i] == v[i]);
        }

        assert(v == cpy);

        cpy.push_back("3.14");

        assert(v != cpy);
        assert(v < cpy);
        assert(!(v > cpy));
        assert(v <= cpy);
        assert(!(v >= cpy));

        // std::cout << "Vectors copy and comparsion <string> PASS" << std::endl;
    }

    // Vectors <string> clear
    {
        CBL::Vector<std::string> v(10);

        v.clear();

        assert(v.size() == 0);
        assert(v.isEmpty());

        // std::cout << "Vectors <string> clear PASS" << std::endl;
    }

    // Vectors <int> clear
    {
        CBL::Vector<int> v(10);

        v.clear();

        assert(v.size() == 0);
        assert(v.isEmpty());

        // std::cout << "Vectors <int> clear PASS" << std::endl;
    }

    // Constructor and pop <string>
    {
        CBL::Vector<std::string> v(10, "VAR");
        for (auto& item : v) {
            assert(item == "VAR");
        }

        v.pop_back();

        assert(v.size() == 9);

        // std::cout << "Constructor and pop <string> PASS" << std::endl;
    }

    // Iterator construction <double>
    {
        CBL::Vector<double> v{1.1, 2.2, 3.3, 4.4, 5.5};

        auto cpy = CBL::Vector<double>(v.begin(), v.end());

        assert(cpy == v);

        assert(cpy[2] == 3.3);

        // std::cout << "Iterator construction <double> PASS" << std::endl;
    }

    // Iterator insertion and removal <char>
    {
        CBL::Vector<char> v{ 'a', 'b', 'c', 'd', 'e' };
        auto insIt = v.insert(v.begin() + 2, 'z');
        assert(*insIt == 'z');
        insIt = v.insert(v.end(), 'k');
        assert(*insIt == 'k');
        auto ersIt = v.erase(v.begin() + 2);
        assert(*ersIt == 'c');
        ersIt = v.erase(v.begin(), v.end());
        assert(!ersIt);
        assert(v.size() == 0);
        assert(v.isEmpty());
        // std::cout << "Iterator insertion and removal <char> OK" << std::endl;
    }
    // if there is no errors - all ok
    return 0;
}
