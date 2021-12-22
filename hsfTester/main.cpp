
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iterator>
#include <sstream>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "../src/halfsumfinder.h"
#include "../util/gendata.h"
#include "../util/timer.h"


namespace po = boost::program_options;


void printSets (const SetPVec &sln, const ValPosVec &/*data*/)
{
    int i = 1;

    printf ("Sorted array indeces to sets distribution:\n");

    if (sln.begin ()->getRangeStartI () > 0) {
        printf ("  indeces [0;%d] - set 0\n", sln.begin ()->getRangeStartI () - 1);
    }

    for (const Set set : sln) {

        Set::const_iterator i1 = set.begin ();

        printf ("  indeces [%d;%d]: {%d", set.getRangeStartI (),
                set.getRangeEndI () - 1, *i1);

        for (++i1; i1 != set.end (); ++i1)
            printf (", %d", *i1);

        printf ("} - set %d", i & 1 ^ 1);

        if (set.getRangeEndI () - set.getRangeStartI () >
                std::distance (set.begin (), set.end ()))
            printf (", the rest - set %d", i & 1);

        printf ("\n");

        ++i;
    }
}


//int beginSeed, endSeed, maxValue, datasetSize;
int beginSeed = 0, endSeed = 30, maxValue = 1000000000, datasetSize = 100000;


void maxValueNotifier (int maxValue)
{
    if (maxValue < 0 || maxValue > 1000000000)
        throw std::runtime_error ("Incorrect maxValue parameter");
}


void datasetSizeNotifier (int datasetSize)
{
    if (datasetSize < 2 || datasetSize > 1000000)
        throw std::runtime_error ("Incorrect dataset size");
}


bool parseProgramOptions (int argc, char *argv[])
{
    po::options_description desc ("Allowed options");

    desc.add_options ()
        ("help,h", "produce help message")
        ("beginSeed,b", po::value <int> (&beginSeed)->default_value (0),
             "random generator seed to start from when generating input datasets")
        ("endSeed,e", po::value <int> (&endSeed)->default_value (30),
             "random generator seed to end with when generating input datasets")
        ("maxValue,m",
             po::value <int> (&maxValue)->default_value (1000000000)
             ->notifier (maxValueNotifier),
             "maximum random input value from 0 to 1000000000 "
             "(minimum input value is always 0)")
        ("dataset-size,s", po::value <int> (&datasetSize)->default_value (100000)
             ->notifier (datasetSizeNotifier),
             "number of input values in a dataset from 2 to 1000000")
    ;

//    po::positional_options_description p;

    po::variables_map vm;

    try {
        po::store (po::command_line_parser (argc, argv).
                   options (desc)/*.positional (p)*/.run (), vm);
        po::notify (vm);
    } catch (std::exception &e) {
        printf ("%s\n", e.what ());
        return false;
    }


    bool printHelpOnly = vm.count ("help") != 0;

    if (printHelpOnly) {
        printf ("Usage: hsfTester [options]\n%s",
                ((std::stringstream &) (std::stringstream () << desc)).str ().c_str ());
        return false;
    }


    return true;
}


int main (int argc, char *argv[])
{
    if (!parseProgramOptions (argc, argv))
        return 1;


    for (int i = beginSeed; i < endSeed; ++i) {

        ValPosVec data;

        printf ("Random seed %d\n", i);

        genData (data, i, datasetSize, maxValue);


        START_TIMER ("Sorting data");
        std::sort (&data[0], &data[0] + data.size (),
                [] (const ValPos &vp1, const ValPos &vp2)
        { return vp1.value < vp2.value; });
        STOP_TIMER ("");


        START_TIMER ("Solution search");
        HalfSumFinder hsf (data);
        bool found = hsf.find ();

        printf ("Solution exists: ");

        if (found) {
            printf ("YES\n");
            printSets (hsf.getSolution (), data);
        } else
            printf ("NO\n");

        printf ("\"Set\" structs allocated in a pool: %d - busy, %d - already free\n",
                (int) Set::getSetsBusySize (), (int) Set::getSetsFreeSize ());
        printf ("Alternatives seen: %d\n", (int) hsf.getAlternativesSeen ());
        STOP_TIMER ("");

        printf ("\n");

        Set::freeSets ();
    }


    return 0;
}
