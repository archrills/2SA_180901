#ifndef __MENU_H__
#define __MENU_H__


#define uchar unsigned char
#define uint  unsigned int

struct MenuItem

{
   unsigned int ID;
   unsigned char *displaystring; 
	 unsigned char *displaystring2; 
   int total;
   int cur;
   void (*doing)();
	 int  photo;

}; 


extern struct  MenuItem *menu_point,*ptemp;
extern struct MenuItem Menu_main[]; 
struct MenuItem *getmenu(uint id);
void parameter_first(void);
void loading(void);
//void topmenu(void);
#endif

