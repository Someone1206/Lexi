#include "../Mata.hpp"
#include "defs.hpp"
#include <string.h>

Mata::Mata()
    : m_data(nullptr), m_type(UNKNOWN), m_arrlen(SIZE) {}

Mata::Mata(const Mata &from)
    : m_type(from.m_type), m_arrlen(from.m_arrlen)
{
    if (m_type != UNKNOWN)
    {
        m_data = malloc(m_arrlen);
    }
    else
    {
        m_data = nullptr;
    }

    switch (m_type)
    {
    case INT:
        assgn(long, from.m_data);
        return;
    case FLOAT:
        assgn(double, from.m_data);
        return;
    case STR:
        m_data = new std::string(*(std::string *)from.m_data);
        return;
    case ARR:
        if (m_data != nullptr && from.m_data != nullptr)
            memcpy(m_data, from.m_data, m_arrlen);
    }
}

Mata::Mata(long val)
    : m_type(INT), m_arrlen(SIZE)
{
    m_data = malloc(m_arrlen);
    assgnr(long, val);
}

Mata::Mata(double val)
    : m_type(FLOAT), m_arrlen(SIZE)
{
    m_data = malloc(SIZE);
    assgnr(double, val);
}
Mata::Mata(const std::string &from)
    : m_type(STR), m_arrlen(sizeof(std::string))
{
    m_data = new std::string(from);
}

Mata::Mata(const uint8_t *arr, size_t sz)
    : m_type(ARR), m_arrlen(sz)
{
    m_data = malloc(sz);
    memcpy(m_data, arr, sz);
}

Mata::~Mata()
{
    if (m_data != nullptr && m_arrlen != 0)
    {
        free(m_data);
    }
}