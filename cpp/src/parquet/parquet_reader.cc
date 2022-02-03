#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/filesystem/api.h>
#include <arrow/util/macros.h>
#include "parquet_reader.h"


ParquetReader::ParquetReader(const std::string& file_path ) {

	this->current_row_idx = 0 ; 
	init_file_reader(file_path);
	init_rows();
}

std::shared_ptr<Row> ParquetReader::next_row() {

	if(!this->has_next()) {
		throw "No further rows exist"; 
	}

	std::shared_ptr<arrow::Table> table_row = table->Slice(current_row_idx, 1); 
	std::shared_ptr<Row> row = std::make_shared<Row>(column_indices.size());

	std::cout << current_row_idx << " : " ;
	for(int i = 0 ; i < column_indices.size() ; i++){
		std::shared_ptr<arrow::ChunkedArray> chunked_array = table_row->column(i);
		std::cout << "\n Chunked array : " << chunked_array->ToString() ;
		row->set_column_value(i, chunked_array);
	}
	current_row_idx++;
	return row; 
}

bool ParquetReader::has_next() const {

	return current_row_idx < total_rows ; 
}

std::string ParquetReader::get_schema_string() const {

	return this->schema->ToString() ;	
}


// Private methods
void ParquetReader::init_file_reader(const std::string& file_path) { 

	std::shared_ptr<arrow::fs::LocalFileSystem> fs = std::make_shared<arrow::fs::LocalFileSystem>() ;

	arrow::MemoryPool* pool = arrow::default_memory_pool();
	std::shared_ptr<arrow::io::RandomAccessFile> inputFile;
	auto result = fs->OpenInputFile(file_path) ;
	if (result.ok()) 
		inputFile = result.ValueOrDie();
	
	auto status = parquet::arrow::OpenFile(inputFile, pool, &file_reader); 
	if (!status.ok()) 
		throw "Cannot open parquet file : " + file_path; 

	file_reader->GetSchema(&schema); 
	
	this->column_indices.reserve(schema->num_fields());
	for(int i = 0 ; i < schema->num_fields(); i++) {
		column_indices[i] = schema->GetFieldIndex(schema->field(i)->name()) ;
	} 
	std::cout << "Hello : " << column_indices.size()  << std::endl ;
}

void ParquetReader::init_rows() {

	auto status = file_reader->ReadTable(column_indices, &(this->table));
	if (!status.ok())
		throw "Error reading the parquet file in to table " ; 

	this->total_rows = table->num_rows();


	std::cout << "\n---DEBUG--\n" ;
	for(int i = 0 ; i < column_indices.size(); i++) {
		std::shared_ptr<arrow::ChunkedArray> array = table->column(i);
		std::cout << array->ToString(); 
	}
	std::cout << "\n---DEBUG--\n" ;
}