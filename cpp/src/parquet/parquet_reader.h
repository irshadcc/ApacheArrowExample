#include <arrow/api.h>
#include <parquet/arrow/reader.h>
#include "../api/row.h"

#ifndef PARQUET_READER_H
#define PARQUET_READER_H


// TO-DO : Read parquet file 
class ParquetReader {

	public : 

		ParquetReader(const std::string& file_path);

		std::shared_ptr<Row> next_row(); 

		bool has_next() const; 

		std::string get_schema_string() const ;	

	private : 

		int current_row_idx; 
		int total_rows; 

		std::unique_ptr<parquet::arrow::FileReader> file_reader;
		std::shared_ptr<arrow::Schema> schema;
		std::shared_ptr<arrow::Table> table; 
		std::vector<int> column_indices ;

		void init_file_reader(const std::string& file_path); 

		void init_rows();
};


#endif

