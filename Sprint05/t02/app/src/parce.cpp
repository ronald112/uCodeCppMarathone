#include <regex>
#include "misc.h"

using namespace std;

static pair<string, string> fourArg(char* argv[]) {
    regex nums(R"(\d+)");
    regex names(R"((\w+),(\w+))");
    cmatch match;
    pair<string, string> rslt;

    if (!regex_match(argv[1], match, nums)) {
        throw ("Invalid shoutNumber");
    }
    if (!regex_match(argv[2], match, names)) {
        throw ("Invalid names");
    }
    rslt.first = match.str(1);
    rslt.second = match.str(2);
    if (!regex_match(argv[3], match, nums)) {
        throw ("Error");
    }
    return rslt;
}

static pair<string, string> fiveArg(char* argv[]) {
    regex nums(R"(\d+)");
    cmatch match;
    pair<string, string> rslt = fourArg(argv);

    if (!regex_match(argv[4], match, nums)) {
        throw ("Error");
    }
    return rslt;
}

pair<string, string> parce(int argc, char* argv[]) {
    pair<string, string> rslt;

    if (argc == 4) {
        rslt = fourArg(argv);
    }
    else if (argc == 5) {
        rslt = fiveArg(argv);
    }
    
    return rslt;
}