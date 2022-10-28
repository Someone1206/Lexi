#include "../Lexi.hpp"

void Lexi::clear()
{
    m_keys.clear();
    m_vals.clear();
}

bool Lexi::push(long key, const Mata &val)
{
    if (index_of(key) != npos)
        return false;
    m_keys.push_back(Mata((long)key));
    m_vals.push_back(val);
    return true;
}

bool Lexi::push(const std::string &key, const Mata &val)
{
    if (index_of(key) != npos)
        return false;
    m_keys.push_back(Mata(key));
    m_vals.push_back(val);
    return true;
}

void Lexi::update(long key, const Mata &val)
{
    size_t pos = index_of(key);

    if (pos != npos)
    {
        m_vals[pos] = val;
    }
    else
    {
        m_keys.push_back(Mata(key));
        m_vals.push_back(val);
    }
}

void Lexi::update(const std::string &key, const Mata &val)
{
    size_t pos = index_of(key);

    if (pos != npos)
    {
        m_vals[pos] = val;
    }
    else
    {
        m_keys.push_back(Mata(key));
        m_vals.push_back(val);
    }
}

bool Lexi::erase(long key)
{
    size_t pos = index_of(key);
    if (pos != npos)
    {
        m_keys.erase(m_keys.begin() + pos);
        m_vals.erase(m_vals.begin() + pos);
        return true;
    }
    return false;
}

bool Lexi::erase(const std::string &key)
{
    size_t pos = index_of(key);
    if (pos != npos)
    {
        m_keys.erase(m_keys.begin() + pos);
        m_vals.erase(m_vals.begin() + pos);
        return true;
    }
    return false;
}

bool Lexi::erase(size_t from, size_t to)
{
    if (!(from <= to && to <= size()))
    {
        return false;
    }

    m_keys.erase(m_keys.begin() + from, m_keys.begin() + to);
    m_vals.erase(m_keys.begin() + from, m_keys.begin() + to);

    return true;
}

void Lexi::pop()
{
    m_keys.pop_back();
    m_vals.pop_back();
}