// Copyright (c) SmartPolarBear 2022.
//
// Copyright (c) 2021 SmartPolarBear
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//

//
// Created by cleve on 2/24/2022.
//

#include "base/exceptions.h"
#include "scanner/scanner.h"

#include <cctype>
#include <sstream>

using namespace std;
using namespace chclang::exceptions;

bool chclang::scanning::scanner::is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool chclang::scanning::scanner::is_letter(char c)
{
	return (c >= 'a' && c <= 'z') ||
		   (c >= 'A' && c <= 'Z') ||
		   c == '_';
}

chclang::scanning::scanner::scanner(std::string source)
		: src_path_(std::move(source))
{
	std::ifstream input{ src_path_, std::ios::in };

	if (!input.is_open())
	{
		throw file_operation_error{ src_path_ };
	}

	stringstream ss{};
	ss << input.rdbuf();

	src_ = ss.str();
}