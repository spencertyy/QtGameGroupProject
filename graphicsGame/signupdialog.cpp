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

    //buttons clicked, trigger these responses

    connect(cancelButton, &QPushButton::clicked, this, &signupdialog::reject);
    connect(uploadButton, &QPushButton::clicked, this, &signupdialog::onUploadButtonClicked);


   // connect(submitButton, &QLineEdit::textChanged, this, &SignUpDialog::checkPasswordValidity);
    //sender, signal, reciever, action

    //handles user request for signup
    //when the submit button is clicked, it triggers the on submit button handler, this handler emits user signed up signal to the user manager who responds with user sign up handler
    connect(submitButton, &QPushButton::clicked, this, &signupdialog::onSubmitButtonClicked); //submit button click triggers, submit button handler, this handler emits signal to user manager requesting user sign up
    connect(this, &signupdialog::signUp, userManager, &UserManager::signUpUser); //this object will emit signUP() signal to userManager who responds by signingUpUser

    //handles when username is already taken, displays warning
    //when user manager emits userNameTaken signal, this should respond by displaying a warning: username taken
    connect(userManager,&UserManager::userNameTaken, this, &signupdialog::displayUserNameTakenWarning);

    //user manager sends userPasswordNotStrong enough signal to this (sign up dialogue) handler who then displays a warning message that purposed password not strong enoug
    connect(userManager, &UserManager::userPasswordNotStrongEnough, this, &signupdialog::displayUserNameNotStrongEnough);

    //render user profile for new user
    connect(userManager, &UserManager::userSignedUp, this, &signupdialog::showProfilePage);
}
void signupdialog::onSubmitButtonClicked() {

    //pipes in username field from form
    QString userName = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QString firstName = firstNameLineEdit->text();
    QString lastName = lastNameLineEdit->text();
    QDate dob = dobDateEdit->date();
    // QComboBox *gender = genderComboBox->
    QPixmap profilePicUpload = profilePictureLabel->pixmap().copy();
    QString gender = genderComboBox->currentText();

    //packages the data, build out user request
    UserRequest* userRequest = new UserRequest();
    userRequest->userName = userName;
    userRequest->firstName = firstName;
    userRequest->lastName = lastName;
    userRequest->password = password;
    userRequest->dob = dob;
    userRequest->gender = gender;
    userRequest->pic = profilePicUpload;

    //checkPasswordValidity();
    //signal recieved by user manager where it can be fulfilled or denied

    emit signUp(userRequest);
    //send signal to user manager, user wants to sign up! Is this an okay user name & password?

}
void signupdialog::onUploadButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        profilePictureLabel->setPixmap(pixmap.scaled(profilePictureLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}


//recieves signal from user manager of new user, render their profile page
void signupdialog::showProfilePage(UserInfo* userInfo) {
    qDebug() <<"Signup Dialolgue: show profile page.";
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

void signupdialog::displayUserNameNotStrongEnough(){
    qDebug() << "SignupDialogue: password not strong enough!";

    //create warking display
    QMessageBox::warning(this, "Warning", "must contain at least 8 chars, with at least one capital letter and one number");
}
