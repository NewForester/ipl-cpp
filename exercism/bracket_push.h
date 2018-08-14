#if !defined(BRACKET_PUSH_H)
#define BRACKET_PUSH_H

#include <stack>
#include <string>

namespace bracket_push {
    const std::string brackets = "(){}[]";

    bool check(const char *expression) {
        std::stack<size_t> stack;

        for (auto character : std::string(expression))
            switch (size_t index = brackets.find(character)) {
                case 0:
                case 2:
                case 4:
                    stack.push(index + 1);
                    break;
                case 1:
                case 3:
                case 5:
                    if (stack.empty() || stack.top() != index)
                        return false;

                    stack.pop();
            }

        return stack.empty();
    }
}

#endif

//
//  This solution uses std::stack instead of std::vector.
//
//  It still uses a switch but now has two simple cases.  It is not, in terms
//  of lines, any shorter that the previous solution.
//
