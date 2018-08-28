/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:05:10 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:05:12 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Instructions.class.hpp"

Instructions::Instructions(void)
{
  return ;
}

Instructions::~Instructions(void)
{
  return ;
}

void Instructions::push(const std::string &opType)
{
  StackVM get;
  eOperandType  type = get.getOperand(opType);
  std::string   value = get.getValue(opType);

  if (type == ERROR) {
    throw Exception::SyntaxError();
  } else {
    _stackTable.push_back(_create.createOperand(type, value));
  }
  return ;
}

void Instructions::pop(void)
{
  if (_stackTable.empty()) {
    throw Exception::EmptyStack();
  } else {
    _stackTable.pop_back();
  }
  return ;
}

void Instructions::dump(void)
{
  if (_stackTable.empty())
  {
    throw Exception::DumpEmptyStack();
  }

  std::vector<const IOperand*>::const_reverse_iterator top_On_Stack;
  std::vector<const IOperand*>::const_reverse_iterator next_On_Stack;

  top_On_Stack = _stackTable.rbegin();
  next_On_Stack = _stackTable.rend();
  while (top_On_Stack != next_On_Stack) {
    std::cout << (*top_On_Stack)->toString() << std::endl;
    top_On_Stack++;
  }
  return ;
}

void Instructions::assert(const std::string &opType)
{
  if (_stackTable.size() == 0)
  {
     throw Exception::AssertOnEmptyStack();
  }

  StackVM v;
  std::string opValue = v.getValue(opType);
  const IOperand &operand = **(_stackTable.rbegin());

  if (opValue != operand.toString())
  {
    throw Exception::AssertError();
  }
  return ;
}

void Instructions::add(void)
{
  const IOperand *operand1;
  const IOperand *operand2;

  if (_stackTable.size() < 2)
  {
    throw Exception::MissingOperand();
  }
  operand1 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  operand2 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  _stackTable.push_back(*operand1 + *operand2);
  return ;
}

void Instructions::sub(void)
{
  const IOperand *operand1;
  const IOperand *operand2;

  if (_stackTable.size() < 2)
  {
    throw Exception::MissingOperand();
  }
  operand1 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  operand2 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  _stackTable.push_back(*operand1 - *operand2);
  return ;
}

void Instructions::mul(void)
{
  const IOperand *operand1;
  const IOperand *operand2;

  if (_stackTable.size() < 2)
  {
    throw Exception::MissingOperand();
  }
  operand1 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  operand2 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  _stackTable.push_back(*operand1 * (*operand2));
  return ;
}

void Instructions::div(void)
{
  const IOperand *operand1;
  const IOperand *operand2;

  if (_stackTable.size() < 2)
  {
    throw Exception::MissingOperand();
  }
  operand1 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  operand2 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  _stackTable.push_back(*operand1 / *operand2);
  return ;
}

void Instructions::mod(void)
{
  const IOperand *operand1;
  const IOperand *operand2;

  if (_stackTable.size() < 2)
  {
    throw Exception::MissingOperand();
  }
  operand1 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  operand2 = *(_stackTable.rbegin());
  _stackTable.pop_back();
  _stackTable.push_back(*operand1 % *operand2);
  return ;
}

void Instructions::print(void)
{
  if (_stackTable.size() == 0)
  {
     throw Exception::PrintOnEmptyStack();
  }

  const IOperand *operand1;
  const Operand<char> *operand2;

  operand1 =*(_stackTable.rbegin());
  if (operand1->getType() != Int8)
  {
    throw Exception::IsNotAscii();
  }
  operand2 = static_cast<const Operand<char>*>(operand1);
  std::cout << operand2->getValue() << std::endl;
  return ;
}
