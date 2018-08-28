/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:01:21 by mmthethw          #+#    #+#             */
/*   Updated: 2018/07/03 15:07:12 by mmthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_CLASS_TPP
# define OPERAND_CLASS_TPP

# include "AbstractFactory.class.hpp"
# include "IOperand.hpp"
# include "Exception.class.hpp"

template <typename T>
class Operand : public IOperand {
public:
  Operand(void) : _type(Int8), _value(0)
  {
    return ;
  }

  Operand(const eOperandType type, const T value) : _value(value), _type(type)
  {
    //_type = type;
    //_value = value;

    return ;
  }

  ~Operand(void)
  {
    return ;
  }

  Operand &operator=(const Operand &rhs)
  {
    return (*new Operand(rhs));
  }

  int getPrecision(void) const
  {
    return (_type);
  }

  eOperandType getType(void) const
  {
    return (this->_type);
  }

  std::string const & toString(void) const
  {
    std::stringstream ss;
	  if (this->_type == Int8)
		   ss << static_cast<int32_t>(this->_value);
	  else
    	 ss << this->_value;
    return (*new std::string(ss.str()));
  }

  T getValue(void) const
  {
    return (this->_value);
  }

  IOperand const	* operator+(IOperand const &rhs) const
  {
    eOperandType  type;
    int           interger = 0;
    double        real_nbr = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() + _value));
    } else {
      type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        interger = std::stoi(rhs.toString()) + _value;
        return (_create.createOperand(type, std::to_string(interger)));
      }
      if (type == Float || type == Double) {
        real_nbr = std::stod(rhs.toString()) + _value;
        return (_create.createOperand(type, std::to_string(real_nbr)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator-(IOperand const &rhs) const
  {
    eOperandType  type;
    int           interger = 0;
    double        real_nbr = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() - _value));
    } else {
      type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        interger = std::stoi(rhs.toString()) - _value;
        return (_create.createOperand(type, std::to_string(interger)));
      }
      if (type == Float || type == Double) {
        real_nbr = std::stod(rhs.toString()) - _value;
        return (_create.createOperand(type, std::to_string(real_nbr)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator*(IOperand const &rhs) const
  {
    eOperandType  type;
    int           interger = 0;
    double        real_nbr = 0;

    if (_type == rhs.getPrecision()) {
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() * _value));
    } else {
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        interger = std::stoi(rhs.toString()) * _value;
        return (_create.createOperand(type, std::to_string(interger)));
      }
      if (type == Float || type == Double) {
        real_nbr = std::stod(rhs.toString()) * _value;
        return (_create.createOperand(type, std::to_string(real_nbr)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator/(IOperand const &rhs) const
  {
    eOperandType  type;
    int           interger = 0;
    double        real_nbr = 0;

    if (_type == rhs.getPrecision()) {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() / _value));
    } else {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        interger = std::stoi(rhs.toString()) / _value;
        return (_create.createOperand(type, std::to_string(interger)));
      }
      if (type == Float || type == Double) {
        real_nbr = std::stod(rhs.toString()) / _value;
        return (_create.createOperand(type, std::to_string(real_nbr)));
      }
    }
    return (NULL);
  }

  IOperand const	* operator%(IOperand const &rhs) const
  {
    eOperandType  type;
    int           interger = 0;
    //double        real_nbr = 0;
    const Operand<T> *getV = NULL;

    if (_type == rhs.getPrecision()) {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      getV = static_cast<const Operand<T>*>(&rhs);
      return (new Operand<T>(_type, static_cast<long int>(getV->getValue()) % static_cast<long int>(_value)));
    } else {
      if (_value == 0 || !(_value))
        throw Exception::FloatingPointError();
      if (_type > getPrecision())
        type = _type;
      else
        type = rhs.getType();
      if (type == Int8 || type == Int16 || type == Int32) {
        interger = static_cast<long int>(std::stoi(rhs.toString())) % static_cast<long int>(_value);
        return (_create.createOperand(type, std::to_string(interger)));
      }
      if (type == Float || type == Double) {
        throw Exception::ModFloatingPoint();
      }
    }
    return (NULL);
  }

private:
  T                   _value;
  const eOperandType  _type;
  AbstractFactory     _create;
};

#endif
