package com.example.demos;

import static org.apache.parquet.schema.Type.Repetition.OPTIONAL;
import static org.apache.parquet.schema.Type.Repetition.REQUIRED;

import org.apache.parquet.schema.LogicalTypeAnnotation;
import org.apache.parquet.schema.MessageType;
import org.apache.parquet.schema.PrimitiveType.PrimitiveTypeName;
import org.apache.parquet.schema.Types;

class ParquetWriteDemo {

	MessageType schema;

	public ParquetWriteDemo(String path) {

		this.schema = new MessageType("example_schema",
				Types.primitive(PrimitiveTypeName.INT64, REQUIRED).id(1).named("fc_int"),
				Types.primitive(PrimitiveTypeName.BINARY, REQUIRED)
						.as(LogicalTypeAnnotation.stringType()).id(2).named("fc_string"),
				Types.list(OPTIONAL).element(
						Types.primitive(PrimitiveTypeName.INT64, REQUIRED).id(3)
								.named("fc_list_int"))
						.named("fc_list"));
	}

}
