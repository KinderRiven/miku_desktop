#ifndef PET_H
#define PET_H

#include <QtWidgets/QMainWindow>
#include "ui_pet.h"
#include "kHeader.h"
#include "ktalk.h"
#include "kSetting.h"

class Pet : public QMainWindow{
	Q_OBJECT

public:
	void kShow(bool ok);
	void loadImage();									//改变动作的函数
	void loadAction();									//预加载
	Pet(QWidget *parent = 0);
	~Pet();

	void menuExit();									//退出信号槽
	void menuStand();
	void menuFree();
private slots:
	void changeState();									
	void changeAction();
private:	
	void paintEvent(QPaintEvent*);						//重画
	void mousePressEvent(QMouseEvent *event);			//鼠标点击重写
	void mouseMoveEvent(QMouseEvent *event);			//鼠标移动重写
	void contextMenuEvent(QContextMenuEvent *event);	//重写弹出窗口

private:	
	Ui::PetClass ui;
	kTalk   talk;

	QTimer  imageTimer;			//
	QTimer  stateTimer;			//

	QPixmap image;

	QPoint  preMousePos;

	int imageID;					//图片ID
	int stateID;					//状态ID
	int	actionID;					//动作ID
	bool stateChange;				//是否可以改变状态

	QAction *menuAction[32];		//菜单栏指针
	vector<int>actionVector[15];	//动作数组
};

#endif // PET_H
