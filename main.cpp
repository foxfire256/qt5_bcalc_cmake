#include "MainWindow.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	// https://doc.qt.io/qt-5/qtwidgets-widgets-windowflags-example.html
	// https://doc.qt.io/qt-5/qt.html#WindowType-enum
	Qt::WindowFlags flags = 0;
	flags = Qt::Window;
	// AND NOT to clear bits, OR to set them
	flags &= ~Qt::WindowSystemMenuHint;
	flags &= ~Qt::WindowMinimizeButtonHint;
	flags &= ~Qt::WindowMaximizeButtonHint;
	w.setWindowFlags(flags);
	w.show();

	return a.exec();
}
