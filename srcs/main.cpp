/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:05:19 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:05:21 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Header.hpp"
#include "../includes/IOperand.hpp"
#include "../includes/StackVM.class.hpp"
#include "../includes/ExecuteVM.class.hpp"

int main(int argc, char *argv[])
{
	StackVM op;

	//std::cout << op.getOperand("push int8") << std::endl;
	//std::cout << in.getInstruction("") << std::endl;
	try {
		if (argc == 1) {
			ExecuteVM execute(op.ft_cin());
			execute.executeVm();
		} else if (argc == 2) {
			ExecuteVM execute(op.fread(argv[1]));
			execute.executeVm();
		}
		//StackVM op;
		//op.ft_cin();
		//std::cout << op.getValue("push int8(.32)") << std::endl;
		//std::vector<std::string*> v = val.fread(argv[1]);
		//std::cout << v << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
