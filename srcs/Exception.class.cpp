/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:04:58 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:05:00 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Header.hpp"
#include "../includes/Exception.class.hpp"

const char *Exception::SyntaxError::what() const throw()
{
	return ("Syntax error!");
}

const char *Exception::Overflow::what() const throw()
{
	return ("Overflow on a value!");
}

const char *Exception::Underflow::what() const throw()
{
	return ("Underflow on a value!");
}

const char *Exception::EmptyStack::what() const throw()
{
	return ("Instruction pop on empty stack!");
}

const char *Exception::DumpEmptyStack::what() const throw()
{
	return ("Instruction dump on empty stack!");
}

const char *Exception::UnknownInstruction::what() const throw()
{
	return ("Instruction is unknown!");
}

const char *Exception::InvalidFile::what() const throw()
{
	return ("File does not exist!");
}

const char *Exception::AssertError::what() const throw()
{
	return ("Assert instruction is not true!");
}

const char *Exception::AssertOnEmptyStack::what() const throw()
{
	return ("Instruction assert on empty stack!");
}

const char *Exception::PrintOnEmptyStack::what() const throw()
{
	return ("Instruction print on empty stack!");
}

const char *Exception::MissingExitInstruction::what() const throw()
{
	return ("Exit instruction is missing!");
}

const char *Exception::MissingOperand::what() const throw()
{
	return ("Not enough values on the stack to execute arithmetic operation!");
}

const char *Exception::FloatingPointError::what() const throw()
{
	return ("Division/Modulo by 0!");
}

const char *Exception::IsNotAscii::what() const throw()
{
	return ("Cannot print a non-ascii character!");
}

const char *Exception::ModFloatingPoint::what() const throw()
{
	return ("Cannot mod floating point values!");
}

const char *Exception::InvalidValue::what() const throw()
{
	return ("The value entered is invalid!");
}
