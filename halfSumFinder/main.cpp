
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <valarray>

#include "../src/halfsumfinder.h"


void inputData (ValPosVec &data)
{
#if 0
    int n;


    std::cin >> n;

    data.reserve (n);


    for (int i = 0; i < data.capacity (); ++i) {

        int num;


        std::cin >> num;

        data.emplace_back (num, i + 1);
    }
#else
    char nmBuf[9];

    fgets (nmBuf, 9, stdin);

    long n = strtoul (nmBuf, 0, 10);

    data.reserve (n);


   std::valarray <char> v (n * 11 + 3);

   fgets (&v[0], v.size (), stdin);

   char *s = &v[0];

   for (int i = 0; i < data.capacity (); ++i) {

       int num = strtoul (s, &s, 10);

       data.emplace_back (num, i + 1);
   }
#endif
}


#define LEN_WIDTH 8


void sprint (const ValPosVec &data, int startI, int endI, char *s[2], int setSize[2], int sI)
{
    for (int i = startI; i < endI; ++i)
        s[sI] += sprintf (s[sI], "%d ", data[i].pos);

    setSize[sI] += endI - startI;
}


void printSolution (const HalfSumFinder &hsf, const ValPosVec &data)
{
    printf ("YES\n");

    size_t sSize = LEN_WIDTH + 6 * 100000 + 2;
    std::valarray <char> v1 (sSize), v2 (sSize);

    const SetPVec &sln = hsf.getSolution ();
    int setSize[2] = {0, 0};
    char *s[2] = {&v1[LEN_WIDTH], &v2[LEN_WIDTH]};
    int sI = (sln.size () & 1) == 0;


    sprint (data, 0, sln.front ().getRangeStartI (), s, setSize, sI);

    for (SetPVec::const_iterator i = sln.begin (); i != sln.end (); ++i) {

        const Set set = *i;

        sprint (data, set.getRangeStartI (), *set.begin (), s, setSize, sI ^ 1);

        for (Set::const_iterator i1 = set.begin (), i2 = ++set.begin ();
             i1 != set.end (); i1 = i2, ++i2) {

            s[sI] += sprintf (s[sI], "%d ", data[*i1].pos);
//            printf ("set %d, dataIdx %d, pos %d\n", sI, *i1, data[*i1].pos);
            ++setSize[sI];

            sprint (data, *i1 + 1, i2 != set.end () ? *i2 : set.getRangeEndI (),
                    s, setSize, sI ^ 1);
        }

        sI ^= 1;
    }


    int l1 = sprintf (&v1[0], "%d\n", setSize[0]);
    int l2 = sprintf (&v2[0], "%d\n", setSize[1]);
    int pos1 = LEN_WIDTH - l1;
    int pos2 = LEN_WIDTH - l2;

    memmove (&v1[pos1], &v1[0], l1);
    memmove (&v2[pos2], &v2[0], l2);

    printf ("%s\n", &v1[pos1]);
    printf ("%s\n", &v2[pos2]);

    assert (setSize[0] + setSize[1] == data.size ());
}


bool parseProgramOptions (int argc, char */*argv*/[])
{
    if (argc > 1) {
        printf ("This program groups numbers from integer array into two subsets "
                "with equal sums.\n"
                "Input (from stdin):\n"
                "\t<input_numbers_COUNT><LF>\n"
                "\t<COUNT_space-separated_integer_numbers><LF>\n"
                "Output (to stdout):\n"
                "\tYES<LF>\n"
                "\t<1st_subset_SIZE1><LF>\n"
                "\t<SIZE1_space-separated_integer_numbers><LF>\n"
                "\t<2nd_subset_SIZE2><LF>\n"
                "\t<SIZE2_space-separated_integer_numbers><LF>\n"
                "    or:\n"
                "\tNO<LF>\n\n");
        return false;
    }


    return true;
}


int main (int argc, char *argv[])
{
    if (!parseProgramOptions (argc, argv))
        return 1;


    ValPosVec data;

    inputData (data);


    std::sort (&data[0], &data[0] + data.size (),
            [] (const ValPos &vp1, const ValPos &vp2)
    { return vp1.value < vp2.value; });


    HalfSumFinder hsf (data);

    if (hsf.find ())
        printSolution (hsf, data);
    else
        printf ("NO\n");


    return 0;
}
