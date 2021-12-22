
#include <cassert>
#include <iostream>
#include <set>
#include <valarray>

#include "../src/set.h"


void printSum (long long sum, bool hidden = false)
{
    if (hidden)
        std::cout << '\t';

    for (int i = 7; i >= 0; --i)
        std::cout << (char) ('0' + ((sum & (1 << i)) != 0));

    std::cout << ' ' << sum;
}


void printHist (const std::valarray <int> &hist)
{
    for (int i = 0; i < hist.size (); ++i)
        std::cout << i << " " << hist[i] << std::endl;
}


int bits = 6;


void printHelp ()
{
    printf ("This program demonstrates the order of numbers distributions lookup "
            "in Half-sum Finder (described with bitmaps since we distribute numbers "
            "over two subsets).\n\n"
            "Usage: hsfSearchOrderDemo [bitmap_width]\n\n"
            "\twhere 2<=bitmap_width<=16 (to avoid extreme amount of output), "
            "6 is the default.\n\n");
}

bool parseProgramOptions (int argc, char *argv[])
{
    if (argc == 1)
        return true;

    if (argc > 2) {
        printHelp ();
        return false;
    }


    char *endPtr;

    bits = (int) strtol (argv[1], &endPtr, 10);

    if (endPtr == argv[1] || !(bits >= 2 && bits <= 16)) {
        printHelp ();
        return false;
    }


    return true;
}


int main (int argc, char *argv[])
{
    if (!parseProgramOptions (argc, argv))
        return 1;


    ValPosVec items;

    for (int i = 0; i < bits; ++i)
        items.emplace_back (1 << i, i);


    Set::setItems (&items);

    std::set <Set, SetPComp> queue;

    queue.insert (Set::addSet (1, 0, items.size ()));

    long long prevSum = 0;
    int distinct = (1 << bits) - 1;  // 2^bits minus "0000..."
    std::valarray <int> hist (0, distinct);

    ++hist[(*queue.begin ()).getSum () - 1];


    while (!queue.empty ()) {

        Set s = *queue.begin ();

        std::cout << "from ";
        printSum (s.getSum ());
        std::cout << " we generate:\n";

        assert (prevSum < s.getSum ());
        prevSum = s.getSum ();


        queue.erase (queue.begin ());

        Set s1;

        do {
            s1 = s.genNext ();

            if (s1.isNull ())
                break;


            printSum (s1.getSum (), true);
            ++hist[s1.getSum () - 1];

//            if (s.getSum () == 5)
//                assert (prevSum == s.getSum ());

            std::pair <std::set <Set, SetPComp>::iterator, bool> ib = queue.insert (s1);

            if (!ib.second) {
                std::cout << " - already enqueued, discarded ";
                Set::removeSet (s1);
            }

            std::cout << std::endl;

        } while (s1 != s);

        if (s1.isNull ())
           Set::removeSet (s);

        std::cout << "----------------------" << std::endl;
    }


    std::cout << "States generated: " << hist.sum () << std::endl;
    std::cout << "Distinct states: " << distinct;
    std::cout << ", so redundancy coefficient: " << (double) hist.sum () / distinct
              << std::endl;
    std::cout << "Each state was generated at least: " << hist.min () << " times,";
    std::cout << " but not more than: " << hist.max () << " times"
              << std::endl;
//    printHist (hist);

    Set::freeSets ();


    return 0;
}
