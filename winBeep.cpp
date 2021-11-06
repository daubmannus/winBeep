#include <iostream>
#include <windows.h> // WinApi header

// https://docs.microsoft.com/en-us/windows/win32/api/utilapiset/nf-utilapiset-beep?redirectedfrom=MSDN

int main(int argc, char** argv) {
	
	if ( argc != 3 ) {
		std::cerr << "two arguments required:" << std::endl;
		std::cerr << "first is frequency in hertz (37 through 32767)" << std::endl;
		std::cerr << "second is duration in milliseconds" << std::endl;
		return 1;
	}
	
	int freq = atoi(argv[1]);
	int dur  = atoi(argv[2]);
	
	if ( freq < 37 || freq > 32767 ) {
		std::cerr << "frequency is out of range (should be 37 through 32767)" << std::endl;
		return 2;
	}
	
	if ( dur <= 0 ) {
		std::cerr << "duration should be greater than zero" << std::endl;
		return 3;
	}
	
	int success = Beep(freq,dur);
	
	if ( ! success ) {
		std::cerr << "Beep function returned error" << std::endl;
		return 4;
	}
	
	return 0;
}
