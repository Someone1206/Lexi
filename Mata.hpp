#pragma once
#include <string>

class Mata
{
private:
    void *m_data;
    char m_type;
    size_t m_arrlen;

    friend class Lexi; // eeh... will add letaa...

public:
    enum MType
    {
        UNKNOWN,
        INT,
        FLOAT,
        STR,
        ARR
    };

    Mata();
    Mata(const Mata &from);
    Mata(long val);
    Mata(double val);
    Mata(const std::string &from);
    Mata(const uint8_t *arr, size_t sz);

    void assignInt(long val);
    void assignFloat(double val);
    void assignStr(const std::string &from);
    void assignArr(const uint8_t *arr, size_t sz);

    void *getValue();
    MType getType();
    size_t getAllocSize();

    int cmpVal(const Mata &to);
    bool cmpInt(long to);
    bool cmpFloat(double to);
    bool cmpStr(const std::string &to);

    ~Mata();
};