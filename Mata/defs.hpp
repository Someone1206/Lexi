#pragma once
// just some useless macros
#define SIZE 8

// assign with modifiable rvalues
#define assgn(dt, frm) \
    *(dt *)m_data = *(dt *)frm;

// assign with read only rvalues
#define assgnr(dt, frm) \
    *(dt *)m_data = frm;

// create assignment
#define crasg(sz)                       \
    if (m_type == STR || m_type == ARR) \
    {                                   \
        if (m_data != nullptr)          \
        {                               \
            free(m_data);               \
        }                               \
        m_data = malloc(sz);            \
        m_arrlen = sz;                  \
    }                                   \
    else if (m_data == nullptr)         \
    {                                   \
        m_data = malloc(sz);            \
    }

#define cmp(dt, frm) \
    (*(dt *)m_data == *(dt *)frm)

#define cmpr(dt, frm) \
    ((*(dt *)m_data) == frm)