#include <cmath>
#include <iostream>
#include <utility>
#include <iomanip>
#include <limits>
#include <string>

#include "GroceryItem.hpp"

namespace // un-named namespace
{
	constexpr auto EPSILON= 1.0E-4;
}

GroceryItem::GroceryItem(const std::string & productName,
						 const std::string & brandName 	,
						 const std::string & upcCode  	,
					     double              price    	)
		: _upcCode		(upcCode),
		  _brandName	(brandName),
		  _productName	(productName),
		  _price		(price)
{}


// Value Returning Functions // 

std::string GroceryItem::upcCode()const{
	return _upcCode;
}

std::string GroceryItem::brandName()const{
	return _brandName;
}

std::string GroceryItem::productName()const{
	return _productName;
}

double GroceryItem::price()const{
	return _price;
}

// Value Setting Functions //

void GroceryItem::upcCode(const std::string & upcCode){
	_upcCode=upcCode;
}

void GroceryItem::productName(const std::string & productName){
	_productName=productName;
}

void GroceryItem::brandName(const std::string & brandName){
	_brandName=brandName;
}

void GroceryItem::price(double price){
	_price=price;
}
 
// Stream Overloading //
std::ostream& operator<<(std::ostream& osObject, const GroceryItem& item)
{
	osObject << "UPC:     " << std::quoted( item.upcCode() ) 	 << ", "
			 << "Brand:   " << std::quoted( item.brandName() ) 	 << ", "
			 << "Product: " << std::quoted( item.productName() ) << ", "
			 << "Price:  $" << item.price()	   					 << '\n';
	return osObject;
}

std::istream& operator>>(std::istream& isObject, GroceryItem& item)
{
	GroceryItem workingItem;
	
	isObject >> std::quoted(workingItem._upcCode    )
			 >> std::quoted(workingItem._brandName  )
			 >> std::quoted(workingItem._productName)
			 >> 			workingItem._price;
			 
	isObject.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
	
	item = std::move(workingItem);
	
	return isObject;
}

// logical Operator Overloading //
bool operator ==( const GroceryItem & lhs, const GroceryItem & rhs )
{
	if constexpr( (true) )
	{
		return 	lhs._upcCode 	 == rhs._upcCode 	 &&
				lhs._productName == rhs._productName &&
				lhs._brandName 	 == rhs._brandName 	 &&
				std::abs(lhs._price - rhs._price) < EPSILON;
	}
	else
	{
		return !(lhs < rhs) && (rhs < lhs );
	}
}

bool operator< ( const GroceryItem& lhs, const GroceryItem& rhs)
{
	if( auto result = lhs._upcCode    .compare(rhs._upcCode		); result !=0 ) return result < 0;
	if( auto result = lhs._productName.compare(rhs._productName	); result !=0 ) return result < 0;
	if( auto result = lhs._brandName  .compare(rhs._brandName	); result !=0 ) return result < 0;
	if (std::abs(lhs._price - rhs._price) >= EPSILON ) 							return lhs._price < rhs._price;
	
	return false;
}

bool operator!=( const GroceryItem& lhs, const GroceryItem& rhs) { return !( lhs == rhs );}
bool operator<=( const GroceryItem& lhs, const GroceryItem& rhs) { return !( rhs <  lhs );}
bool operator> ( const GroceryItem& lhs, const GroceryItem& rhs) { return  ( rhs <  lhs );}
bool operator>=( const GroceryItem& lhs, const GroceryItem& rhs) { return !( lhs <  rhs );}
