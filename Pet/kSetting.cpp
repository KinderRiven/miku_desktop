#include "kSetting.h"


kSetting::kSetting(){

}


kSetting::~kSetting(){

}

void kSetting::getScreen(){

	QDesktopWidget* desktop = QApplication::desktop();
	QRect qrect = desktop -> screenGeometry();
	kSetting::screenWidth  = qrect.width();
	kSetting::screenHeight = qrect.height();

}