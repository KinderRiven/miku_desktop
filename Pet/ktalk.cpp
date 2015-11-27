#include "ktalk.h"
#include "ui_ktalk.h"

kTalk::kTalk(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kTalk){
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

}

void kTalk::paintEvent(QPaintEvent*){
	QPainter painter(this);
	resize(image.width(), image.height());
	painter.drawPixmap(0, 0, image.width(), image.height(), image);
}

kTalk::~kTalk(){
    delete ui;
}
 
void kTalk::kShow(bool ok, int x, int y){
	
	if (ok){
		image.load("image/talk1");
		move(QPoint(x, y));
		show();
	}
	else{
		hide();
	}
}
