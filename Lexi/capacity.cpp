#include "../Lexi.hpp"


bool Lexi::empty() {
    return m_keys.empty();
}

size_t Lexi::size(){
    return m_keys.size();
}

size_t Lexi::max_size(){
    return m_keys.max_size();
}

void Lexi::reserve(size_t new_cap){
    m_keys.reserve(new_cap);
    m_vals.reserve(new_cap);
}

size_t Lexi::capacity(){
    return m_keys.capacity();
}

void Lexi::shrink_to_fit(){
    m_keys.shrink_to_fit();
    m_vals.shrink_to_fit();
}