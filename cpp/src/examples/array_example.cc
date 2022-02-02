#include <iostream>
#include <arrow/api.h>

#include "array_example.h"


void int64_example() {

	arrow::Int64Builder builder;
	builder.Append(1);
	builder.Append(2);
	builder.Append(3);
	builder.AppendNull();
	builder.Append(5);
	builder.Append(6);
	builder.Append(7);
	builder.Append(8);

	auto maybe_array = builder.Finish();
	if (!maybe_array.ok()) {
	// ... do something on array building failure
	}
	std::shared_ptr<arrow::Array> array = *maybe_array;
	std::cout << "Array Length = " << array->length() << std::endl ; 

	std::shared_ptr<arrow::Array> slicedArray = array->Slice(3, 2);
	std::shared_ptr<arrow::Int64Array> int64Array = std::static_pointer_cast<arrow::Int64Array>(slicedArray);

	for(int i = 0 ; i < int64Array->length(); i++) {
		if( int64Array->IsNull(i)) {
			std::cout << " null " ; 
		}
		else {
			int64_t value = int64Array->Value(i);
			std::cout << " " << value << " " ; 
		}

	}
}
