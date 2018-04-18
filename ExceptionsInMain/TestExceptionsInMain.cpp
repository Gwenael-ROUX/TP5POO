#include <iostream>
#include "CException.h"
#include "CstCodErr.h"

using namespace std;
using namespace nsUtil;

char ChoixMenu (void){
    char c;
    cout << "Choisissez votre exception" << endl
         << "A - exception" << endl
         << "B - run-time" << endl
         << "C - CException" << endl
         << "D - inconnue" << endl;
    cin >> c;
    return c;

}

namespace {
        void testExceptionsInMain(char c)
        {
                if (c == 'A')
                    throw exception();
                else if (c == 'B')
                    throw runtime_error("Cadeau");
                else if (c == 'C')
                    throw CException ("Surprise", 6220);
                else if (c == 'D')
                    throw 25;
                else if (c == 'E')
                    throw 25;
        }
}

int main ()
{
    try
    {
        char c;
        c = ChoixMenu();
        testExceptionsInMain(c);
        return KNoExc;
    }

    catch (CException & e)
    {
        e.display();
        return e.getCodErr();
    }

    catch (runtime_error & e)
    {
        cerr << e.what();
        return KExcStd;
    }

    catch (exception & e)
    {
       cerr << e.what();
       return KExcStd;
    }
    catch (int & e)
    {

        cerr << "Autres erreur";
        return KExcStd;
    }
    catch (...)
    {
        cerr << "erreur inconnue";
        return KExcInconnue;
    }
}
