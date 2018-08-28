/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:01:55 by mmthethw          #+#    #+#             */
/*   Updated: 2018/08/28 09:42:47 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_CLASS_HPP
# define INSTRUCTIONS_CLASS_HPP

# include "IOperand.hpp"
# include "AbstractFactory.class.hpp"
# include "Exception.class.hpp"
# include "StackVM.class.hpp"
# include "Header.hpp"
# include "Operand.hpp"

class Instructions {
public:
  Instructions(void);
  ~Instructions(void);

  void push(const std::string &opType);
  void pop(void);
  void dump(void);
  void assert(const std::string &opType);
  void add(void);
  void sub(void);
  void mul(void);
  void div(void);
  void mod(void);
  void print(void);
  // void exit(void);

private:
  const AbstractFactory   _create;
  std::vector<const IOperand*>  _stackTable;
};

#endif
