#ifndef KTALK_H
#define KTALK_H

#include <QWidget>
#include "kHeader.h"

namespace Ui {
class kTalk;
}

class kTalk : public QWidget
{
    Q_OBJECT

public:
    explicit kTalk(QWidget *parent = 0);
    ~kTalk();
	void kShow(bool ok, int x, int y);					//show
	QPixmap image;
private:
	void paintEvent(QPaintEvent*);						//ÖØ»­
private:
    Ui::kTalk *ui;
};

#endif // KTALK_H
