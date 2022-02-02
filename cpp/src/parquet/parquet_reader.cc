#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/filesystem/api.h>
#include <arrow/util/macros.h>

#include "parquet_reader.h"


ParquetReader::ParquetReader(const std::string& file_path) {

	init_file_reader(file_path);


}

std::shared_ptr<Row> ParquetReader::next_row() {

	if(!this->has_next()) {
		throw "No further rows exist"; 
	}

	return rows[current_row_idx++];
}


bool ParquetReader::has_next() const {

	return current_row_idx < rows.size() ; 
}

arrow::util::string_view ParquetReader::get_schema_string() const {


}


// Private methods
void ParquetReader::init_file_reader(const std::string& file_path) { 

	std::shared_ptr<arrow::fs::LocalFileSystem> fs = std::make_shared<arrow::fs::LocalFileSystem>() ;

	arrow::MemoryPool* pool = arrow::default_memory_pool();
	std::shared_ptr<arrow::io::RandomAccessFile> inputFile;
	auto result = fs->OpenInputFile(file_path) ;
	if (result.ok()) 
		inputFile = result.ValueOrDie();
	

	auto status = parquet::arrow::OpenFile(inputFile, pool, &reader); 
	if (!status.ok()) 
		throw "Cannot open parquet file"; 
}