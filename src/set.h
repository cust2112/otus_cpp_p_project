#ifndef SET_H
#define SET_H

#undef NDEBUG

#include <cassert>
#include <vector>
#include <list>


struct ValPos
{
    ValPos (int value, int pos) : value (value), pos (pos) {}

    int value, pos;
};


typedef std::vector <ValPos> ValPosVec;
typedef std::vector <long long> LLVec;
typedef std::vector <int> IntVec;


class Set {
private:
    struct SetImpl
    {
        SetImpl (long long sum, int beginItemI, int endItemI);
        SetImpl (long long sum, int dataI, int beginItemI, int endItemI, int curII);

        long long sum;
        int dataI;
        int beginItemI, endItemI;
        int curII;


        typedef std::list <SetImpl> SetImpls;

        static IntVec data;
        static SetImpls setsBusy, setsFree;
        static const ValPosVec *items;

        static IntVec initData ();
        static void resizeData (size_t size);

        SetImpls::iterator copyFromThisAddingNextItem () const;
        int findIndex2Increment () const;
        SetImpls::iterator copyFromThis () const;
    };


    SetImpl::SetImpls::iterator i;

    Set (SetImpl::SetImpls::iterator i) noexcept : i (i) {}

    template <typename... Args>
    static SetImpl::SetImpls::iterator employSetImpl (Args&&... args)//;
    {
        if (SetImpl::setsFree.empty ()) {
            assert (SetImpl::setsBusy.size () * sizeof (SetImpl::setsBusy.front ()) < 1000000000);
            SetImpl::setsBusy.emplace (SetImpl::setsBusy.begin (), std::forward<Args> (args)...);
        } else {
            SetImpl::setsBusy.splice (SetImpl::setsBusy.begin (), SetImpl::setsFree,
                                      SetImpl::setsFree.begin ());
            SetImpl::setsBusy.front () = SetImpl (std::forward<Args> (args)...);
        }


        return SetImpl::setsBusy.begin ();
    }

#ifdef _MSC_VER
#define SETIMPL_SETIMPLS_EMPTY_ITER SetImpl::setsBusy.end ()
#else
#define SETIMPL_SETIMPLS_EMPTY_ITER SetImpl::SetImpls::iterator ()
#endif


public:
    Set () : i (SETIMPL_SETIMPLS_EMPTY_ITER) {}

    static void setItems (const ValPosVec *items) { Set::SetImpl::items = items; }

    static Set addSet (long long sum, int beginItemI, int endItemI);
    static void removeSet (Set s);
    Set genNext ();

    long long getSum () const { return i->sum; }

    bool isNull () const { return i == SETIMPL_SETIMPLS_EMPTY_ITER; }

    int getRangeStartI () const { return i->beginItemI; }
    int getRangeEndI () const { return i->endItemI; }

    static int getSetsBusySize () { return SetImpl::setsBusy.size (); }
    static int getSetsFreeSize () { return SetImpl::setsFree.size (); }
    static void freeSets ();


    struct const_iterator
    {
        typedef size_t difference_type;
        typedef int value_type;
        typedef int* pointer;
        typedef int& reference;
        typedef std::forward_iterator_tag iterator_category;

        const_iterator (int ii) : ii (ii) {}

        const_iterator &operator++ () { ++ii;  return *this; }
        int operator* () const { return SetImpl::data[ii]; }

        friend bool operator!= (const_iterator i1, const_iterator i2)
        {
            return i1.ii != i2.ii;
        }

    private:
        int ii;
    };

    const_iterator begin () const { return const_iterator (i->dataI + 1); }
    const_iterator end () const { return const_iterator (i->dataI + SetImpl::data[i->dataI] + 1); }


    friend bool operator!= (const Set s1, const Set s2)
    {
        return s1.i != s2.i;
    }
};


struct SetPComp
{
    bool operator() (const Set s1, const Set s2) const
    {
        return s1.getSum () < s2.getSum ();
    }
};


#endif // SET_H
