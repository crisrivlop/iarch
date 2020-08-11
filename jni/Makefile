matrix.o:
	g++ -c math/matrix.cpp


iavector.o:
	g++ -c math/iavector.cpp

NeuralNetwork.o:
	g++ -c ia/NeuralNetwork.cpp 

layer.o: 
	g++ -c ia/layer.cpp 
sigmoid.o: 
	g++ -c ia/sigmoid.cpp 

activation.o: 
	g++ -c ia/activation.cpp 
relu.o:
	g++ -c ia/relu.cpp


vector_test.o:
	g++ -c test/vector_test.cpp 
matrix_test.o:	
	g++ -c test/matrix_test.cpp

main.o: iavector.o matrix.o NeuralNetwork.o layer.o sigmoid.o activation.o relu.o vector_test.o matrix_test.o
	g++ -c main.cpp
	g++ -fopenmp main.o iavector.o matrix.o NeuralNetwork.o layer.o sigmoid.o activation.o relu.o vector_test.o matrix_test.o -o ia-test 


all:
	make clean
	make main.o
	mv *.o build/

clean:
	rm -rf *.o
	rm -rf build/*

compile:
	/opt/android-ndk-r20/ndk-build

run:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/ia_test /data/local/tmp
	adb shell /data/local/tmp/ia_test
