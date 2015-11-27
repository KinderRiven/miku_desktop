#include "pet.h"

Pet::Pet(QWidget *parent)
	: QMainWindow(parent){

	kSetting::getScreen();
	/*
		透明 窗口异形
	*/
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

	/*
		加载人物
	*/
	stateChange = true;
	stateID  = 0;
	imageID  = 0;
	actionID = 0;

	loadImage();

	/*
		加载动作事件
	*/
	loadAction();

	imageTimer.start(100);
	stateTimer.start(5000);

	connect(&stateTimer, SIGNAL(timeout()), this, SLOT(changeState()));
	connect(&imageTimer, SIGNAL(timeout()), this, SLOT(changeAction()));

}

/*
	重画
*/
void Pet::kShow(bool ok){

	if (ok){

		int posX = kSetting::screenWidth  - image.width();
		int posY = kSetting::screenHeight - image.height();
		move(QPoint(posX, posY));

		int tposX = posX - talk.image.height();
		int tposY = posY - talk.image.width();
		talk.kShow(true, tposX, tposY);
		show();
	}
	else 
		hide();
}

void Pet::paintEvent(QPaintEvent*){
	QPainter painter(this);
	resize(image.width(), image.height());
	painter.drawPixmap(0, 0, image.width(), image.height(), image);
}

/*
	鼠标移动重写
*/
void Pet::mousePressEvent(QMouseEvent* event){

	if (event->button() == Qt::LeftButton){
		preMousePos = cursor().pos();
		update();
	}
	if (event->button() == Qt::RightButton){

	}
}

/*
	鼠标拖动事件
*/
void Pet::mouseMoveEvent(QMouseEvent* event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mpos = cursor().pos();	//鼠标坐标

		/*
		移动的公式：
		设置的位置 = 之前窗口位置 + （当前鼠标位置 - 之前鼠标位置）
		*/
		int posX = pos().x() + mpos.x() - preMousePos.x();
		int posY = pos().y() + mpos.y() - preMousePos.y();
		move(QPoint(posX, posY));

		//更新鼠标坐标值
		preMousePos = mpos;
	}
}
/*
	析构函数
*/
Pet::~Pet(){
		
}

/*
	加载动作
*/
void Pet::loadAction(){
	
	for (int i = 0; i <= 0; i++)
		actionVector[0].push_back(i);

	for (int i = 1; i <= 2; i++)
		actionVector[1].push_back(i);

	for (int i = 11; i <= 15; i++)
		actionVector[2].push_back(i);

	for (int i = 21; i <= 27; i++)
		actionVector[3].push_back(i);

}

void Pet::loadImage(){


	QString path = "image/miku/";
	path += QString::number(imageID, 10);
	image.load(path);
	update();

}

/*
	菜单
*/
void Pet::contextMenuEvent(QContextMenuEvent *event){
	QCursor cur = this->cursor();

	//创建一个属于该窗口的子菜单
	QMenu *menu = new QMenu(this);

	//字体设置
	QFont font;
	font.setFamily(QStringLiteral("華康少女文字W6"));
	font.setPointSize(12);

	//固定状态
	menuAction[1] = new QAction(QIcon("image/Window"), tr("Stand"), this);
	menuAction[1] -> setFont(font);
	connect(menuAction[1], &QAction::triggered, this, &Pet::menuStand);
	menu -> addAction(menuAction[1]);

	//自由模式
	menuAction[2] = new QAction(QIcon("image/Window"), tr("Free"), this);
	menuAction[2] -> setFont(font);
	connect(menuAction[2], &QAction::triggered, this, &Pet::menuFree);
	menu->addAction(menuAction[2]);

	//退出
	menuAction[0] = new QAction(QIcon("image/exit"), tr("Exit"), this);
	menuAction[0] -> setFont(font);
	connect(menuAction[0], &QAction::triggered, this, &Pet::menuExit);
	menu -> addAction(menuAction[0]);


	//菜单弹出位置
	menu->exec(cur.pos());

}

void Pet::menuExit(){
	exit(0);

	stateID = 0;
}

void Pet::menuStand(){

	stateChange = false;

	stateID = 0;
	actionID = 0;

}

void Pet::menuFree(){

	stateChange = true;
}

/*
	计时器 改变动作
*/
void Pet::changeAction(){
	

	actionID ++;

	if (actionID >= actionVector[stateID].size())
		actionID = 0;

	imageID = actionVector[stateID][actionID];
	if (stateID == 0){

	}
	else if (stateID == 1){
		int x = pos().x() - 5;
		if (x >= 0)
			move(x, pos().y());
	}
	else if (stateID == 2){

	}
	else if (stateID == 3){

	}
	loadImage();
}

/*
	计时器 改变动作状态
*/
void Pet::changeState(){

	if (!stateChange)
		return;

	stateID  = rand() % 4;
	actionID = 0;

	if (stateID == 0){

		imageTimer.start(5000);
		imageTimer.start(5000);

	}
	else if (stateID == 1){

		imageTimer.start(100);
		stateTimer.start(5000);

	}
	else if (stateID == 2){

		imageTimer.start(200);
		stateTimer.start(1000);

	}
	else if (stateID == 3){

		imageTimer.start(200);
		stateTimer.start(2000);

	}
}