
#include <cstdio>
#include <sstream>

#include <boost/program_options.hpp>

#include "../util/gendata.h"


namespace po = boost::program_options;


int randomSeed = 0, maxValue = 1000000000, datasetSize = 100000;


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
        ("randomSeed,r", po::value <int> (&randomSeed)->default_value (0),
             "random seed for generating input dataset")
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
        printf ("Usage: hsfInputGenerator [options]\n%s",
                ((std::stringstream &) (std::stringstream () << desc)).str ().c_str ());
        return false;
    }


    return true;
}


int main (int argc, char *argv[])
{
    if (!parseProgramOptions (argc, argv))
        return 1;


    ValPosVec data;

    genData (data, randomSeed, datasetSize, maxValue);


    puts (std::to_string (data.size ()).c_str ());

    for (const ValPos &vp : data)
        printf ("%s ",std::to_string (vp.value).c_str ());

    puts ("");


    return 0;
}
