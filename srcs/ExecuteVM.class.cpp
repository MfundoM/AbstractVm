/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteVM.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:04:36 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:04:42 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ExecuteVM.class.hpp"

ExecuteVM::ExecuteVM(const ExecuteVM &rhs) : _instr(NULL)
{
  static_cast<void>(rhs);
  return ;
}

ExecuteVM::ExecuteVM(const std::vector<std::string*> &instr) : _instr(&instr)
{
  return ;
}

ExecuteVM::~ExecuteVM(void)
{
  return ;
}

void  ExecuteVM::executeVm(void)
{
  std::vector<std::string*>::const_iterator	top_On_Stack;
	std::vector<std::string*>::const_iterator	next_On_Stack;

	top_On_Stack = _instr->begin();
	next_On_Stack = _instr->end();

  StackVM get;
  Instructions do_something;

  while (top_On_Stack != next_On_Stack) {
    Instr command = get.getInstruction(**top_On_Stack);

    if (command == Error) {
      throw Exception::UnknownInstruction();
    }
    if (command == Push) {
      //std::cout << "fuck push" << std::endl;
      do_something.push(**top_On_Stack);
      //break;
    }
    if (command == Dump) {
      //std::cout << "fuck dump" << std::endl;
      do_something.dump();
      //break;
    }
    if (command == Pop) {
      //std::cout << "fuck pop" << std::endl;
      do_something.pop();
      //break;
    }
    if (command == Assert) {
      //std::cout << "fuck assert" << std::endl;
      do_something.assert(**top_On_Stack);
      //break;
    }
    if (command == Add) {
      //std::cout << "fuck add" << std::endl;
      do_something.add();
      //break;
    }
    if (command == Sub) {
      //std::cout << "fuck sub" << std::endl;
      do_something.sub();
      //break;
    }
    if (command == Mul) {
      //std::cout << "fuck mul" << std::endl;
      do_something.mul();
      //break;
    }
    if (command == Div) {
      //std::cout << "fuck div" << std::endl;
      do_something.div();
      //break;
    }
    if (command == Mod) {
      //std::cout << "fuck mod" << std::endl;
      do_something.mod();
      //break;
    }
    if (command == Print) {
      //std::cout << "fuck print" << std::endl;
      do_something.print();
      //break;
    }
    top_On_Stack++;
  }
}
