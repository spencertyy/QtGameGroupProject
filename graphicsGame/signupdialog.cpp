#include "signupdialog.h"
#include "profile.h"



signupdialog::signupdialog(UserManager* userManager, QWidget *parent) : QDialog(parent) {
    this->userManager = userManager;
    setupUI();
    connectSignals();
}

void signupdialog::setupUI() {

    firstNameLineEdit = new QLineEdit(this);
    lastNameLineEdit = new QLineEdit(this);
    dobDateEdit = new QDateEdit(this);
    dobDateEdit->setCalendarPopup(true);
    dobDateEdit->setMinimumDate(QDate(1900, 1, 1));
    dobDateEdit->setMaximumDate(QDate::currentDate());
    dobDateEdit->setDisplayFormat("MM/dd/yyyy");
    genderComboBox = new QComboBox(this);
    genderComboBox->addItems({"Male", "Female", "Other"});
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    submitButton = new QPushButton("Submit😊", this);
    cancelButton = new QPushButton("Cancel😑", this);

    // Define the regular expression for the password
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
    // Assume the passwordValidator is correctly set up somewhere in the class
    passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    //passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setValidator(passwordValidator);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("First Name:", firstNameLineEdit);
    formLayout->addRow("Last Name:", lastNameLineEdit);
    formLayout->addRow("Date of Birth:", dobDateEdit);

    formLayout->addRow("Gender:", genderComboBox);
    formLayout->addRow("User Name:", usernameLineEdit);
    formLayout->addRow("Password:", passwordLineEdit);

    // Profile Picture
    profilePictureLabel = new QLabel(this);
    profilePictureLabel->setFixedSize(100, 100); // You can adjust the size as needed
    profilePictureLabel->setStyleSheet("QLabel { background-color : gray; }"); // Placeholder style
    profilePictureLabel->setAlignment(Qt::AlignCenter);
    profilePictureLabel->setText("No Image"); // Placeholder text

    uploadButton = new QPushButton("Upload Image", this);


    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(submitButton);
    mainLayout->addWidget(cancelButton);
    formLayout->addRow(profilePictureLabel);
    formLayout->addRow(uploadButton);

    // birthdayImageLabel = new QLabel(this);
    // birthdayImageLabel->setFixedSize(200, 200); // Set as needed
    // birthdayImageLabel->hide(); // Initially hidden
    // mainLayout->addWidget(birthdayImageLabel); // Add to your main layout


    setLayout(mainLayout);
}

void signupdialog::connectSignals() {
    connect(submitButton, &QPushButton::clicked, this, &signupdialog::onSubmitButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &signupdialog::reject);
    connect(uploadButton, &QPushButton::clicked, this, &signupdialog::onUploadButtonClicked);
   // connect(submitButton, &QLineEdit::textChanged, this, &SignUpDialog::checkPasswordValidity);
    //sender, signal, reciever, action

    //handles user request for signup
    connect(this, &signupdialog::signUp, userManager, &UserManager::signUpUser);

    //handles when username is already taken, displays warning
    connect(userManager,&UserManager::userNameTaken, this, &signupdialog::displayUserNameTakenWarning);

    //render user profile for new user
    connect(userManager, &UserManager::userSignedUp, this, &signupdialog::showProfilePage);
}
void signupdialog::onSubmitButtonClicked() {

    //pipes in username field from form
    QString userName = usernameLineEdit->text();
    QString password = passwordLineEdit->text();


    //packages the data, build out user request
    UserRequest* userRequest = new UserRequest();
    userRequest->userName = userName;
    userRequest->password = password;

    qDebug() << "SignUpDialogue: user requesting to be signed up";
    qDebug() << "username: " << userName;
    qDebug() << "password:" << password;

    //signal recieved by user manager where it can be fulfilled or denied
    emit signUp(userRequest);

    checkPasswordValidity();
    //send signal to user manager, user wants to sign up! Is this an okay user name & password?

}
void signupdialog::onUploadButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        profilePictureLabel->setPixmap(pixmap.scaled(profilePictureLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}


// And implement the slot to check validity
void signupdialog::checkPasswordValidity() {
    // //pipes in data from form
    // QString password = passwordLineEdit->text();

    // //packages the data
    // userRequest.password = password;
    // qDebug() << "SignUpDialogue: user password" << password;


    //KT TODO: uncomment when done testing. Maybe move logic to UserHandler?
    // int pos = 0;
    // if(passwordValidator->validate(password, pos) != QValidator::Acceptable) {

    //     QMessageBox::warning(this, "Invalid Password", "Password must contain at least one number, one uppercase letter, one lowercase letter, and be at least 8 characters long, and no punctuation");
    //     passwordLineEdit->setStyleSheet("QLineEdit { border: 1px solid red; }");

    // } else {
    //     showProfilePage();
    // }
    //  //delete passwordValidator;
}




//recieves signal from user manager of new user, render their profile page
void signupdialog::showProfilePage(UserInfo* userInfo) {
    qDebug() <<"show profile page.";
    profile* profilePage = new profile(userInfo);
    profilePage->show();
    this->close();  // 隐藏当前对话框，而不是关闭它
}

//recieves singal from userManage that username is already taken,displays warning on login page
void signupdialog::displayUserNameTakenWarning(){
    qDebug() << "SignupDialogue: display user name taken warning!";

    //create warking display
    QMessageBox::warning(this, "Warning", "username taken");
}
