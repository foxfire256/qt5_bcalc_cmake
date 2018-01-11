#include "MainWindow.hpp"

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

//------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setup_ui();

	connect(calc_button, SIGNAL(clicked()), this, SLOT(do_calc()));
}

//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}

//------------------------------------------------------------------------------
void MainWindow::setup_ui()
{
	// TODO: maybe come up with a better solution than this
	this->setMaximumWidth(130);

	main_widget = new QWidget();
	main_layout = new QVBoxLayout(main_widget);

	weight_label = new QLabel("Weight (grains)", this);
	main_layout->addWidget(weight_label);
	weight_edit = new QLineEdit(this);
	main_layout->addWidget(weight_edit);

	velocity_label = new QLabel("Velocity (fps)", this);
	main_layout->addWidget(velocity_label);
	velocity_edit = new QLineEdit(this);
	main_layout->addWidget(velocity_edit);

	calc_button = new QPushButton("Calculate", this);
	main_layout->addWidget(calc_button);

	ke_label = new QLabel("Kinetic Energy (ft-lbs)", this);
	main_layout->addWidget(ke_label);
	ke_edit = new QLineEdit(this);
	ke_edit->setReadOnly(true);
	main_layout->addWidget(ke_edit);

	this->setCentralWidget(main_widget);
}

//------------------------------------------------------------------------------
void MainWindow::do_calc()
{
	bool conv_ok, all_conv_ok = true;

	double weight = weight_edit->text().toDouble(&conv_ok);
	if(!conv_ok || !all_conv_ok) all_conv_ok = false;

	double velocity = velocity_edit->text().toDouble(&conv_ok);
	if(!conv_ok || !all_conv_ok) all_conv_ok = false;

	double mass = weight / 225218.3408641;
	double ke = 0.5 * mass * velocity * velocity;

	if(all_conv_ok)
		ke_edit->setText(QString("%1").arg(ke));
	else
		ke_edit->setText(QString("Error!"));
}
