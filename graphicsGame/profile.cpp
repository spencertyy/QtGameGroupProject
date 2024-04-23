#include "profile.h"
#include "ui_profile.h"

//profile shows up upon successful login or sucessful signup,(user info supplied by user manager after verifying credentials)
profile::profile(UserInfo* userInfo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profile)
{
    qDebug() << "Profile: constructing profile";
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->gameStartBtn, &QPushButton::clicked, this, &profile::onGameStartBtnClicked);

    //setting profile with username, firstname, lastname
    ui->userNameEdit->setText(userInfo->username);
    ui->firstNameEdit->setText(userInfo->firstName);
    ui->lastNameEdit->setText(userInfo->lastName);
    //ui->dobLineEdit->setText(userInfo->dateOfBirth);

    //setting profile data (date of birth)
    QDate userDOB = userInfo->dateOfBirth;
    QString dateString = userDOB.toString("yyyy-MM-dd");  // Convert the QDate to a string in a specific format (e.g., "yyyy-MM-dd");
    ui->dobLineEdit->setText(dateString);

    //settting the profile picture
    QPixmap userPic = userInfo->profilePicture; // Get UserInfo object
    displayProfilePicture(userPic);

    //is users birthday today? Then display birthday pop window!
    if(userDOB.day() == QDate::currentDate().day() && userDOB.month() == QDate::currentDate().month()){
        qDebug() << "it's the users birthday today!";
        displayBirthdayMessage();
    }
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

void profile::displayProfilePicture(const QPixmap& profilePic) {

    // Create a instance of the item
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(profilePic);

    //set position and scale of item
    qreal scaleFactor = qMin(static_cast<qreal>(ui->picView->width()) / profilePic.width(), static_cast<qreal>(ui->picView->height()) / profilePic.height());
    pixmapItem->setPos(0, 0);
    pixmapItem->setScale(scaleFactor);

    //Obtain scene associated with the view
    scene = ui->picView->scene();
    if (!scene) {
        //if no sccene aosicated, create a new one and set it
        scene = new QGraphicsScene(this);
        ui->picView->setScene(scene);
    }
    else{
        scene->clear();
    }

    //add the item to the scene
    scene->addItem(pixmapItem);

    // Optionally, adjust the view to fit the pixmap item
    ui->picView->fitInView(pixmapItem, Qt::KeepAspectRatio);
}

//KT: to do move this logic to the profile class?
void profile::displayBirthdayMessage() {
    birthdayDialog = new QDialog(this);
    birthdayDialog->setWindowTitle("🎉Happy Birthday🎁");

    QLabel *imageLabel = new QLabel(birthdayDialog);
    QPixmap birthdayPic(":/new/prefix1/images/birthdayy.png");  // Ensure the path is correct
    imageLabel->setPixmap(birthdayPic.scaled(400, 400, Qt::KeepAspectRatio));

    QLabel *textLabel = new QLabel("Happy Birthday!", birthdayDialog);
    textLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(birthdayDialog);
    layout->addWidget(imageLabel);
    birthdayDialog->setLayout(layout);
    birthdayDialog->resize(400, 400);
    birthdayDialog->setAttribute(Qt::WA_DeleteOnClose); // Ensure dialog is deleted on close

    birthdayDialog->exec();
}
