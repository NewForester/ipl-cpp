#if !defined(BRACKET_PUSH_H)
#define BRACKET_PUSH_H

#include <vector>

namespace bracket_push {
    bool check(const char *expression) {
        std::string stack;

        for (auto character : std::string(expression))
            switch (character) {
                case '(':
                    stack.push_back(')');
                    break;
                case '{':
                    stack.push_back('}');
                    break;
                case '[':
                    stack.push_back(']');
                    break;
                case ')':
                case '}':
                case ']':
                    if (stack.size() == 0 || character != stack.back())
                        return false;

                    stack.pop_back();
            }

        return stack.size() == 0;
    }
}

#endif

//
//  This solution uses a switch and makes the pop common.
//
//  Well, all but one of the solutions examined where over complicated or long
//  winded suggesting folk started coding and end up digging themselves out of
//  a hole.  Perhaps the problem sounds easier than it is.
//
//  Almost all used std::stack but this did not help.  std::string or
//  std::vector are perfectly adequate.
//


