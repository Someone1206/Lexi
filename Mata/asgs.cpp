#include "../Mata.hpp"
#include "defs.hpp"
#include <string.h>

void Mata::assignInt(long val)
{
    crasg(SIZE);
    assgnr(long, val);
    m_type = INT;
}

void Mata::assignFloat(double val)
{
    crasg(SIZE);
    assgnr(double, val);
    m_type = FLOAT;
}

void Mata::assignStr(const std::string &from)
{

    if (m_arrlen != sizeof(std::string))
    {
        if (m_data != nullptr)
        {
            free(m_data);
        }
        m_data = malloc(sizeof(std::string));
    }
    else if (m_data == nullptr)
    {
        m_data = malloc(sizeof(std::string));
    }
    m_type = STR;
    m_arrlen = sizeof(std::string);
    assgnr(std::string, from);
}

void Mata::assignArr(const uint8_t *arr, size_t sz)
{
    if (m_arrlen != sz)
    {
        if (m_data != nullptr)
        {
            free(m_data);
        }
        m_data = malloc(sz);
    }
    else if (m_data == nullptr)
    {
        m_data = malloc(sz);
    }
    m_arrlen = sz;
    m_type = ARR;
    memcpy(m_data, arr, sz);
}