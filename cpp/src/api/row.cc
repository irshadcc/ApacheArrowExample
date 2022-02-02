#include <arrow/api.h>
#include "row.h"



std::shared_ptr<arrow::Array> Row::get_column_value(int index) const {  

	return column_values[index];
}

void Row::set_column_value(int index, std::shared_ptr<arrow::Array> column_value) {

	column_values[index] = std::move(column_value) ; 
}

std::ostream operator<<(std::ostream& os, const Row& row) {

	os << "Row : { " ;
	for(int i = 0 ; i < row.column_values.size() ; i++ ) {
		os << row.column_values[i]->ToString() << std::endl ;
	}
}