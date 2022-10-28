#include "../Lexi.hpp"
#include <stdexcept>

size_t Lexi::index_of(long key)
{
    for (size_t i = 0; i < m_keys.size(); i++)
    {
        if (m_keys[i].cmpInt(key))
            return i;
    }
    return npos;
}

size_t Lexi::index_of(const std::string &key)
{
    for (size_t i = 0; i < m_keys.size(); i++)
    {
        if (m_keys[i].cmpStr(key))
            return i;
    }
    return npos;
}

const Mata *Lexi::at(long key)
{
    size_t pos = index_of(key);
    if (pos != npos)
        return &m_vals[pos];
    return nullptr;
}

const Mata *Lexi::at(const std::string &key)
{
    size_t pos = index_of(key);
    if (pos != npos)
        return &m_vals[pos];
    return nullptr;
}

Mata *Lexi::operator[](long key)
{
    return (Mata *)at(key);
}

Mata *Lexi::operator[](const std::string &key)
{
    return (Mata *)at(key);
}

std::pair<Mata, Mata> Lexi::at_index(size_t index)
{
    if (index <= m_keys.size())
    {
        return std::pair<Mata, Mata>(m_keys[index], m_vals[index]);
    }
    throw std::invalid_argument("Lexi index out of bounds");
}