/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 19. Aug 01:09:29 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *dialectLabel;
    QComboBox *dialectComboBox;
    QLabel *charsetLabel;
    QComboBox *charsetComboBox;
    QLabel *filenameLabel;
    QLineEdit *filenameLineEdit;
    QPushButton *pbChoosefile;
    QPushButton *pbConnect;
    QTableView *tvTables;
    QTableView *tvFields;
    QPushButton *pbRead;
    QCheckBox *cbgenSetter;
    QCheckBox *cbGenGetter;
    QCheckBox *cbQObject;
    QPushButton *pbGenerateHeader;
    QPushButton *pbGenerateSource;
    QTextEdit *edtGentext;
    QCheckBox *cbwxObject;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(754, 672);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 181, 152));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        hostLabel = new QLabel(formLayoutWidget);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, hostLabel);

        hostLineEdit = new QLineEdit(formLayoutWidget);
        hostLineEdit->setObjectName(QString::fromUtf8("hostLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, hostLineEdit);

        userLabel = new QLabel(formLayoutWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, userLabel);

        userLineEdit = new QLineEdit(formLayoutWidget);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, userLineEdit);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(formLayoutWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordLineEdit);

        dialectLabel = new QLabel(formLayoutWidget);
        dialectLabel->setObjectName(QString::fromUtf8("dialectLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, dialectLabel);

        dialectComboBox = new QComboBox(formLayoutWidget);
        dialectComboBox->setObjectName(QString::fromUtf8("dialectComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dialectComboBox);

        charsetLabel = new QLabel(formLayoutWidget);
        charsetLabel->setObjectName(QString::fromUtf8("charsetLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, charsetLabel);

        charsetComboBox = new QComboBox(formLayoutWidget);
        charsetComboBox->setObjectName(QString::fromUtf8("charsetComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, charsetComboBox);

        filenameLabel = new QLabel(formLayoutWidget);
        filenameLabel->setObjectName(QString::fromUtf8("filenameLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, filenameLabel);

        filenameLineEdit = new QLineEdit(formLayoutWidget);
        filenameLineEdit->setObjectName(QString::fromUtf8("filenameLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, filenameLineEdit);

        pbChoosefile = new QPushButton(centralWidget);
        pbChoosefile->setObjectName(QString::fromUtf8("pbChoosefile"));
        pbChoosefile->setGeometry(QRect(10, 160, 75, 23));
        pbConnect = new QPushButton(centralWidget);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));
        pbConnect->setGeometry(QRect(10, 190, 75, 23));
        tvTables = new QTableView(centralWidget);
        tvTables->setObjectName(QString::fromUtf8("tvTables"));
        tvTables->setGeometry(QRect(200, 0, 541, 151));
        tvFields = new QTableView(centralWidget);
        tvFields->setObjectName(QString::fromUtf8("tvFields"));
        tvFields->setGeometry(QRect(200, 160, 541, 261));
        pbRead = new QPushButton(centralWidget);
        pbRead->setObjectName(QString::fromUtf8("pbRead"));
        pbRead->setGeometry(QRect(90, 190, 75, 23));
        cbgenSetter = new QCheckBox(centralWidget);
        cbgenSetter->setObjectName(QString::fromUtf8("cbgenSetter"));
        cbgenSetter->setGeometry(QRect(20, 220, 171, 17));
        cbGenGetter = new QCheckBox(centralWidget);
        cbGenGetter->setObjectName(QString::fromUtf8("cbGenGetter"));
        cbGenGetter->setGeometry(QRect(20, 240, 171, 17));
        cbQObject = new QCheckBox(centralWidget);
        cbQObject->setObjectName(QString::fromUtf8("cbQObject"));
        cbQObject->setGeometry(QRect(20, 260, 171, 17));
        pbGenerateHeader = new QPushButton(centralWidget);
        pbGenerateHeader->setObjectName(QString::fromUtf8("pbGenerateHeader"));
        pbGenerateHeader->setGeometry(QRect(200, 430, 101, 23));
        pbGenerateSource = new QPushButton(centralWidget);
        pbGenerateSource->setObjectName(QString::fromUtf8("pbGenerateSource"));
        pbGenerateSource->setGeometry(QRect(310, 430, 101, 23));
        edtGentext = new QTextEdit(centralWidget);
        edtGentext->setObjectName(QString::fromUtf8("edtGentext"));
        edtGentext->setGeometry(QRect(200, 460, 541, 151));
        cbwxObject = new QCheckBox(centralWidget);
        cbwxObject->setObjectName(QString::fromUtf8("cbwxObject"));
        cbwxObject->setGeometry(QRect(20, 280, 171, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 754, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        hostLabel->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        hostLineEdit->setText(QApplication::translate("MainWindow", "localhost", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QApplication::translate("MainWindow", "User", 0, QApplication::UnicodeUTF8));
        userLineEdit->setText(QApplication::translate("MainWindow", "SYSDBA", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        passwordLineEdit->setText(QString());
        dialectLabel->setText(QApplication::translate("MainWindow", "Dialect", 0, QApplication::UnicodeUTF8));
        dialectComboBox->clear();
        dialectComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
        );
        charsetLabel->setText(QApplication::translate("MainWindow", "Charset", 0, QApplication::UnicodeUTF8));
        charsetComboBox->clear();
        charsetComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "UNICODE_FSS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ASCII", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "UTF8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ISO8859_13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1252", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WIN1258", 0, QApplication::UnicodeUTF8)
        );
        filenameLabel->setText(QApplication::translate("MainWindow", "Filename", 0, QApplication::UnicodeUTF8));
        pbChoosefile->setText(QApplication::translate("MainWindow", "Choose file...", 0, QApplication::UnicodeUTF8));
        pbConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        pbRead->setText(QApplication::translate("MainWindow", "Read Tables", 0, QApplication::UnicodeUTF8));
        cbgenSetter->setText(QApplication::translate("MainWindow", "Generate Setter", 0, QApplication::UnicodeUTF8));
        cbGenGetter->setText(QApplication::translate("MainWindow", "Generate Getter", 0, QApplication::UnicodeUTF8));
        cbQObject->setText(QApplication::translate("MainWindow", "QObject for Qt", 0, QApplication::UnicodeUTF8));
        pbGenerateHeader->setText(QApplication::translate("MainWindow", "Generate Header", 0, QApplication::UnicodeUTF8));
        pbGenerateSource->setText(QApplication::translate("MainWindow", "Generate Source", 0, QApplication::UnicodeUTF8));
        cbwxObject->setText(QApplication::translate("MainWindow", "wxObject for wxWidgets", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
