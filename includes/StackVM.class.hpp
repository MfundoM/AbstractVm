/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackVM.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:02:04 by mmthethw          #+#    #+#             */
/*   Updated: 2018/08/28 09:43:25 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKVM_CLASS_HPP
# define STACKVM_CLASS_HPP

# include "Header.hpp"
# include "IOperand.hpp"

enum Instr {
	Push = 0,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit,
	Comment,
	Error
};

class StackVM {
public:
  StackVM(void);
  ~StackVM(void);

  eOperandType  getOperand(const std::string &Operand);
  Instr  getInstruction(const std::string &instruct);
  std::string   getValue(const std::string &value);

  bool  checkFileExists(const std::string &file_path);
  const std::vector<std::string*> &fread(const char *fname);
  const std::vector<std::string*> &ft_cin(void);
};

#endif
