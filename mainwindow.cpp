#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->centralWidget);
    ui->centralWidget->layout();
    connectSignals();
    
    db = QSqlDatabase::addDatabase("QIBASE");
    ui->pbRead->setEnabled(false);
    tablemodel = NULL;
    fieldsmodel = NULL;
    
    InitFieldTypeMapping();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tablemodel;
}

void MainWindow::ConnectToDB()
{
    QString charset, conncharset;
    charset = ui->charsetComboBox->itemText(ui->charsetComboBox->currentIndex());
    conncharset = "ISC_DPB_LC_CTYPE="+charset;
    if(QSqlDatabase::isDriverAvailable("QIBASE"))
        qDebug("IBASE YES");
    
    db.setHostName(ui->hostLineEdit->text());
    db.setDatabaseName(m_sDBFile);
    db.setUserName(ui->userLineEdit->text());
    db.setPassword(ui->passwordLineEdit->text());
    db.setConnectOptions(conncharset);
    
    if(!db.open())
        QMessageBox::critical(this, "No Connection", db.lastError().text() );
    else
    {
        ui->pbChoosefile->setEnabled(false);
        ui->pbConnect->setEnabled(false);
        ui->pbRead->setEnabled(true);
        
        if(tablemodel == NULL)
        {
            tablemodel = new QSqlTableModel();
            fieldsmodel = new QSqlTableModel();
        }
    }
}
    
void MainWindow::ReadTables()
{
    //db.transaction();
    tablemodel->setQuery("SELECT RDB$RELATION_NAME FROM RDB$RELATIONS WHERE RDB$RELATION_NAME NOT STARTS WITH 'RDB$' AND RDB$RELATION_NAME NOT STARTS WITH 'MON$'");
    tablemodel->setHeaderData(0, Qt::Horizontal, "Tablename");
    tablemodel->query();
    //db.rollback();
    ui->tvTables->setModel(tablemodel);
    ui->tvTables->show();
}

void MainWindow::ReadFields(const QModelIndex & index)
{
    //db.transaction();
    tablename = tablemodel->record(index.row()).value(index.column()).toString();
    
    fieldsmodel->setQuery("select r.rdb$field_name, r.rdb$relation_name, "
                          "t.rdb$type_name, "
                          "f.rdb$field_length, "
                           "r.rdb$null_flag, "
                          "f.rdb$validation_source, "
                      "f.rdb$field_type, "
                      "f.rdb$field_sub_type "
                      "from rdb$relation_fields r, rdb$types t, rdb$fields f "
                      "where "
                          "r.rdb$relation_name not starts with 'RDB$' "
                          "and r.rdb$relation_name not starts with 'MON$' "
                          "and r.rdb$relation_name = '"+tablename+"' "
                          "and f.rdb$field_name=r.rdb$field_source "
                          "and t.rdb$field_name='RDB$FIELD_TYPE' " 
                          "and f.rdb$field_type=t.rdb$type");
    
    fieldsmodel->setHeaderData(0, Qt::Horizontal, "fieldname");
    fieldsmodel->query();
    //db.rollback();
    ui->tvFields->setModel(fieldsmodel);
    ui->tvFields->show();
}

void MainWindow::ChooseFile()
{
    m_sDBFile = QFileDialog::getOpenFileName();
    ui->filenameLineEdit->setText(m_sDBFile);
    ui->filenameLineEdit->setToolTip(m_sDBFile);
}

void MainWindow::connectSignals()
{
    connect(ui->pbConnect, SIGNAL(clicked()), this, SLOT(ConnectToDB()));
    connect(ui->pbChoosefile, SIGNAL(clicked()), this, SLOT(ChooseFile()));
    connect(ui->pbRead, SIGNAL(clicked()), this, SLOT(ReadTables()));
    connect(ui->tvTables, SIGNAL(clicked(QModelIndex)), SLOT(ReadFields(QModelIndex)));
    connect(ui->pbGenerateHeader, SIGNAL(clicked()), this, SLOT(GenerateHeader()));
    connect(ui->pbGenerateSource, SIGNAL(clicked()), this, SLOT(GenerateSource()));
    
}

