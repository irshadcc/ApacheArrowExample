## Dev Environment
### VSCode Remote Container Development 

If you have any issues related to the source folder permissions in container, you can try to solve it by running the following command (caused by SELinux enforcing mode) in host machine.

```bash
sudo setenforce 0
```


### By using anaconda

1. Install conda using [Install Conda in Linux](https://docs.conda.io/projects/conda/en/latest/user-guide/install/linux.html) 
2. Run the following commands
   ```bash
	conda 
	conda create --name arrow-env
	conda activate arrow-env

	conda install arrow-cpp=6.0.* -c conda-forge
	conda install pyarrow=6.0.* -c conda-forge
   ``` 
3. Edit .vscode json files
	- Edit c_cpp_properties.json to for the vs code extension to configure include path
	- Header files for arrow is downloaded into ${arrow-env}/include
	- Shared libraries are downloaded into ${arrow-env}/lib
	- ${arrow-env} is the path of the arrow environment 

## Build

```bash
mkdir release
cd release
cmake ../
make
```