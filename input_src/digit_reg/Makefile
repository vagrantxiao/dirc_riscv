
all: 
	#g++ -I /opt/Xilinx/Vivado/2018.2/include -o Test_host  ./*.cpp  -O3 -DPROFILE
	g++ -I /opt/Xilinx/Vivado/2018.2/include -o Test_host  ./operators/*.cpp ./host/*.cpp   -O3 -DPROFILE
	./Test_host  


run:
	./Test_host  

clean:
	rm -rf ./Test_host
