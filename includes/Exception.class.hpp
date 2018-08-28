/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:01:05 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:01:07 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_CLASS_HPP
# define EXCEPTION_CLASS_HPP

# include "Header.hpp"

class Exception {
public:
	class SyntaxError : public std::exception {
	public:
		const char *what() const throw();
	};

	class Overflow : public std::exception {
	public:
		const char *what() const throw();
	};

	class Underflow : public std::exception {
	public:
		const char *what() const throw();
	};

	class EmptyStack : public std::exception {
	public:
		const char *what() const throw();
	};

	class DumpEmptyStack : public std::exception {
	public:
		const char *what() const throw();
	};

	class UnknownInstruction : public std::exception {
	public:
		const char *what() const throw();
	};

	class InvalidFile : public std::exception {
	public:
		const char *what() const throw();
	};

	class AssertError : public std::exception {
	public:
		const char *what() const throw();
	};

	class AssertOnEmptyStack : public std::exception {
	public:
		const char *what() const throw();
	};

	class PrintOnEmptyStack : public std::exception {
	public:
		const char *what() const throw();
	};

	class MissingExitInstruction : public std::exception {
	public:
		const char *what() const throw();
	};

	class MissingOperand : public std::exception {
	public:
		const char *what() const throw();
	};

	class FloatingPointError : public std::exception {
	public:
		const char *what() const throw();
	};

	class IsNotAscii : public std::exception {
	public:
		const char *what() const throw();
	};

	class ModFloatingPoint : public std::exception {
	public:
		const char *what() const throw();
	};

	class InvalidValue : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif
