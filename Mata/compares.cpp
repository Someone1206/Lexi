#include "../Mata.hpp"
#include "defs.hpp"

int Mata::cmpVal(const Mata &to)
{
    if (m_type == UNKNOWN)
        return false;

    if (m_type != to.m_type)
        return false;

    switch (m_type)
    {
    case INT:
        return cmp(long, to.m_data);
    case FLOAT:
        return cmp(double, to.m_data);
    case STR:
        return cmp(std::string, to.m_data);
    case ARR:
        return -1;
    }
    return -2;
}

bool Mata::cmpInt(long to)
{
    if (m_type != INT)
        return false;
    return cmpr(long, to);
}

bool Mata::cmpFloat(double to)
{
    if (m_type != FLOAT)
        return false;
    return cmpr(double, to);
}

bool Mata::cmpStr(const std::string &to)
{
    if (m_type != STR)
        return false;
    return cmpr(std::string, to);
}