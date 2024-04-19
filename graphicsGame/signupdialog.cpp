#include "SignUpDialog.h"



SignUpDialog::SignUpDialog(QWidget *parent) : QDialog(parent) {
    setupUI();
    connectSignals();
    setupDatabase();
}

void SignUpDialog::setupUI() {


    firstNameLineEdit = new QLineEdit(this);
    lastNameLineEdit = new QLineEdit(this);
    dobDateEdit = new QDateEdit(this);
    dobDateEdit->setCalendarPopup(true);
    genderComboBox = new QComboBox(this);
    genderComboBox->addItems({"Male", "Female", "Other"});
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    submitButton = new QPushButton("Submit😊", this);
    cancelButton = new QPushButton("Cancel😑", this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("First Name:", firstNameLineEdit);
    formLayout->addRow("Last Name:", lastNameLineEdit);
    formLayout->addRow("Date of Birth:", dobDateEdit);
    formLayout->addRow("Gender:", genderComboBox);
    formLayout->addRow("User Name:", usernameLineEdit);
    formLayout->addRow("Password:", passwordLineEdit);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);



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


    setLayout(mainLayout);
}

void SignUpDialog::connectSignals() {
    connect(submitButton, &QPushButton::clicked, this, &SignUpDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &SignUpDialog::reject);
    connect(uploadButton, &QPushButton::clicked, this, &SignUpDialog::onUploadButtonClicked);
    connect(passwordLineEdit, &QLineEdit::textChanged, this, &SignUpDialog::checkPasswordValidity);
    //connect(passwordLineEdit, &QLineEdit::editingFinished, this,&SignUpDialog::checkPasswordValidity);
}
void SignUpDialog::onUploadButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        profilePictureLabel->setPixmap(pixmap.scaled(profilePictureLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
void SignUpDialog::setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("application.db");
    if (!db.open()) {
        qDebug() << "Error: unable to open database";
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT, "
               "firstName TEXT, "
               "lastName TEXT, "
               "dateOfBirth DATE, "
               "gender TEXT)");
}
// And implement the slot to check validity
void SignUpDialog::checkPasswordValidity(const QString &password) {
    // First, create a non-const copy of the password
    QString nonConstPassword = password;

    // Define the regular expression for the password
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");

    // Assume the passwordValidator is correctly set up somewhere in the class
    QRegularExpressionValidator *passwordValidator = new QRegularExpressionValidator(passwordRegex, this);

    passwordLineEdit->setValidator(passwordValidator);

    // Set the position to zero
    int pos = 0;
    // Now use the non-const password copy for validation
    if(passwordValidator->validate(nonConstPassword, pos) != QValidator::Acceptable) {
        // Inform user about the invalid password
        QMessageBox::warning(this, "Invalid Password", "Password must be at least 8 characters long and include uppercase letters, lowercase letters, and numbers.");
        // Update the UI to reflect the invalid state, like changing the color of the line edit
        passwordLineEdit->setStyleSheet("QLineEdit { border: 1px solid red; }");
    } else {
        // If the password is valid, reset any warning styles you might have set
        passwordLineEdit->setStyleSheet("");
    }

    // Clean up the validator to prevent memory leak
    delete passwordValidator;
}
