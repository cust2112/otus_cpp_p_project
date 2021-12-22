
#include <cstring>

#include "set.h"


IntVec Set::SetImpl::data = Set::SetImpl::initData ();
Set::SetImpl::SetImpls Set::SetImpl::setsBusy;
Set::SetImpl::SetImpls Set::SetImpl::setsFree;
const ValPosVec *Set::SetImpl::items = 0;


Set Set::addSet (long long sum, int beginItemI, int endItemI)
{
    return employSetImpl (sum, beginItemI, endItemI);
}


void Set::removeSet (Set /*&*/s)
{
//    if (s.i != SETIMPL_SETIMPLS_EMPTY_ITER) {

        SetImpl::setsFree.splice (SetImpl::setsFree.begin (), SetImpl::setsBusy, s.i);

        s.i = SETIMPL_SETIMPLS_EMPTY_ITER;
//    }
}


Set Set::genNext ()
{
    if (i->curII == 0)
        return Set ();


    if (i->curII > SetImpl::data[i->dataI]) {

        if (SetImpl::data[i->dataI] == i->endItemI - i->beginItemI)
            return Set ();
        else {

            Set s = i->copyFromThisAddingNextItem ();

            --i->curII;

            return s;
        }

    } else {

        i->curII = i->findIndex2Increment ();

        if (i->curII == 0 || SetImpl::data[i->dataI + i->curII] == i->endItemI - 1)
            return Set ();

        if (i->curII == 1) {

            int &curItemI = SetImpl::data[i->dataI + i->curII];

            i->sum += (*SetImpl::items)[curItemI + 1].value -
                      (*SetImpl::items)[curItemI].value;
            ++curItemI;

//            i->curII = SetImpl::data[i->dataI]; // this increases redundancy

            return *this;
        }

        Set s = i->copyFromThis ();
        int &curItemI = SetImpl::data[s.i->dataI + i->curII];

        assert (curItemI < s.i->endItemI);

        s.i->sum += (*SetImpl::items)[curItemI + 1].value -
                    (*SetImpl::items)[curItemI].value;
        ++curItemI;
        --i->curII;

        return s;
    }
}


void Set::freeSets ()
{
    SetImpl::setsFree.splice (SetImpl::setsFree.begin (), SetImpl::setsBusy);
}


Set::SetImpl::SetImpl (long long sum, int beginItemI, int endItemI)
    : sum (sum), dataI (data.size ()), beginItemI (beginItemI), endItemI (endItemI),
      curII (2)
{
    if (data.size () * sizeof (data[0]) > 1000000000)
        assert (false);

    data.push_back (1);
    data.push_back (beginItemI);
}


Set::SetImpl::SetImpl (long long sum, int dataI, int beginItemI, int endItemI, int curII)
    : sum (sum), dataI (dataI), beginItemI (beginItemI), endItemI (endItemI),
      curII (curII) {
}


IntVec Set::SetImpl::initData ()
{
    IntVec data;

    data.reserve (1000000);

    return data;
}


void Set::SetImpl::resizeData (size_t size)
{
    if (data.size () * sizeof (data[0]) > 1000000000)
        assert (false);

    data.resize (size);
}


Set::SetImpl::SetImpls::iterator Set::SetImpl::copyFromThisAddingNextItem () const
{
    int nextDataI = data.size ();


    resizeData (data.size () + data[dataI] + 2);

    data[nextDataI] = data[dataI] + 1;
    memcpy (&data[nextDataI + 1], &data[dataI + 1], data[dataI] * sizeof (data[0]));
    data.back () = beginItemI + data[dataI];


    return employSetImpl (sum + (*items)[data.back ()].value, nextDataI, beginItemI,
            endItemI, data[nextDataI] + 1);
}


int Set::SetImpl::findIndex2Increment () const
{
    int ii = curII;

    if (ii == data[dataI]) {

        if (data[dataI + ii] == endItemI - 1) {

            --ii;

            while (ii > 0 && data[dataI + ii] == data[dataI + ii + 1] - 1)
                --ii;
        }

    } else
        while (ii > 0 && data[dataI + ii] == data[dataI + ii + 1] - 1)
            --ii;

    return ii;
}


Set::SetImpl::SetImpls::iterator Set::SetImpl::copyFromThis () const
{
    int nextDataI = data.size ();


    resizeData (data.size () + data[dataI] + 1);

    data[nextDataI] = data[dataI];
    memcpy (&data[nextDataI + 1], &data[dataI + 1], data[dataI] * sizeof (data[0]));


    return employSetImpl (sum, nextDataI, beginItemI, endItemI,
                          /*data[nextDataI]*/curII);  // <- eliminates redundancy!
}
