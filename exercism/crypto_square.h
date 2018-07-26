#if !defined(CRYTO_SQUARE_H)
#define CRYTO_SQUARE_H

#include <cctype>
#include <cmath>
#include <string>
#include <utility>
#include <vector>

namespace crypto_square {
    class cipher {
    public:
        cipher(const char *plain_text): text(normalise(plain_text)) {}

        const std::string &normalize_plain_text(void) const {
            return text;
        }

        std::vector<std::string> plain_text_segments(void) const {
            std::vector<std::string> segments;

            const int len = dimensions().first;

            for (int pos = 0; pos < text.length(); pos += len)
                segments.push_back(text.substr(pos, len));

            return segments;
        }

        std::string cipher_text(void) const {
            return encrypt(false);
        }

        std::string normalized_cipher_text(void) const {
            return encrypt(true);
        }
    private:
        const std::string text;

        std::string normalise(const char *text) const {
            std::string normal;

            for (; *text; ++text)
                if (isalnum(*text))
                    normal.push_back(tolower(*text));

            return normal;
        }

        std::pair<int, int>dimensions(void) const {
            double root = sqrt(text.length());

            return std::pair<int, int>(ceil(root), floor(root));
        }

        std::string encrypt(bool normalise) const {
            std::string cipher;

            auto dims = dimensions();
            auto data = text.data();
            auto len = text.length();

            for (int ii = 0; ii < dims.first; ++ii) {
                for (int jj = 0; jj < dims.second; ++jj) {
                    int offset = ii + jj * dims.first;

                    if (offset < len)
                        cipher.push_back(data[offset]);
                    else if (normalise)
                        cipher.push_back(' ');
                }
                if (normalise)
                    cipher.push_back(' ');
            }

            if (normalise && !cipher.empty())
                cipher.pop_back();

            return cipher;
        }
    };
}

#endif

//
//  The track version of this exercise forced long winded solutions.
//
//  Most of the solutions were, like mine, around 80 lines long.  For the two
//  shorter solutions there was no clear reason why.
//
//  The way the tests were constructed implied a particular way of solving the
//  main problem.  Some followed this route, others did not (I did not).  That
//  seemed to make little difference.
//
//  I am not sure that following the way the test cases expected did not
//  actually make the code harder to follow (may just be sour grapes).  The
//  idea might have worked well in Rust with each additional requirement being
//  a new section in the pipe.
//
//  Some solutions used STL more that I did, others went to Boost.  Nothing seemed
//  to make much difference except perhaps to the efficiency.  It was unclear what
//  was and what wasn't efficient.  I tend to drop back to looping over characters.
//  There is nothing wrong with higher level constructs but they did not make the
//  code clearer nor where they clearly efficient.  I suspect in Rust, the use of
//  char iterators would be both clearer and efficient.
//
//  I used a boolean flag to avoid creating yet another routine.  Some might call
//  that a dirty trick that requires refactoring out of existence.  I'm inclined to
//  agree.
//
//  Note that boost/algorithm/string.hpp as some of the string functions
//  that I find missing from the STL library.
//
