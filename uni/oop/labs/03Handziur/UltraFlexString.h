// Developed by Handziur Dmytro on 07.03.2026
#pragma once
#include <string>

class UltraFlexString
{
private:
	size_t length_;
	char* content_;

	static size_t len(const char*);

public:
	/* Default constructor*/
	UltraFlexString();
	/* STL */
	UltraFlexString(const std::string&);
	/* C-style */
	UltraFlexString(const char*);

	/*Ro5*/
	~UltraFlexString() noexcept;
	UltraFlexString(const UltraFlexString&);
	UltraFlexString& operator=(const UltraFlexString&);
	UltraFlexString(UltraFlexString&&) noexcept;
	UltraFlexString& operator=(UltraFlexString&&) noexcept;

	const size_t length() const noexcept { return this->length_; }

	/* explicit convertion into c-style*/
	const char* stl_to_c() const noexcept { return this->content_; }

	/* another explicit convertion into c-style*/
	explicit operator const char* () const noexcept { return this->content_; }

	UltraFlexString& operator+=(const UltraFlexString&);

	char& operator[](size_t); /* modifier */
	const char& operator[](size_t) const; /* selector */

	friend UltraFlexString operator+(const UltraFlexString&, const UltraFlexString&);
	friend bool operator==(const UltraFlexString&, const UltraFlexString&) noexcept;
	friend bool operator!=(const UltraFlexString&, const UltraFlexString&) noexcept;
	
	friend std::ostream& operator<<(std::ostream&, const UltraFlexString&);
};