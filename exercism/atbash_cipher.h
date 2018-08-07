#if !defined(ATBASH_H)
#define ATBASH_H

#include <string>

namespace atbash {
    char transform(char cc) {
        return isalpha(cc) ? 'z' - cc + 'a' : cc;
    }

    std::string encode(std::string text) {
        std::string cipher;

        for (auto letter : text)
            if (isalnum(letter)) {
                if (cipher.length() % 6 == 5)
                    cipher.push_back(' ');

                cipher.push_back(transform(tolower(letter)));
            }

        return cipher;
    }

    std::string decode(std::string cipher) {
        std::string text;

        for (auto letter : cipher)
            if (!isspace(letter))
                text.push_back(transform(letter));

        return text;
    }
}

#endif

//
//  This solution carefully factors out the common transformation.
//
//  To me this is straight forward:  you implement encode and when you come to
//  decode you realise that the actual atbash transform is symmetrical so you
//  can factor out a common routine.
//
//  It is bad for decode to call encode (as two solution examined did):  it
//  introduces code that is half redundant.  Easy to cope with here but in the
//  read world this is potentially a real maintenance nightmare.
//
//  Even those who spilt out a common routine all mananaged to put conversion
//  to lower case in it.
//
//  Two solutions tried to use STL and call std::erase to filter out characters
//  that are not alphanumeric and then called std::transform twice, one to
//  convert case and once to do some real work.  Ugh.
//
//  Only two were interesting:  one passed a parameter to encode to modify its
//  behaviour for decode.  I've done that myself but not left it that way: to
//  much scope for confusion in the maintenance space.
//
//  The other counted the space inserted by encode and so did things modulo 6.
//  This enabled the solution to start at one and avoid the conditional.  Hmm.
//
