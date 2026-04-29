// Developed by Handziur Dmytro on 07.03.2026
#include <iostream>
#include <string>
#include <utility>
#include <cassert>
#include "UltraFlexString.h"

using std::cout;

int main()
{
    const std::string SEPARATOR = "------------------\n";
    UltraFlexString s1("Dmytro ");
    std::string s2 = "Handziur ";
    char* p = new char[] {'V', 'a', 's', 'y', 'l', 'i', 'o', 'v', 'y', 'c', 'h', ' ', '\0'};

    cout << SEPARATOR << "** Strings tests **\n";

    cout << "custom: >" << s1 << "<\n";
    cout << "stl: >" << s2 << "<\n";
    cout << "c-ctyle: >" << p << "<\n\n";

    UltraFlexString str1 = s1 + s2;
    assert(str1 == "Dmytro Handziur ");
    assert(str1 != "");
    cout << SEPARATOR << "string no.1(custom + stl): >" << str1 << "<\n" << SEPARATOR;
    
    UltraFlexString str2 = s2 + s1;
    assert(str2 == "Handziur Dmytro ");
    assert(str2 != ""); 
    cout << SEPARATOR << "string no.2(stl + custom): >" << str2 << "<\n" << SEPARATOR;
    
    UltraFlexString str3 = p + s1;
    assert(str3 == "Vasyliovych Dmytro ");
    assert(str3 != "");
    cout << SEPARATOR << "string no.3(c-style + custom): >" << str3 << "<\n" << SEPARATOR;
    
    UltraFlexString str4 = s1 + p;
    assert(str4 == "Dmytro Vasyliovych ");
    assert(str4 != "");
    cout << SEPARATOR << "string no.4(custom + c-style): >" << str4 << "<\n" << SEPARATOR;

    /* Explicit convertion to C-style */
    UltraFlexString converted = s1.stl_to_c();
    cout << SEPARATOR << "Explicit convertion to C-style: " << converted << '\n' << SEPARATOR;

    /* Another explicit convertion to C-style */
    UltraFlexString converted2 = static_cast<const char*>(s1);
    cout << SEPARATOR << "Another explicit convertion to C-style: " << converted2 << '\n' << SEPARATOR;

    /*Rule of 5 tests*/
    cout << SEPARATOR << "** Rule of 5 tests **\n";

    /* define UFS_DEBUG in UltraFlexString.cpp to see the execution of special methods */

    /*#1 Destructor*/
    cout << "( 1 )" << SEPARATOR;

    {
        UltraFlexString born_to_die("destruction");
    }/* Destructor will work here */


    /*#2 Copy Ctor*/
    cout << "( 2 )" << SEPARATOR;

    UltraFlexString original("original");
    UltraFlexString copy1(original);/*copy ctor will work here*/
    UltraFlexString copy2 = original;/*copy ctor will work here*/

    /*#3 Copy Assign*/
    cout << "( 3 )" << SEPARATOR;
    
    UltraFlexString container("container");
    UltraFlexString content("content");
    container = content;/*copy assign will work here*/

    /*#4 Move Ctor*/
    cout << "( 4 )" << SEPARATOR;

    UltraFlexString move_val("move me");
    UltraFlexString move_container(std::move(move_val));

    /*#5 Move Assign*/
    cout << "( 5 )" << SEPARATOR;

    UltraFlexString move_val_2("move me");
    UltraFlexString move_container_2("move into me");

    move_container_2 = std::move(move_val_2);

    cout << SEPARATOR;
    return 0;
}
