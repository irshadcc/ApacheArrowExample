import numpy as np
import pandas as pd
import pyarrow as pa
import pyarrow.parquet as pq


df = pd.DataFrame(
	{
		'fc_int' : [1,None, 3, None, 5, None],
		'fc_string' : [ None, 'b', None, 'c', None, 'd'],
		'fc_list' : [
			[1,2,3],
			[4,5,6],
			[7,8,9],
			None,
			[10,11,12],
			None
		],
		'fc_struct' : [
			{
				'id' : '123af23e',
				'name' : "abc",
			},
			None,
			{
				'id' : '1232f33e',
				'name' : "asfd",
			},
			None,
			None,
			{
				'id' : '12224a3e',
				'name' : "asfd",
			},
		]
	}
)

table = pa.Table.from_pandas(df)
pq.write_table(table, '../resources/example.parquet')