/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:01:14 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:01:15 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include "Header.hpp"

enum eOperandType {
	Int8 = 0,
	Int16,
	Int32,
	Float,
	Double,
	ERROR
};

class IOperand {
public:
	virtual int						getPrecision(void) const = 0;	// Precision of the type of the instance
	virtual eOperandType	getType(void) const = 0;	// Type of the instance

	virtual IOperand const	* operator+(IOperand const &rhs) const = 0; // Sum
	virtual IOperand const	* operator-(IOperand const &rhs) const = 0; // Difference
	virtual IOperand const	* operator*(IOperand const &rhs) const = 0; // Product
	virtual IOperand const	* operator/(IOperand const &rhs) const = 0; // Quotient
	virtual IOperand const	* operator%(IOperand const &rhs) const = 0; // Modulo

	virtual std::string const & toString(void) const = 0; // String representation of the instance
	virtual ~IOperand(void) {}
};

#endif