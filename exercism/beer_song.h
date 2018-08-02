#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>
#include <sstream>

namespace beer {
    const char *oneOrMore(int howMany, const char *one, const char *many) {
        return howMany == 1 ? one : many;
    }

    std::string verse(int which) {
        std::stringstream verse;

        if (which == 0) {
            verse << "No more bottles of beer on the wall, ";
            verse << "no more bottles of beer.\n";
            verse << "Go to the store and buy some more, ";
            which = 99;
        } else {
            verse << which << oneOrMore(which, " bottle", " bottles") << " of beer on the wall, ";
            verse << which << oneOrMore(which, " bottle", " bottles") << " of beer.\n";
            verse << "Take " << oneOrMore(which, "it", "one") << " down and pass it around, ";
            which--;
        }

        if (which == 0)
            verse << "no more bottles of beer on the wall.\n";
        else
            verse << which << oneOrMore(which, " bottle", " bottles") << " of beer on the wall.\n";

        return verse.str();
    }

    std::string sing(int from, int to = 0) {
        std::stringstream verses;

        verses << verse(from);

        while (--from >= to) {
            verses << "\n";
            verses << verse(from);
        }

        return verses.str();
    }
}

#endif

//
//  This solution is compact but handles singular/plural at run-time.
//
//  One could 'solve' this with a lookup table of verses and minimal code.
//  That would be very clear and simple to understand.  There is considerable
//  scope for generating the verses using less text and more code.  The further
//  one takes that process the less clear the final code.
//
//  All solutions attempted some level of 'optimisation'.  Most had a routine
//  to handle bottle/bottles.  Some used stringstream.  I think my solution
//  achieved a good balance and I feel the stringstream solutions were
//  clearer than those that used string concatenation.
//
//  Three routines were asked for and some supplied them but many spotted the
//  case for the default parameter.  A simple verse loop in sing() adds one
//  newline two many.  I prefer solutions that don't add it in the first place
//  over those that take one off at the end.
//
//  Finally, one chap implemented a class instead of a namespace and was
//  criticised for it.  Why ?
//
