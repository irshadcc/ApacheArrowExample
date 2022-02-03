#include <iostream>
#include "parquet_example.h"
#include "../parquet/parquet_reader.h" 

void print_parquet(std::string file_path) {

	ParquetReader parquet_reader(file_path);

	std::cout << "Parquet schema : " << std::endl ;
	std::cout << parquet_reader.get_schema_string() << std::endl;
	while( parquet_reader.has_next() ) {

		std::shared_ptr<Row> row = parquet_reader.next_row(); 
		std::cout << *(row.get()) ; 
	}
}
