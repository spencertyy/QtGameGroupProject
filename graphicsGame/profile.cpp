#include "profile.h"
#include "ui_profile.h"


profile::profile(UserInfo* userInfo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profile)
{
    qDebug() << "Profile: constructing profile";
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->gameStartBtn, &QPushButton::clicked, this, &profile::onGameStartBtnClicked);

    //setting profile feilds with user info
    ui->firstNameEdit->setText(userInfo->firstName);
    ui->lastNameEdit->setText(userInfo->lastName);

    QDate userDOB = userInfo->dateOfBirth;
    //is it the users birthday today?
    if(userDOB.day() == QDate::currentDate().day() && userDOB.month() == QDate::currentDate().month()){
        qDebug() << "it's the users birthday today!";
        displayBirthdayMessage();
    }

    // Convert the QDate to a string in a specific format (e.g., "yyyy-MM-dd")
    QString dateString = userDOB.toString("yyyy-MM-dd");
    ui->dobLineEdit->setText(dateString);
}

profile::~profile()
{
    delete ui;
}

void profile::onGameStartBtnClicked(){

    game1scene *scene = new game1scene();
    QGraphicsView *view_obj = new QGraphicsView(scene);

    this->hide();
    view_obj->setFixedSize(910,512);

    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    if (!view_obj) {
        view_obj = new QGraphicsView;
    }

    view_obj->show(); // Shows the main game view
    //this->hide();
}


//KT: to do move this logic to the profile class?
void profile::displayBirthdayMessage() {
    birthdayDialog = new QDialog(this);
    birthdayDialog->setWindowTitle("🎉Happy Birthday🎁");

    QLabel *imageLabel = new QLabel(birthdayDialog);
    QPixmap birthdayPic(":/new/prefix1/images/birthdayy.png");  // Ensure the path is correct
    imageLabel->setPixmap(birthdayPic.scaled(400, 400, Qt::KeepAspectRatio));

    QVBoxLayout *layout = new QVBoxLayout(birthdayDialog);
    layout->addWidget(imageLabel);
    birthdayDialog->setLayout(layout);
    birthdayDialog->resize(400, 400);
    birthdayDialog->setAttribute(Qt::WA_DeleteOnClose); // Ensure dialog is deleted on close

    birthdayDialog->exec();
}
