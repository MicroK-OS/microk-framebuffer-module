#include <stdint.h>
#include <stddef.h>

#include <cdefs.h>
#include <mkmi.h>

extern "C" uint32_t VendorID = 0xCAFEBABE;
extern "C" uint32_t ProductID = 0xF3A2C0DE;

#include "fb/print.h"

extern "C" size_t OnInit() {
	MKMI_Printf("Probing for framebuffer.\r\n");

	Framebuffer fbData;
	//Syscall(SYSCALL_FILE_READ, "FB:0", &fbData, sizeof(fbData), 0, 0, 0);
	InitFB(&fbData);

	FB_Printf(" __  __  _                _  __\n"
		  "|  \\/  |(_) __  _ _  ___ | |/ /\n"
		  "| |\\/| || |/ _|| '_|/ _ \\|   < \n"
		  "|_|  |_||_|\\__||_|  \\___/|_|\\_\\\n\n"
		  "Welcome from %x by %x\n", ProductID, VendorID);
	
	return 0;
}

extern "C" size_t OnExit() {
	return 0;
}
