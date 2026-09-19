// Developed by Handziur Dmytro on 07.03.2026
#include "UltraFlexString.h"
#include <cassert>
#include <iostream>

#define UFS_DEBUG

UltraFlexString::UltraFlexString() : length_(0), content_(new char[1] {'\0'}) 
{
#ifdef UFS_DEBUG
	std::cout << "\t[CREATION] UltraFlexString: " << *this << '\n';
#endif
}

/* c-style */
UltraFlexString::UltraFlexString(const char* content)
{
	if (content) 
	{
		this->length_ = len(content);
		assert(content[this->length_] == '\0');
		this->content_ = new char[this->length_ + 1];

		for (size_t i = 0; i < this->length_ + 1; i++)
		{
			this->content_[i] = content[i];
		}
	}
	else
	{
		this->content_ = new char[1] {'\0'};
		this->length_ = 0;
	}
#ifdef UFS_DEBUG
	std::cout << "\t[CREATION from C-style] UltraFlexString: " << *this << '\n';
#endif
}

/* STL */
UltraFlexString::UltraFlexString(const std::string& s)
{
	this->length_ = s.length();
	this->content_ = new char[this->length_ + 1];

	for (size_t i = 0; i < this->length_; i++)
	{
		this->content_[i] = s[i];
	}
	this->content_[this->length_] = '\0';
#ifdef UFS_DEBUG
	std::cout << "\t[CREATION from STL] UltraFlexString: " << *this << '\n';
#endif
}

/*Rule of 5*/

/* Destructor */
UltraFlexString::~UltraFlexString() noexcept
{
#ifdef UFS_DEBUG
	std::cout << "\t[DESTRUCTION] UltraFlexString: " << *this << '\n';
#endif
	delete[] this->content_;
}

/* Copy constructor */
UltraFlexString::UltraFlexString(const UltraFlexString& s) : length_(s.length_), content_(new char[s.length_ + 1])
{
	for (size_t i = 0; i < this->length_; i++)
	{
		this->content_[i] = s.content_[i];
	}
	this->content_[this->length_] = '\0';
#ifdef UFS_DEBUG
	std::cout << "\t[COPY C-TOR] UltraFlexString: " << *this << '\n';
#endif
}

/* Copy assignment*/
UltraFlexString& UltraFlexString::operator=(const UltraFlexString& s)
{
	if (this != &s)
	{
		delete[] this->content_;
		
		this->length_ = s.length_;
		this->content_ = new char[length_ + 1];

		for (size_t i = 0; i < this->length_; i++) {
			this->content_[i] = s.content_[i];
		}
		this->content_[this->length_] = '\0';
 	}
#ifdef UFS_DEBUG
	std::cout << "\t[COPY ASSIGN] UltraFlexString: " << *this << '\n';
#endif
	return *this;
}

/* Move constructor */
UltraFlexString::UltraFlexString(UltraFlexString&& s) noexcept: length_(s.length_), content_(s.content_)
{
	s.content_ = nullptr;
	s.length_ = 0;
#ifdef UFS_DEBUG
	std::cout << "\t[MOVE C-TOR] UltraFlexString: " << *this << '\n';
#endif
}

/* Move assignment*/
UltraFlexString& UltraFlexString::operator=(UltraFlexString&& s) noexcept
{
	if (this != &s)
	{
		delete[] this->content_;
		this->length_ = s.length_;
		this->content_ = s.content_;

		s.content_ = nullptr;
		s.length_ = 0;
	}
#ifdef UFS_DEBUG
	std::cout << "\t[MOVE ASSIGN] UltraFlexString: " << *this << '\n';
#endif
	return *this;
}

size_t UltraFlexString::len(const char* string)
{
	size_t len = 0;
	if (string)
	{
		while (string[len++] != '\0');
	}
	return len - 1;
}

std::ostream& operator<<(std::ostream& os, const UltraFlexString& s)
{
	if (s.content_ != nullptr) 
	{
		os << s.content_;
	}
	else 
	{
		os << "NULL";
	}
	return os;
}


UltraFlexString& UltraFlexString::operator+=(const UltraFlexString& s)
{
	size_t length = this->length_ + s.length_;

	char* content = new char[length + 1]();
	size_t ptr = 0;

	for (size_t i = 0; i < this->length_; i++)
	{
		content[ptr++] = this->content_[i];
	}

	for (size_t i = 0; i < s.length_; i++)
	{
		content[ptr++] = s.content_[i];
	}

	assert(ptr == length);
	content[ptr] = '\0';

	delete[] this->content_;
	this->content_ = content;
	this->length_ = length;

	return *this;
}

char& UltraFlexString::operator[](size_t idx)
{
	return this->content_[idx];
}
const char& UltraFlexString::operator[](size_t idx) const
{
	return this->content_[idx];	
}

UltraFlexString operator+(const UltraFlexString& s1, const UltraFlexString& s2)
{
	UltraFlexString temp(s1);
	temp += s2;
	return temp;
}

bool operator==(const UltraFlexString& s1, const UltraFlexString& s2) noexcept
{
	if (s1.length_ != s2.length_) return false;

	for (size_t i = 0; i < s1.length_; i++)
	{
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

bool operator!=(const UltraFlexString& s1, const UltraFlexString& s2) noexcept
{
	return !(s1 == s2);
}