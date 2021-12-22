
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>


typedef std::vector<int> IntVec;


std::string inFName, resFName;


void printHelp ()
{
    printf ("This program verifies the result of Half-sum Finder's work: reads its input "
            "data and the result, then calculates subsets' sums.\n\n"
            "Usage: hsfOutputVerifier <input_file_name> <HsF_result_file_name>\n\n"
            "    where input file may be hsfInputGenerator's output, redirected to a file,\n"
            "          HsF result file is halfSumFinder's output, redirected to a file.\n\n");
}


bool parseProgramOptions (int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!strcmp (argv[i], "-h") || !strcmp (argv[i], "--help") ||
                !strcmp (argv[i], "/?")) {
            printHelp ();
            return false;
        }

    if (argc != 3) {
        printHelp ();
        return false;
    }


    inFName = argv[1], resFName = argv[2];


    return true;
}


int readIntFrom (std::istream &f)
{
    std::string s;
    int i;

    std::getline (f, s);

    i = (int) strtol (s.c_str (), 0, 10);

    return i;
}


void readIntVecFrom (std::istream &f, IntVec &vec)
{
    std::string s;

    std::getline (f, s);


    std::istringstream ss (s);
    int i;

    while (ss >> i)
        vec.push_back (i);
}


long long sumIndexedArray (const IntVec &array, const IntVec &indeces)
{
    long long sum = 0;

    for (int i : indeces)
        sum += array[i - 1];  // indeces start from 1

    return sum;
}


int main (int argc, char *argv[])
{
    if (!parseProgramOptions (argc, argv))
        return 1;


    IntVec input, indeces1, indeces2;

    std::ifstream inF (inFName);

    if (!inF) {
        printf ("Could't open file %s\n", inFName.c_str ());
        return 2;
    }

    int inputSize = readIntFrom (inF);

    input.reserve (inputSize);

    readIntVecFrom (inF, input);

    inF.close ();


    std::ifstream resF (resFName);
    std::string s;

    if (!resF) {
        printf ("Could't open file %s\n", resFName.c_str ());
        return 2;
    }

    std::getline (resF, s);

    if (s == "NO") {
        printf ("Half-sum Finder reported NO solution\n");
        return 0;
    }

    int size1 = readIntFrom (resF);

    indeces1.reserve (size1);

    readIntVecFrom (resF, indeces1);

    int size2 = readIntFrom (resF);

    indeces2.reserve (size2);

    readIntVecFrom (resF, indeces2);

    resF.close ();


    long long sum1 = sumIndexedArray (input, indeces1);
    long long sum2 = sumIndexedArray (input, indeces2);

    printf ("sum1 = %lld, sum2 = %lld\n", sum1, sum2);

    if (sum1 == sum2)
        printf ("Success: sums are the same.\n");
    else
        printf ("Error detected: sums differ!\n");


    return 0;
}
