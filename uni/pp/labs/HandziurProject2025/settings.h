/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cassert>

/* TASK #1 */
struct Settings
{
	/*each field is a 2bit part of 8bit(1byte) unsigned char*/
	unsigned char _volume : 2;
	unsigned char _color : 2;
	unsigned char _theme : 2;
	unsigned char _language : 2;
};

void invert_second_field(Settings& s)
{
	/*mask 00001100 - we are interested only in second field 
	(bits 2 and 3 in reversed indexation (7 6 5 4 (3 2) 1 0))*/
	unsigned char mask = 0x0C;

	/* get byte ptr to access the s*/
	unsigned char* ptr = (unsigned char*)&s;
	assert(ptr != nullptr);

	/* 1 ^ 1 = 0; 0 ^ 1 = 1 <- we use XOR + mask to invert*/
	*ptr ^= mask;
}