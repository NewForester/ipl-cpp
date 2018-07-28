#if !defined(DNA_RNA_H)
#define DNA_RNA_H

#include <string>

namespace transcription {

    char to_rna(char nucleotide) {
        switch (nucleotide) {
            case 'G':   return 'C';
            case 'C':   return 'G';
            case 'T':   return 'A';
            case 'A':   return 'U';
        }
    }

    std::string to_rna(const std::string strand) {
        std::string  rna;

        for (auto nucleotide : strand)
            rna.push_back(to_rna(nucleotide));

        return rna;
    }
}

#endif

//
//  This solution makes this exercise look really trivial.  It has two errors.
//
//  There are four questions any solution must answer.  The solutions examined
//  shows a variety of responses.
//
//  One is what to do with invalid input.  I was not the only one to leave this
//  undefined (I did it by mistake).  Some raised an exception, very C++.  One
//  transcribed invalid nucleotides to '\0' so embedding nulls in a string.
//
//  Another question is transcribe in-place or return a new string ?  Mine
//  does the latter but makes no attempt to reserve enough space beforehand.
//  This is a string so assume it is efficient to do so.  Those solutions that
//  transcribed in-place passed the input by value so saved nothing.
//
//  Next is whether to use a simple loop, call transform or call for_each.  I
//  looked for_each up again and it is inappropriate:  use transform.  For a
//  problem as trivial as this why go to the trouble of using transform?  Why
//  go to the trouble of using transform anyway ?
//
//  Lastly, how to transcribe a single letter ?  A couple of solutions used a
//  map, which is nicely extendible but here is overkill.  Most used a switch
//  statement but a couple used find and an index.
//
