#include <Qt\qapplication.h>
#include <QtGui\qwidget.h>
#include "MyGlWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MyGlWindow myGlWindow;
	myGlWindow.show();
	return app.exec();
}