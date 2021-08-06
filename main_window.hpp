#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

class QWidget;
class QLabel;
class QPushButton;
class QLineEdit;

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	main_window(QWidget *parent = 0);
	~main_window();

public slots:
	void do_calc();

private:
	QWidget *main_widget;
	QVBoxLayout *main_layout;
	QLabel *weight_label, *velocity_label, *ke_label;
	QLineEdit *weight_edit, *velocity_edit, *ke_edit;
	QPushButton *calc_button;

	void setup_ui();
};

#endif // MAINWINDOW_H
