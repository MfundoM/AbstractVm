/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteVM.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:01:36 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:01:38 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTEVM_CLASS_HPP
# define EXECUTEVM_CLASS_HPP

# include "IOperand.hpp"
# include "AbstractFactory.class.hpp"
# include "Exception.class.hpp"
# include "StackVM.class.hpp"
# include "Header.hpp"
# include "Operand.hpp"
#include "Instructions.class.hpp"

class ExecuteVM {
public:
  ExecuteVM(const std::vector<std::string*> &instr);
  ExecuteVM(const ExecuteVM &rhs);
  ~ExecuteVM(void);

  void  executeVm(void);

private:
  const std::vector<std::string*> *_instr;
};

#endif
