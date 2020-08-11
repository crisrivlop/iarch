run:
	rm -rf Android.mk Application.mk
	cp parallel-build/* ./
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/ia_test /data/local/tmp
	adb shell /data/local/tmp/ia_test > logs/log.parallel

run-nonparallel:
	rm -rf Android.mk Application.mk
	cp non-parallel-build/* ./
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/ia_test_non_parallel /data/local/tmp
	adb shell /data/local/tmp/ia_test_non_parallel > logs/log.non-parallel

all:
	make run
	make run-nonparallel
	make clean

clean:
	rm -rf Android.mk Application.mk