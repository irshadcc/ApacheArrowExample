#include <arrow/api.h>
#include <iostream>

#ifndef ROW_H
#define ROW_H


/**
 * @brief The stores the pointer to the each value of the current row in the columnar stored memory 
 * 
 *  -----------------
 *  |    column1    | 
 *  -----------------
 *  |  col_1_value1 |
 *  |  col_2_value2 |  <-- first shared_ptr
 *  -----------------
 *  |    column2    | 
 *  -----------------
 *  |  col_2_value1 |
 *  |  col_2_value2 |  <-- second shared_ptr
 *  ---------------- 
 */
class Row {

	private: 

	std::vector<std::shared_ptr<arrow::Array>> column_values; 

	public:

	void set_column_value(int index, std::shared_ptr<arrow::Array> column_value); 

	std::shared_ptr<arrow::Array> get_column_value(const int index) const;

	friend std::ostream operator<<(std::ostream& os, const Row& row); 
};
#endif
