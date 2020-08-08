matrix.o:
	g++ -c math/matrix.cpp


iavector.o:
	g++ -c math/iavector.cpp

main.o: iavector.o matrix.o
	g++ -c main.cpp
	g++ main.o iavector.o matrix.o -o ia-test


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
	adb push ia /data/local/tmp
	adb shell /data/local/tmp/ia
