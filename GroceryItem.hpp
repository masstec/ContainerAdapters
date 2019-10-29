#pragma once

#include <string>
#include <iostream>


class GroceryItem{
		friend std::ostream& operator<<(std::ostream& osObject, const GroceryItem& item);
		friend std::istream& operator>>(std::istream& isObject,       GroceryItem& item);
		
		friend bool operator == (const GroceryItem& lhs, const GroceryItem & rhs);
		friend bool operator <  (const GroceryItem& lhs, const GroceryItem & rhs);
		
	public:
		// constructors 
		GroceryItem() = default; // default
						// upc, brandName, productName, price //
		GroceryItem(const std::string & productName   ,
					const std::string & brandName = {},
					const std::string & upcCode   = {},
					double              price     =0.0); // uber|all-around constructor
		
		// Queries (getters)
		std::string upcCode()	 const;
		std::string brandName()	 const;
		std::string productName()const;
		double 		price()		 const;
		// mutators(setters)
		
		void upcCode	(const std::string & upcCode);
		void brandName	(const std::string & brandName);
		void productName(const std::string & productName);
		void price		(double 	   		 price);

	private:
		std::string     _upcCode;
		std::string   _brandName;
		std::string _productName;
		double        _price=0.0;
};

// Logical Operators
bool operator==(const GroceryItem& lhs, const GroceryItem& rhs);
bool operator!=(const GroceryItem& lhs, const GroceryItem& rhs);
bool operator< (const GroceryItem& lhs, const GroceryItem& rhs);
bool operator<=(const GroceryItem& lhs, const GroceryItem& rhs);
bool operator> (const GroceryItem& lhs, const GroceryItem& rhs);
bool operator>=(const GroceryItem& lhs, const GroceryItem& rhs);