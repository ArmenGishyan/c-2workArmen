#include "IntegerToRoman.h"



IntegerToRoman::IntegerToRoman(const unsigned int &changableNumber)
{
    if(changableNumber>=4449)
    {
        std::cerr<<"ERROR \n Number must be less than 4449\n";
        std::terminate();
    }
    m_Number=changableNumber;
    this->addCharacter('I');
    this->addCharacter('V');
    this->addCharacter('X');
    this->addCharacter('L');
    this->addCharacter('C');
    this->addCharacter('D');
    this->addCharacter('M');
}
IntegerToRoman::IntegerToRoman()
{
    std::cout<<"Default Costructor\n";
}

std::vector<unsigned int> IntegerToRoman::getNumberVector()
{
    std::vector<unsigned int > vec_Number;
    int value=0;
    while(m_Number!=0)
    {
        vec_Number.push_back(m_Number%10);
        m_Number=int(m_Number/10);
    }
    return vec_Number;
}

void IntegerToRoman::addCharacter(const char ch)
{
    m_MRomInteger.push_back(ch);
}

std::string IntegerToRoman::MakeRomanNumber()
{
    std::vector<unsigned int> numVec=getNumberVector();
    std::string RomNumber="";
    std::copy(numVec.begin(),numVec.end(),std::ostream_iterator<unsigned int> (std::cout,","));

    int index=0;

    for(int i=0;i<numVec.size();i++)
    {
        if(numVec[i]<=5)
        {
            RomNumber.insert(0,blabla(index,index+1,numVec[i]));
            RomNumber+=',';
        }
        else
        {
            RomNumber.insert(0,blabla(index+1,index+2,numVec[i]));
            RomNumber+=',';
        }
        index+=2;

    }
    return RomNumber;
}

std::string IntegerToRoman::blabla(int start, int end,int number)
{
    std::string str="";
    switch (number)
    {
        case 0:
            {
                return "";
            }
        case 1:
            {
                str=m_MRomInteger[start];
                return str;
            }
        case 2:
            {
                str=m_MRomInteger[start];
                str+=m_MRomInteger[start];
                return str;
            }
        case 3:
            {
                str=m_MRomInteger[start];
                str+=m_MRomInteger[start];
                str+=m_MRomInteger[start];  
                return str; 
            }
        case 4:
            {
                str=m_MRomInteger[start];
                str+=m_MRomInteger[end];
                return str;
            }
        case 5:
            {
                str=m_MRomInteger[end];
                return str;
            }
        case 6:
            {
                str=m_MRomInteger[start];
                str=+m_MRomInteger[start-1];
                return str;
            }
        case 7:
            {
                str=m_MRomInteger[start];
                str=+m_MRomInteger[start-1];
                str=+m_MRomInteger[start-1];
                return str;
            }
        case 8:
            {
                str=m_MRomInteger[start];
                str=+m_MRomInteger[start-1];
                str=+m_MRomInteger[start-1];
                str=+m_MRomInteger[start-1];
                return str;
            }
        case 9:
            {
                str=m_MRomInteger[start-1];
                str+=m_MRomInteger[end];
                return str;
            }
    }
}
