#ifndef HALFSUMFINDER_H
#define HALFSUMFINDER_H

#include "set.h"


typedef std::vector <Set> SetPVec;


class HalfSumFinder {
public:
    HalfSumFinder (const ValPosVec &data);

    bool find ();

    const SetPVec &getSolution () const { return solution; }
    size_t getDataSize () const { return data.size (); }
    size_t getAlternativesSeen () const { return alternativesSeen; }


private:
    const ValPosVec &data;
    LLVec sums;
    SetPVec solution;
    size_t alternativesSeen;

    bool find (long long desired, size_t endItemI);
};


#endif // HALFSUMFINDER_H
