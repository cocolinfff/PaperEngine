#include"kernel.h"
int sig = 2;
int button_1_sig = 0;
void callofButton_1();


int main() {
	IMAGE img;
	loadimage(&img, "D:\\PR\\Çò×´ÉÁµç\\2.png",200,100);
	window test(400, 600); 

	picture picture_1(200, 200, img, []() {});
	button button_1(20, 80, 50, 50, "click", callofButton_1);
	text text_1(150, 150, "text_1");
	test.addScript(&picture_1);
	test.addScript(&button_1);
	test.addScript(&text_1);
	
	test.display();
	


	while (sig) {
		if (button_1_sig == 1) { button_1.changePos(0, 0, 50, 50); button_1_sig = 0; }
		test.winMain();
	}
}

void callofButton_1() {
	button_1_sig = 1;
	sig--;
}