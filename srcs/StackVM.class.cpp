/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackVM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:04:49 by mmthethw          #+#    #+#             */
/*   Updated: 2018/08/28 09:44:42 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StackVM.class.hpp"
#include  "../includes/Exception.class.hpp"
#include "../includes/IOperand.hpp"

StackVM::StackVM(void)
{
  //std::vector<std::string*> v(fread("text.avm"));
  //std::cout << getValue("push int8(;32)") << std::endl;
  //ft_cin();
  return;
}

StackVM::~StackVM(void) { return; }

eOperandType StackVM::getOperand(const std::string &Operand)
{
  std::string op_type = Operand.substr(Operand.find(' ') + 1, Operand.size());

  if (op_type.substr(0, 4) == "int8")   { return (Int8); }
  if (op_type.substr(0, 5) == "int16")  { return (Int16); }
  if (op_type.substr(0, 5) == "int32")  { return (Int32); }
  if (op_type.substr(0, 5) == "float")  { return (Float); }
  if (op_type.substr(0, 6) == "double") { return (Double); }

  return (ERROR);
}

Instr StackVM::getInstruction(const std::string &instruct)
{
  if (instruct.substr(0, 5) == "push ")   { return (Push); }
  if (instruct.substr(0, 3) == "pop")     { return (Pop); }
  if (instruct.substr(0, 4) == "dump")    { return (Dump); }
  if (instruct.substr(0, 7) == "assert ") { return (Assert); }
  if (instruct.substr(0, 3) == "add")     { return (Add); }
  if (instruct.substr(0, 3) == "sub")     { return (Sub); }
  if (instruct.substr(0, 3) == "mul")     { return (Mul); }
  if (instruct.substr(0, 3) == "div")     { return (Div); }
  if (instruct.substr(0, 3) == "mod")     { return (Mod); }
  if (instruct.substr(0, 5) == "print")   { return (Print); }
  if (instruct.substr(0, 1) == ";") { return (Comment); }
  if (instruct.substr(0, 4) == "exit")    { return (Exit); }

  return (Error);
}

std::string StackVM::getValue(const std::string &value)
{
  std::string op_val = value.substr(value.find('(') + 1, value.size());
  std::regex  myRegex("^[0-9.-]*$");

  op_val = op_val.substr(0, op_val.find(')'));
  if (!std::regex_match(op_val, myRegex))
    throw Exception::InvalidValue();
  //std::cout << op_val << std::endl;
  return (op_val);
}

bool  StackVM::checkFileExists(const std::string &file_path)
{
  if (FILE *file = fopen(file_path.c_str(), "r"))
  {
    fclose(file);
    return (true);
  } else {
    return (false);
  }
}

const std::vector<std::string*> &StackVM::fread(const char *fname)
{
  std::vector<std::string*> *instructions = new std::vector<std::string*>;
  char          *buff = new char [BUFF_SIZE];

  if (checkFileExists(fname) == false)
  {
    throw Exception::InvalidFile();
  }
  std::ifstream file(fname);
  if (file.is_open())
  {
    while (!file.eof())
    {
      file.getline(buff, BUFF_SIZE);
      if (strlen(buff) > 0)
        instructions->push_back(new std::string(buff));
      if (!strncmp(buff, "exit", 4))
        break ;
    }
    file.close();
    delete [] (buff);
  }
  //if (instructions->size() && **(instructions->rbegin()) != "exit")
    //throw Exception::MissingExitInstruction();
  return (*instructions);
}

const std::vector<std::string*> &StackVM::ft_cin(void)
{
  std::vector<std::string*> *instructions = new std::vector<std::string*>;
  char          *buff = new char [BUFF_SIZE];

  while (strncmp(buff, ";;", 2))
  {
    std::cin.getline(buff, BUFF_SIZE);
    if (strlen(buff) > 0 && strncmp(buff, ";;", 2))
      instructions->push_back(new std::string(buff));
  }
  delete [] (buff);
  if (instructions->size() && **(instructions->rbegin()) != "exit")
    throw Exception::MissingExitInstruction();
  return (*instructions);
}
