
#include <algorithm>
#include <iterator>
#include <set>

#include "halfsumfinder.h"


void fillSumsFrom (const ValPosVec &data, LLVec &sums)
{
    long long sum = 0;

    sums.reserve (data.size ());

//    std::transform (&data[0], &data[0] + data.size (), std::back_inserter (sums),
//            [&sum] (const ValPos &vp)
//    {
//        return sum += vp.value;
//    });
    for (int i = 0; i < data.size (); ++i) {
        sum += data[i].value;
        sums.push_back (sum);
    }
}


HalfSumFinder::HalfSumFinder (const ValPosVec &data)
    : data (data), alternativesSeen (0)
{
    fillSumsFrom (data, sums);

    Set::setItems (&data);

    solution.reserve (10);
}


bool HalfSumFinder::find ()
{
    if ((sums.back () & 1) != 0)
        return false;

    return find (sums.back () / 2, data.size ());
}


void removeSetsFromQueue (std::set <Set, SetPComp> &queue)
{
    for (Set s : queue)
        Set::removeSet (s);
}


bool HalfSumFinder::find (long long desired, size_t endItemI)
{
    ++alternativesSeen;

    LLVec::const_iterator lb = std::lower_bound (sums.begin (), sums.begin () + endItemI,
                                                 desired);
    size_t lbPos = lb - sums.begin ();

    if (lbPos == endItemI)
        return false;


    Set s = Set::addSet (*lb, lbPos, endItemI);

    if (*lb == desired) {
        solution.push_back (s);
        return true;
    }


    std::set <Set, SetPComp> queue;

    queue.insert (s);


    while (!queue.empty ()) {

        s = *queue.begin ();

        long long sumDiff = s.getSum () - desired;

        assert (lbPos > 0);

        if (sumDiff > sums[lbPos - 1]) {
            removeSetsFromQueue (queue);
            break;
        }


        queue.erase (queue.begin ());

        if (sumDiff >= data.front ().value) {

            if (find (sumDiff, lbPos)) {
                removeSetsFromQueue (queue);
                solution.push_back (s);
                return true;
            }
        }


        ++alternativesSeen;

        Set s1;

        do {

            s1 = s.genNext ();

            if (s1.isNull ())
                break;


            std::pair <std::set <Set, SetPComp>::iterator, bool> ib = queue.insert (s1);

            if (!ib.second)
#ifdef _MSC_VER  // msvc iterators behave specifically
                if (s1 != s) {
                    Set::removeSet (s1);
                    continue;
                } else
#endif
                Set::removeSet (s1);

        } while (s1 != s);

        if (s1.isNull ())
            Set::removeSet (s);
    }


    return false;
}
