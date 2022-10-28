#pragma once
#include "Mata.hpp"
#include <vector>
#include <utility>


// Lexi - Lexicon
class Lexi
{
private:
    std::vector<Mata> m_keys;
    std::vector<Mata> m_vals;
    // idk wut i'm doin...

    void key_check(const Mata &key);
    // idk if I need it...

public:
    static const size_t npos = std::string::npos;

    Lexi();

    size_t index_of(long key);
    size_t index_of(const std::string &key);

    const Mata *at(long key);
    const Mata *at(const std::string &key);

    Mata *operator[](long key);
    Mata *operator[](const std::string &key);

    std::pair<Mata, Mata> at_index(size_t index);

    bool empty();
    size_t size();
    size_t max_size();
    void reserve(size_t new_cap);
    size_t capacity();
    void shrink_to_fit();

    void clear();
    bool push(long key, const Mata &val);
    bool push(const std::string &key, const Mata &val);
    void update(long key, const Mata &val);
    void update(const std::string &key, const Mata &val);
    bool erase(long key);
    bool erase(const std::string &key);
    bool erase(size_t from, size_t to);
    void pop();

    ~Lexi();
};