void MainWindow::InitFieldTypeMapping()
{
    fieldtypemappingqt["SHORT"] = "unsigned integer";
    fieldtypemappingqt["LONG"] = "unsigned long";
    fieldtypemappingqt["DOUBLE"] = "double";
    fieldtypemappingqt["VARYING"] = "QString";
    fieldtypemappingqt["BLOB"] = "QString";
    fieldtypemappingqt["INT64"] = "quint64";
    
    fieldtypedefaultvalueqt["SHORT"] = "0";
    fieldtypedefaultvalueqt["LONG"] = "0";
    fieldtypedefaultvalueqt["DOUBLE"] = "0.0";
    fieldtypedefaultvalueqt["VARYING"] = "\"\"";
    fieldtypedefaultvalueqt["BLOB"] = "\"\"";
    fieldtypedefaultvalueqt["INT64"] = "0";
    
    fieldtypemappingwx["SHORT"] = "unsigned integer";
    fieldtypemappingwx["LONG"] = "unsigned long";
    fieldtypemappingwx["DOUBLE"] = "double";
    fieldtypemappingwx["VARYING"] = "wxString";
    fieldtypemappingwx["BLOB"] = "wxString";
    fieldtypemappingwx["INT64"] = "quint64";
    
    fieldtypedefaultvaluewx["SHORT"] = "0";
    fieldtypedefaultvaluewx["LONG"] = "0";
    fieldtypedefaultvaluewx["DOUBLE"] = "0.0";
    fieldtypedefaultvaluewx["VARYING"] = "_T(\"\")";
    fieldtypedefaultvaluewx["BLOB"] = "_T(\"\")";
    fieldtypedefaultvaluewx["INT64"] = "0";
}

void MainWindow::GenerateHeader()
{
    QString filecont;
    int i = 0;
    
    QFile rcheader;
    if(ui->cbQObject->isChecked())
        rcheader.setFileName(":/templates/template.hrcqt");
    if(ui->cbwxObject->isChecked())
        rcheader.setFileName(":/templates/template.hrcwx");
    rcheader.open(QIODevice::ReadOnly);
    
    if(rcheader.isOpen())
    {
        m_sClassname = tablename;
        filecont = rcheader.readAll();
        m_sClassname = m_sClassname.toLower();
        m_sClassname[m_sClassname.indexOf("_")+1] = m_sClassname[m_sClassname.indexOf("_")+1].toUpper();
        m_sClassname.replace("_","");
        m_sClassname[0] = m_sClassname[0].toUpper();
        m_sClassname = m_sClassname.trimmed();
        filecont.replace("%CLASSNAME%", m_sClassname);
        
        m_sHeader = filecont;
        
        GenerateMembers();
        GenerateHeaderGetter();
        GenerateHeaderSetter();
        ui->edtGentext->setText(m_sHeader);
    }
    
}

void MainWindow::GenerateSource()
{
    QString filecont;
    int i = 0;
    
    QFile rcheader;
    if(ui->cbQObject->isChecked())
        rcheader.setFileName(":/templates/template.srcqt");
    if(ui->cbwxObject->isChecked())
        rcheader.setFileName(":/templates/template.srcwx");
    rcheader.open(QIODevice::ReadOnly);
    
    if(rcheader.isOpen())
    {
        m_sClassname = tablename;
        filecont = rcheader.readAll();
        m_sClassname = m_sClassname.toLower();
        m_sClassname[m_sClassname.indexOf("_")+1] = m_sClassname[m_sClassname.indexOf("_")+1].toUpper();
        m_sClassname.replace("_","");
        m_sClassname[0] = m_sClassname[0].toUpper();
        m_sClassname = m_sClassname.trimmed();
        filecont.replace("%CLASSNAME%", m_sClassname);
        
        m_sSource = filecont;
        
        //GenerateMembers();
        GenerateSourceGetter();
        GenerateSourceSetter();
        GenerateSourceInit();
        ui->edtGentext->setText(m_sSource);
    }
}

void MainWindow::GenerateHeaderGetter()
{
    QString type;
    QString function;
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sHeaderGetters.append("\r\n");
        m_sHeaderGetters.append("\t");
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        
        if(ui->cbQObject->isChecked())
            m_sHeaderGetters.append(fieldtypemappingqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sHeaderGetters.append(fieldtypemappingwx[type]);        
        
        m_sHeaderGetters.append(" ");
        m_sHeaderGetters.append("Get");
        function = fieldsmodel->record(i).value(0).toString().toLower().trimmed();
        function[function.indexOf("_")+1] = function[function.indexOf("_")+1].toUpper();
        function.replace("_","");
        function[0] = function[0].toUpper();
        m_sHeaderGetters.append(function);
        m_sHeaderGetters.append("();");
    }
    
    m_sHeader.replace("%GETTERHEADER%", m_sHeaderGetters);
    qDebug(m_sHeader.toUtf8());
}

