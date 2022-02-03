function conda_install() {
	# Reference : https://arrow.apache.org/docs/cpp/build_system.html
	conda install arrow-cpp=6.0.* -c conda-forge
	conda install pyarrow=6.0.* -c conda-forge
}

function init_envs() {
	echo "Compiler envs init.."
	lib_dir=/home/irshadcc/anaconda3/envs/arrow/lib
	include_dir=/home/irshadcc/anaconda3/envs/arrow/include

	export LIBRARY_PATH=${lib_dir}
	export LD_LIBRARY_PATH=${lib_dir}
	export CPLUS_INCLUDE_PATH=${include_dir}
}

function debian_install() {
	# Reference : https://arrow.apache.org/docs/cpp/build_system.html

	sudo apt update
	sudo apt install -y -V ca-certificates lsb-release wget
	wget https://apache.jfrog.io/artifactory/arrow/$(lsb_release --id --short | tr 'A-Z' 'a-z')/apache-arrow-apt-source-latest-$(lsb_release --codename --short).deb
	sudo apt install -y -V ./apache-arrow-apt-source-latest-$(lsb_release --codename --short).deb
	sudo apt update
	sudo apt install -y -V libarrow-dev # For C++
	sudo apt install -y -V libarrow-glib-dev # For GLib (C)
	sudo apt install -y -V libarrow-dataset-dev # For Apache Arrow Dataset C++
	sudo apt install -y -V libarrow-flight-dev # For Apache Arrow Flight C++
	sudo apt install -y -V libplasma-dev # For Plasma C++
	sudo apt install -y -V libplasma-glib-dev # For Plasma GLib (C)
	sudo apt install -y -V libgandiva-dev # For Gandiva C++
	sudo apt install -y -V libgandiva-glib-dev # For Gandiva GLib (C)
	sudo apt install -y -V libparquet-dev # For Apache Parquet C++
	sudo apt install -y -V libparquet-glib-dev # For Apache Parquet GLib (C)
}

function build_using_g++() {

	setup 
	rm -rf build
	mkdir -p build
	
	g++ -c "src/example.cc" -o "build/example.o"
	g++ -c "src/examples/array_example.cc" -o "build/array_example.o"
	g++ -c "src/examples/parquet_example.cc" -o "build/parquet_example.o" 
	g++ -c "src/api/row.cc" -o "build/row.o"
	g++ -c "src/parquet/parquet_reader.cc" -o "build/parquet_reader.o"

	g++ -larrow -lparquet build/*.o -o build/example.o

}