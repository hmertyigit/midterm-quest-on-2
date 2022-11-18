
#define rccahblenR * ( (unsigned volatile int *)0x40023830)
#define gpiodmask 1<<3
#define gpiodModr *((unsigned volatile int* )0x40020c00)
#define gpiodP14mask 1<<28
#define gpiodP13mask 1<<26
#define gpiodP15mask 1<<30
#define gpiodP12mask 1<<24
#define gpiodOdr  *((unsigned volatile int *)0x40020c14)
#define gpiodp14onmask 1<<14
#define gpiodp14ofmask 0<<14
#define gpiodp13onmask 1<<13
#define gpiodp13ofmask ~(1<<13)
#define gpiodp15onmask 1<<15
#define gpiodp15ofmask 0<<15
#define gpiodp12onmask 1<<12
#define gpiodp12ofmask 0<<12

// 14= kırmızı , 15=mavi ,13 =turuncu ,12=yeşil

//int main() {
//rccahblenR = gpiodmask; // mert =440 mod4=0,kırmızı //
//gpiodModr=gpiodP14mask;
//gpiodModr |=gpiodP13mask;// yigit= 550 mod4=2 ,turuncu //
//gpiodOdr=gpiodp14onmask;
//gpiodOdr=gpiodp14ofmask;
//gpiodOdr|=gpiodp13onmask;
//gpiodOdr&=gpiodp13ofmask;

//return 0;
//}

void init_leds ();
void turn_name_on();
void turn_surname_on();
void turn_name_off();
void turn_surname_off();
void delaytime1();
void delaytime2();
int main()

{
	int i ;
	    init_leds();
	    delaytime1();
	    for(i=0;i<4;i++){
	        turn_name_on();
	        turn_name_off();
	    }
	    for(i=0;i<5;i++){
	            turn_surname_on();
	            turn_surname_off();
	        }

return 0;
	    }
void init_leds(){
	rccahblenR = gpiodmask;
	gpiodModr=gpiodP14mask;  //14 ve 13 pinleri açıldı //
	gpiodModr |=gpiodP13mask;
}
void turn_name_on(){

	gpiodOdr=gpiodp14onmask; //Kırmızı açıldı //
	delaytime1();
}
void turn_name_off(){

	gpiodOdr=gpiodp14ofmask; // Kırmızı kapatıldı //
	delaytime2();
}
void turn_surname_on(){
	gpiodOdr|=gpiodp13onmask; // Turuncu açıldı //
	delaytime1();
}
void turn_surname_off(){
	gpiodOdr&=gpiodp13ofmask; // Turuncu kapatıldı //
	 delaytime2();
}
void delaytime1(){

for(int i=0;i<0x0FFFFFFF;i++){

}
}
void delaytime2(){
for(int i=0;i<0X0FFFFFFF;i++){

}
}
