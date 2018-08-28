/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractFactory.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:00:55 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/02 11:00:58 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTFACTORY_CLASS_HPP
# define ABSTRACTFACTORY_CLASS_HPP

# include "IOperand.hpp"
# include "Header.hpp"

class AbstractFactory {
public:
  AbstractFactory(void);
  ~AbstractFactory(void);

  typedef  const IOperand * (AbstractFactory::*OpFunction)(const std::string &) const;

  IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
  IOperand const * createInt8( std::string const & value ) const;
  IOperand const * createInt16( std::string const & value ) const;
  IOperand const * createInt32( std::string const & value ) const;
  IOperand const * createFloat( std::string const & value ) const;
  IOperand const * createDouble( std::string const & value ) const;

  std::vector<OpFunction>   _create;
};

#endif
