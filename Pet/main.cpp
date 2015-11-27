#include "pet.h"
#include "ktalk.h"
#include "kSetting.h"
#include <QtWidgets/QApplication>

int kSetting::screenWidth;
int kSetting::screenHeight;

int main(int argc, char *argv[]){
	
	QApplication a(argc, argv);
	Pet w;
	w.kShow(true);
	return a.exec();
}
