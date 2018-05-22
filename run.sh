if [ ! -f libusb-1.0.so.0 ]; then
	ln -s libusb-1.0.so libusb-1.0.so.0
fi
LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./uzbprog
