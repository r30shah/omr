/*******************************************************************************
 * Copyright (c) 2017, 2020 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#ifndef OMR_DATATYPES_INLINES_INCL
#define OMR_DATATYPES_INLINES_INCL

#include "il/OMRDataTypes.hpp"

TR::DataType*
OMR::DataType::self()
   {
   return static_cast<TR::DataType*>(this);
   }

const TR::DataType*
OMR::DataType::self() const
   {
   return static_cast<const TR::DataType*>(this);
   }

OMR::DataType::operator int()
   {
   return self()->getDataType();
   }

bool
OMR::DataType::isInt8()
   {
   return self()->getDataType() == TR::Int8;
   }

bool
OMR::DataType::isInt16()
   {
   return self()->getDataType() == TR::Int16;
   }

bool
OMR::DataType::isInt32()
   {
   return self()->getDataType() == TR::Int32;
   }

bool
OMR::DataType::isInt64()
   {
   return self()->getDataType() == TR::Int64;
   }

bool
OMR::DataType::isIntegral()
   {
   return self()->isInt8() || self()->isInt16() || self()->isInt32() || self()->isInt64();
   }

bool
OMR::DataType::isFloatingPoint()
   {
   return self()->isBFPorHFP();
   }

bool
OMR::DataType::isVector()
   {
   return _type >= TR::NumNonVectorTypes;
   }

bool
OMR::DataType::isBFPorHFP()
   {
   return self()->getDataType() == TR::Float || self()->getDataType() == TR::Double;
   }

bool
OMR::DataType::isDouble()
   {
   return self()->getDataType() == TR::Double;
   }

bool
OMR::DataType::isFloat()
   {
   return self()->getDataType() == TR::Float;
   }

bool
OMR::DataType::isAddress()
   {
   return self()->getDataType() == TR::Address;
   }

bool
OMR::DataType::isAggregate()
   {
   return self()->getDataType() == TR::Aggregate;
   }

TR::DataType&
OMR::DataType::operator=(const TR::DataType& rhs)
   {
   _type = rhs._type;
   return *(static_cast<TR::DataType *>(this));
   }

TR::DataType&
OMR::DataType::operator=(TR::DataTypes rhs)
   {
   _type = rhs;
   return *(static_cast<TR::DataType *>(this));
   }

bool
OMR::DataType::operator==(const TR::DataType& rhs)
   {
   return _type == rhs._type;
   }

bool
OMR::DataType::operator==(TR::DataTypes rhs)
   {
   return _type == rhs;
   }

bool
OMR::DataType::operator!=(const TR::DataType& rhs)
   {
   return _type != rhs._type;
   }

bool
OMR::DataType::operator!=(TR::DataTypes rhs)
   {
   return _type != rhs;
   }

bool
OMR::DataType::operator<=(const TR::DataType& rhs)
   {
   return _type <= rhs._type;
   }

bool
OMR::DataType::operator<=(TR::DataTypes rhs)
   {
   return _type <= rhs;
   }

bool		
OMR::DataType::operator<(const TR::DataType& rhs)		
   {		
   return _type < rhs._type;		
   }		
		
bool		
OMR::DataType::operator<(TR::DataTypes rhs)		
   {		
   return _type < rhs;		
   }		
		
bool		
OMR::DataType::operator>=(const TR::DataType& rhs)		
   {		
   return _type >= rhs._type;		
   }		
		
bool		
OMR::DataType::operator>=(TR::DataTypes rhs)		
   {		
   return _type >= rhs;		
   }		
		
bool		
OMR::DataType::operator>(const TR::DataType& rhs)		
   {		
   return _type > rhs._type;		
   }		
		
bool		
OMR::DataType::operator>(TR::DataTypes rhs)		
   {		
   return _type > rhs;		
   }		

TR::DataTypes
OMR::DataType::createVectorType(TR::DataTypes elementType, TR::VectorLength length)
   {
   //TR_ASSERT_FATAL(elementType > TR::NoType  && elementType <= TR::NumVectorElementTypes, "Invalid vector element type\n");
   //TR_ASSERT_FATAL(length > TR::NoVectorLength  && length <= TR::NumVectorLengths, "Invalid vector length\n");
   
   TR::DataTypes type = (TR::DataTypes)(TR::NumNonVectorTypes + (length-1) * TR::NumVectorElementTypes + elementType - 1);
   
   return type; 
   }

TR::DataType
OMR::DataType::getVectorElementType()
   {
   //TR_ASSERT_FATAL(isVector(), "getVectorElementType() is called on non-vector type\n");
   
   return (TR::DataTypes)((_type - TR::NumNonVectorTypes) % TR::NumVectorElementTypes + 1);
   }

TR::VectorLength
OMR::DataType::getVectorLength()
   {
   //TR_ASSERT_FATAL(isVector(), "getVectorLength() is called on non-vector type\n");
   
   return (TR::VectorLength)((_type - TR::NumNonVectorTypes) / TR::NumVectorElementTypes + 1);
   }

#endif // OMR_DATATYPES_INLINES_INCL
