// Developed by Handziur Dmytro on 16.04.2026
#include <iostream>
#include <string>
#include <utility>
#include <cassert>
#include <cctype>
#include "Array.h"
#include "Dictionary.h"
#include "Word.h"

using std::cout;

void fill_dict_with_str(const std::string&, Dictionary<std::string>&);

template <typename T>
bool is_sorted(const Dictionary<T>& dict);

int main()
{
    bool test_array_class = true;
    bool test_dictionary_class = true;
    bool test_word_class = true;
    std::string sep = "\n-----------------------------------\n";

    /* TASK #5 */
    cout << sep << "\t** Task #5 **" << sep;
    Dictionary<std::string> dict;
    cout << "Created dict: " << dict << '\n';
    
    std::string lorem = /* 138 words */
        "lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor "
        "incididunt ut labore et dolore magna aliqua ut enim ad minim veniam quis nostrud "
        "exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat duis aute irure "
        "dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur "
        "excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit "
        "anim id est laborum lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod "
        "tempor incididunt ut labore et dolore magna aliqua ut enim ad minim veniam quis nostrud "
        "exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat duis aute irure dolor "
        "in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur excepteur "
        "sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum";
    fill_dict_with_str(lorem, dict);
    assert(is_sorted(dict));

    cout << "[INFO] filled dict: " << dict << '\n';
    cout << "[INFO] size: " << dict.size() << '\n';


    /* TASK #6 */
    cout << sep << "\t** Task #6 **" << sep;

    Dictionary<std::string> dict_copy;
    copy(dict_copy, dict);
    assert(dict_copy == dict);
    cout << "[INFO] dicts are equal; successfull copy\n";

    Dictionary<std::string> dict_moved;
    merge_into(dict_moved, std::move(dict_copy));
    assert(dict_copy.size() == 0);
    assert(dict_moved == dict);
    assert(is_sorted(dict_moved));
    cout << "[INFO] successfull move; source is empty, order is saved" << sep;

    /* TASK #8 */
    cout << sep << "\t** Task #8 **" << sep;

    Dictionary<Word<16>> edict;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        edict.insert(Word<16>(*it));
    }
    cout << "[INFO] edict created: " << edict << '\n';
    cout << "[INFO] size: " << edict.size() << sep;

    /* TASK #9 */
    cout << sep << "\t** Task #9 **" << sep;

    Dictionary<Word<16>> edict_odd;
    Dictionary<Word<16>> edict_even;

    size_t position = 1; /*0, 2, 4 - odd positions; 1, 3, 5 - even*/
    for (auto it = edict.begin(); it != edict.end(); ++it, ++position) 
    {
        if (position % 2 == 0) 
        {
            edict_even.insert(*it);
        }
        else 
        {
            edict_odd.insert(*it);
        }
    }
    cout << "[INFO] even edict: " << edict_even << '\n';
    assert(is_sorted(edict_even));
    cout << "[INFO] odd edict: " << edict_odd << '\n';
    assert(is_sorted(edict_odd));

    assert((edict_odd + edict_even) == edict);
    cout << "[INFO] successfull union: edict_odd + edict_even == edict" << sep;

    /* TASK #10 */
    cout << sep << "\t** Task #10 **" << sep;

    Dictionary<Word<16>> edict_div3;
    Dictionary<Word<16>> edict_div6;

    position = 1;
    for (auto it = edict.begin(); it != edict.end(); ++it, ++position) 
    {
        if (position % 3 == 0) edict_div3.insert(*it);
        if (position % 6 == 0) edict_div6.insert(*it);
    }

    cout << "[INFO] div3 edict: " << edict_div3 << '\n';
    assert(is_sorted(edict_div3));
    cout << "[INFO] div6 edict: " << edict_div6 << '\n';
    assert(is_sorted(edict_div6));

    assert((edict_even/*_div2*/ * edict_div3) == edict_div6);
    cout << "[INFO] successfull intersection: edict_even(_div2) * edict_div3 == edict_div6" << sep;


    /* CUSTOM DS TESTING */
    if (test_array_class) {
        cout << sep << "\t** ARRAY TESTING **" << sep;
        Array<int> a1;
        cout << a1 << '\n';
        a1.insert(0, 23);
        cout << a1 << '\n';
        a1.insert(1, 47);
        cout << a1 << '\n';
        a1.insert(2, 11);
        cout << a1 << '\n';

        assert(a1.contain(23));
        assert(a1.contain(47));
        assert(a1.contain(11));
        assert(a1.size() == 3);
        assert(a1.capacity() == 4);

        a1.remove(0);
        cout << a1 << '\n';
        assert(!a1.contain(23));
        assert(a1.contain(47));
        assert(a1.contain(11));
        assert(a1.size() == 2);
        assert(a1.capacity() == 4);

        a1.clear();
        assert(!a1.contain(23));
        assert(!a1.contain(47));
        assert(!a1.contain(11));
        assert(a1.size() == 0);
        assert(a1.capacity() == 4);
        cout << sep;
    }

    if (test_word_class) {
        cout << sep << "\t** WORD TESTING **" << sep;
        Word<16> w1;
        Word<16> w2("rust");
        Word<16> w3(std::string("zig"));
        Word<16> w4("rust");
        Word<16> w5("golanggolanggolanggolanggolanggolang");

        assert(w1 < w2);
        assert(w2 < w3);
        assert(w2 == w4);
        assert(!(w3 < w2));

        cout << "Word 2: " << w2 << '\n';
        cout << "Word 3: " << w3 << '\n';
        cout << "Word 5 (truncated): " << w5 << '\n';
    }

    if (test_dictionary_class) {
        cout << sep << "\t** DICTIONARY TESTING **" << sep;
        Dictionary<int> d;

        d.insert(50);
        d.insert(10);
        d.insert(30);
        d.insert(30);

        cout << "Dict: " << d << '\n';
        assert(d.size() == 3);
        assert(is_sorted(d));

        assert(d.contain(10));
        assert(!d.contain(99));

        d.remove(30);
        d.remove(100);
        cout << "Dict: " << d << '\n';

        assert(d.size() == 2);
        assert(!d.contain(30));

        d.clear();
        assert(d.size() == 0);
        cout << sep;
    }

    return 0;
}

void fill_dict_with_str(const std::string& str, Dictionary<std::string>& dict)
{
    std::string buffer;

    for (char c : str) 
    {
        if (std::ispunct(static_cast<unsigned char>(c))) continue;

        if (std::isspace(static_cast<unsigned char>(c))) 
        {
            if (!buffer.empty()) 
            {
                dict.insert(buffer);
                buffer.clear();
            }
        }
        else 
        {
            buffer += c;
        }
    }

    if (!buffer.empty()) 
    {
        dict.insert(buffer);
    }
}

template <typename T>
bool is_sorted(const Dictionary<T>& dict)
{
    if (dict.size() <= 1) return true;

    auto it = dict.begin();
    T prev = *it;
    ++it;

    while (it != dict.end()) {
        if (*it < prev || *it == prev) return false;
        prev = *it;
        ++it;
    }
    return true;
}