void MainWindow::GenerateSourceGetter()
{
    QString type;
    QString function;
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sSourceGetters.append("\r\n");
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        
        if(ui->cbQObject->isChecked())
            m_sSourceGetters.append(fieldtypemappingqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sSourceGetters.append(fieldtypemappingwx[type]); 

        m_sSourceGetters.append(" ");
        m_sSourceGetters.append(m_sClassname);
        m_sSourceGetters.append("::");
        m_sSourceGetters.append("Get");
        function = fieldsmodel->record(i).value(0).toString().toLower().trimmed();
        function[function.indexOf("_")+1] = function[function.indexOf("_")+1].toUpper();
        function.replace("_","");
        function[0] = function[0].toUpper();
        m_sSourceGetters.append(function);
        m_sSourceGetters.append("()");
        m_sSourceGetters.append("\r\n");
        m_sSourceGetters.append("{\r\n");
        //member init
        
        m_sSourceGetters.append("\t");
        m_sSourceGetters.append("return");
        m_sSourceGetters.append(" ");
        m_sSourceGetters.append(fieldsmodel->record(i).value(0).toString().toLower().trimmed());
        m_sSourceGetters.append(";\r\n");
        m_sSourceGetters.append("}\r\n");
    }
    
    m_sSource.replace("%GETTERSOURCE%", m_sSourceGetters);
    qDebug(m_sSource.toUtf8()); 
}

void MainWindow::GenerateHeaderSetter()
{
    QString type;
    QString function;
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sHeaderSetters.append("\r\n");
        m_sHeaderSetters.append("\t");
        m_sHeaderSetters.append("void");
        m_sHeaderSetters.append(" ");
        m_sHeaderSetters.append("Set");
        function = fieldsmodel->record(i).value(0).toString().toLower().trimmed();
        function[function.indexOf("_")+1] = function[function.indexOf("_")+1].toUpper();
        function.replace("_","");
        function[0] = function[0].toUpper();
        m_sHeaderSetters.append(function);
        m_sHeaderSetters.append("(");
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        
        if(ui->cbQObject->isChecked())
            m_sHeaderSetters.append(fieldtypemappingqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sHeaderSetters.append(fieldtypemappingwx[type]);
        
        m_sHeaderSetters.append(" ");
        m_sHeaderSetters.append("val");
        m_sHeaderSetters.append(");");        
    }
    
    m_sHeader.replace("%SETTERHEADER%", m_sHeaderSetters);
    qDebug(m_sSource.toUtf8());
}

void MainWindow::GenerateSourceSetter()
{
    QString type;
    QString function;
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sSourceSetters.append("\r\n");
        m_sSourceSetters.append("void");
        m_sSourceSetters.append(" ");
        m_sSourceSetters.append(m_sClassname);
        m_sSourceSetters.append("::");
        m_sSourceSetters.append("Set");
        
        function = fieldsmodel->record(i).value(0).toString().toLower().trimmed();
        function[function.indexOf("_")+1] = function[function.indexOf("_")+1].toUpper();
        function.replace("_","");
        function[0] = function[0].toUpper();
        
        m_sSourceSetters.append(function);
        m_sSourceSetters.append("(");
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        
        if(ui->cbQObject->isChecked())
            m_sSourceSetters.append(fieldtypemappingqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sSourceSetters.append(fieldtypemappingwx[type]);

        m_sSourceSetters.append(" ");
        m_sSourceSetters.append("val");
        m_sSourceSetters.append(")\r\n");
        m_sSourceSetters.append("{");
        m_sSourceSetters.append("\r\n");
        m_sSourceSetters.append("\t");
        m_sSourceSetters.append(fieldsmodel->record(i).value(0).toString().toLower().trimmed());
        m_sSourceSetters.append(" = ");
        m_sSourceSetters.append("val;\r\n");
        m_sSourceSetters.append("}\r\n");
        
    }
    
    m_sSource.replace("%SETTERSOURCE%", m_sSourceSetters);
    qDebug(m_sSource.toUtf8());
}

void MainWindow::GenerateMembers()
{
    QString type;
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sMember.append("\r\n");
        m_sMember.append("\t");
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        
        if(ui->cbQObject->isChecked())
            m_sMember.append(fieldtypemappingqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sMember.append(fieldtypemappingwx[type]);
        
        m_sMember.append(" ");
        m_sMember.append(fieldsmodel->record(i).value(0).toString().toLower().trimmed());
        m_sMember.append(";");
    }
    
    m_sHeader.replace("%HEADERMEMBERS%", m_sMember);
    qDebug(m_sHeader.toUtf8());
}

void MainWindow::GenerateSourceInit()
{
    QString member, type;
    
    for(int i = 0; i < fieldsmodel->rowCount(); i++)
    {
        m_sSourceInit.append("\t");
        m_sSourceInit.append(fieldsmodel->record(i).value(0).toString().toLower().trimmed());             
        type = fieldsmodel->record(i).value(2).toString();
        type = type.trimmed();
        m_sSourceInit.append(" = ");
        
        if(ui->cbQObject->isChecked())
            m_sSourceInit.append(fieldtypedefaultvalueqt[type]);
        if(ui->cbwxObject->isChecked())
            m_sSourceInit.append(fieldtypedefaultvaluewx[type]);
        
        m_sSourceInit.append(";\r\n");
    }
    
    m_sSource.replace("%INIT%", m_sSourceInit);
    qDebug(m_sSource.toUtf8());
}
