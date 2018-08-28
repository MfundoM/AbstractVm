/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractFactory.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:04:24 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/03 15:02:46 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractFactory.class.hpp"
#include "../includes/Exception.class.hpp"
#include "../includes/Operand.hpp"

AbstractFactory::AbstractFactory(void)
{
  _create.push_back(&AbstractFactory::createInt8);
  _create.push_back(&AbstractFactory::createInt16);
  _create.push_back(&AbstractFactory::createInt32);
  _create.push_back(&AbstractFactory::createFloat);
  _create.push_back(&AbstractFactory::createDouble);

  return ;
}

AbstractFactory::~AbstractFactory(void)
{
  return ;
}

IOperand const * AbstractFactory::createOperand( eOperandType type, std::string const & value ) const
{
  return (this->*(_create[type]))(value);
}

// int8_t (char) 8 bits size
IOperand const * AbstractFactory::createInt8( std::string const & value ) const
{
  int8_t nbr = static_cast<int8_t>(atoi(value.c_str()));

   if (nbr < SCHAR_MIN)
     throw Exception::Underflow();
   if (nbr > SCHAR_MAX)
    throw Exception::Overflow();
  return new Operand<int8_t>(Int8, static_cast<int8_t>(nbr));
}

// int16_t (short) 16 bits size
IOperand const * AbstractFactory::createInt16( std::string const & value ) const
{
  int16_t nbr = static_cast<int16_t>(atoi(value.c_str()));
  if (nbr == -1)
    throw Exception::Overflow();
  if (nbr < SHRT_MIN)
    throw Exception::Underflow();
  // if (nbr > SHRT_MAX || nbr < SHRT_MIN)
  //   throw Exception::Underflow();
  // throw Exception::Overflow();
  return new Operand<int16_t>(Int16, static_cast<int16_t>(nbr));
}

// int32_t (int) 32 bits size
IOperand const * AbstractFactory::createInt32( std::string const & value ) const
{
  int nbr = atoi(value.c_str());

  if (nbr > INT_MAX)
    throw Exception::Overflow();
  if (nbr < INT_MIN)
   throw Exception::Underflow();
  // if (nbr > INT_MAX || nbr < INT_MIN)
  //   throw Exception::Underflow();
  // throw Exception::Overflow();
  return new Operand<int32_t>(Int32, nbr);
}

// float 32 bits size
IOperand const * AbstractFactory::createFloat( std::string const & value ) const
{
  double nbr = static_cast<float>(atof(value.c_str()));

  if (nbr > FLT_MAX)
   throw Exception::Overflow();
  if (nbr < -FLT_MAX)
    throw Exception::Underflow();
  // if (nbr > FLT_MAX || nbr < -FLT_MAX)
  //   throw Exception::Underflow();
  // throw Exception::Overflow();
  return new Operand<float>(Float, static_cast<float>(nbr));
}

// double 64 bits size
IOperand const * AbstractFactory::createDouble( std::string const & value ) const
{
  long double nbr = static_cast<double>(atof(value.c_str()));

  if (nbr > DBL_MAX)
   throw Exception::Overflow();
  if (nbr < -DBL_MAX)
    throw Exception::Underflow();
  // if (nbr > DBL_MAX || nbr < -DBL_MAX)
  //   throw Exception::Underflow();
  // throw Exception::Overflow();
  return new Operand<double>(Double, static_cast<double>(nbr));
}
