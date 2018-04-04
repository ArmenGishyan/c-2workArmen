#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

typedef std::map<unsigned int,char> m_RomInt;
typedef std::pair<unsigned int,char> m_MapType;
class IntegerToRoman
{
    private:
        unsigned int m_Number;
        std::vector<char> m_MRomInteger;
    public:
        IntegerToRoman(const unsigned int &changableNumber);
        IntegerToRoman();
        std::vector<unsigned int> getNumberVector();
        void addCharacter(const char ch);
        std::string MakeRomanNumber();

        std::string blabla(int start, int end,int number);
};