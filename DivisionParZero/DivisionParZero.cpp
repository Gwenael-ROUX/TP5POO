/**
 *
 * \file   : SqueletteMain.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
    double divisionEntiere (int  d1, int  d2) throw (CException)
    {
        if (d2 == 0)
            throw CException ("Division par 0", 256);
        return d1/d2;
    }

//    void testDivisionParZero (void)
//    {
//        try
//        {

//        }

//        catch (CException & e)
//        {

//        }

//    } // TestFailure  ()

} // namespace

int main (void)
{
    try
    {
        divisionEntiere (5,0);
        return KNoExc;
    }
    catch (const CException & e)
    {
        e.display();
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
