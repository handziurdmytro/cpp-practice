// Developed by Handziur Dmytro on 16.04.2026
#pragma once
#include <string>
#include <ostream>

/* Task 7: economical word class with static buffer */
template <size_t N = 16>
class Word 
{
private:
    char _contents[N];

public:
    /* empty c-tor */
    Word() 
    {
        _contents[0] = '\0';
    }

    /* c-style str c-tor */
    Word(const char* str) 
    {
        size_t i = 0;
        while (str[i] != '\0' && i < N - 1) 
        {
            _contents[i] = str[i];
            ++i;
        }
        _contents[i] = '\0';
    }

    /* stl str c-tor */
    Word(const std::string& str) 
    {
        size_t i = 0;
        while (i < str.length() && i < N - 1) 
        {
            _contents[i] = str[i];
            ++i;
        }
        _contents[i] = '\0';
    }

    /*Task #1.2: op< for ordering */
    bool operator<(const Word& that) const 
    {
        size_t i = 0;
        while (_contents[i] != '\0' && _contents[i] == that._contents[i]) 
        {
            ++i;
        }   
        return static_cast<unsigned char>(_contents[i]) < static_cast<unsigned char>(that._contents[i]);
    }

    /*Task #1.2: op== */
    bool operator==(const Word& that) const
    {
        size_t i = 0;
        while (_contents[i] != '\0' && that._contents[i] != '\0') 
        {
            if (_contents[i] != that._contents[i]) 
            {
                return false;
            }
            ++i;
        }
        return _contents[i] == that._contents[i];
    }

    const char* c_style_string() const 
    {
        return _contents;
    }
};

template <size_t N>
std::ostream& operator<<(std::ostream& os, const Word<N>& word) 
{
    return os << word.c_style_string();
}
