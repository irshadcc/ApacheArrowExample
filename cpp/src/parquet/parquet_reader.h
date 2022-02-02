#include <arrow/api.h>
#include <
#include "api/row.h"

#ifndef PARQUET_READER_H
#define PARQUET_READER_H


// TO-DO : Read parquet file 
class ParquetReader {



	public : 

		ParquetReader(const std::string& file_path); 

		std::shared_ptr<Row> next_row(); 

		bool has_next() const; 

		arrow::util::string_view get_schema_string() const ;

	private : 

		int current_row_idx; 
		std::vector<std::shared_ptr<Row>> rows; 

		void init_file_reader(const std::string& file_path); 
};


#endif

