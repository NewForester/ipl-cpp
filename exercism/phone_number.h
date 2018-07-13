#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <cctype>
#include <string>
#include <sstream>

class phone_number {
public:
    explicit phone_number(const char *number): nn(normalise(number)) {}

    const std::string &number(void) const {
        return nn;
    }

    std::string area_code(void) const {
        return nn.substr(0,3);
    }

    operator std::string() const {
        std::stringstream number;

        number << '(' << nn.substr(0,3) << ')';
        number << ' ' << nn.substr(3,3);
        number << '-' << nn.substr(6,4);

        return number.str();
    }

private:
    const std::string nn;

    static std::string normalise(const char *number) {
        std::string normalised;

        for (auto digit : std::string(number))
            if (::isdigit(digit))
                normalised += digit;

        if (normalised.length() == 10)
            return normalised;

        if (normalised.length() == 11 && normalised.front() == '1')
            return normalised.erase(0 ,1);

        return "0000000000";
    }
};

#endif

//
//  This solution uses ::isdigit to clean and a string stream to pretty print.
//
//  The other uses the same algorithm, some where shorter, other much longer.
//
//  Most used a lower level loop to clean the string as I did.  Two used
//  copy_if() but I'm not sure about the conditions.
//
//  Most used string concatenation for the pretty print, one used boost::format
//  while I used a string stream.
//
//  Most had just the bare number as data member, as I did, but a couple had
//  three as you might expect.
//
