#include "../Mata.hpp"

void *Mata::getValue() const
{
    return m_data;
}

Mata::MType Mata::getType()
{
    return (MType)m_type;
}

size_t Mata::getAllocSize()
{
    return m_arrlen;
}